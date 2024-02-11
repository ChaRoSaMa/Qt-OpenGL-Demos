#include "myglwidget.h"

#include <iostream>
// attention: please ensure that the glm library has
// already been installed in your environment
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <QDateTime>

MyGLWidget::MyGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void MyGLWidget::initializeGL()
{
    // init functions ptr to make them point to the right memory
    initializeOpenGLFunctions();

    // use specific color to clear the screen
    // GL_COLOR_BUFFER_BIT focus on the color, so just use it
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    // start rec

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
        // vertex attrib
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
        // texture coordinate
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // end rec
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // initialize shaders
    shaderProgram.addShaderFromSourceFile(
        QOpenGLShader::Fragment,
        ":/fragmentShader.frag");
    shaderProgram.addShaderFromSourceFile(
        QOpenGLShader::Vertex,
        ":/vertexShader.vert");
    shaderProgram.link();

    // generate texture object
    tex0 = new QOpenGLTexture(QImage(":/texture/Texturelabs_Brick_141S.jpg").mirrored());
    tex1 = new QOpenGLTexture(QImage(":/texture/1").mirrored());

    // specify the sampler location
    shaderProgram.bind();
    shaderProgram.setUniformValue("tex0", 0);
    shaderProgram.setUniformValue("tex1", 1);





}

void MyGLWidget::paintGL()
{
    tex0->bind(0);
    tex1->bind(1);
    shaderProgram.bind();
    glBindVertexArray(VAO);

    // some operation may cause poor performance
    // but to show you all code together, I must do like this
    QDateTime dateTime = QDateTime::currentDateTime();
    qint64 milliseconds = dateTime.toMSecsSinceEpoch();

    glm::mat4 trans(1.0f);
    trans = glm::rotate(trans, float(3.14159 * (sin(milliseconds * 0.005) + 1)), glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));

    GLuint matLocation = shaderProgram.uniformLocation("transMat");
    glUniformMatrix4fv(matLocation, 1, GL_FALSE, glm::value_ptr(trans));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    update();
}

