#include "myglwidget.h"

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
    glBindVertexArray(VAO); // start Record

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindVertexArray(0); // end Record
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // init shader
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentShader.frag");
    shaderProgram.link();

}

void MyGLWidget::paintGL()
{
    shaderProgram.bind();
    glBindVertexArray(VAO);

    // get green value according to the time
    QDateTime dateTime = QDateTime::currentDateTime();
    qint64 milliseconds = dateTime.toMSecsSinceEpoch();
    GLfloat green = (sin(milliseconds/120.0) + 1) / 2.0;

    // get color location and set its value
    // the location suggest be stored as class member
    // but here to show you the code, I didn't
    GLuint aColorLocation = shaderProgram.uniformLocation("aColor");
    glUniform3f(aColorLocation, 0.9f, green, 0.3f);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
    // update the canvas as quickly as possible
    update();
}

