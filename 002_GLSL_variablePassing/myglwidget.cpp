#include "myglwidget.h"

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
    glBindVertexArray(VAO); // start record

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glBindVertexArray(0); // end record

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



    // init GLSL
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentShader.frag");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.vert");
    shaderProgram.link();
}

void MyGLWidget::paintGL()
{
    shaderProgram.bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

