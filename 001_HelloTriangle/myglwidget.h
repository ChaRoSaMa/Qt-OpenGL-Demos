#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core> // use newer standard
#include <QOpenGLShaderProgram>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions_4_5_Core
{
public:
    explicit MyGLWidget(QWidget *parent);

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL();

private:
    QOpenGLShaderProgram shaderProgram;
    GLuint VBO = 0;
    GLfloat vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };



};

#endif // MYGLWIDGET_H
