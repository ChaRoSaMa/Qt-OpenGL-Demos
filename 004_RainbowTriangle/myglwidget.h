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
private:
    GLuint VAO, VBO = 0;
    QOpenGLShaderProgram shaderProgram;
    GLfloat vertices[18] /* actually includes colors now */ = {
        // positions         // colors
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
    };

};

#endif // MYGLWIDGET_H
