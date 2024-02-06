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

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentShader.frag");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.vert");
    shaderProgram.link();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0 );
    glEnableVertexAttribArray(0);
}

void MyGLWidget::paintGL()
{
    shaderProgram.bind();
    glBindVertexArray(VBO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWidget::resizeGL()
{

}

