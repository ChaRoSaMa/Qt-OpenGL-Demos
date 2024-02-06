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
}

void MyGLWidget::paintGL()
{

}

