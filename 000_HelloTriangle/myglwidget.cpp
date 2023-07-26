#include "myglwidget.h"

MyGLWidget::MyGLWidget()
{

}

void MyGLWidget::initializeOpenGLFunctions()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}

void MyGLWidget::paintGL()
{

}
