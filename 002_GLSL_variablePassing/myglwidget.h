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
    GLuint VAO, VBO, EBO  = 0;
    QOpenGLShaderProgram shaderProgram;
    GLfloat vertices[12] = {
        -0.4f,  0.3f, 0.0f, // left top
         0.4f,  0.3f, 0.0f, // right top
        -0.4f, -0.3f, 0.0f, // left bottom
         0.4f, -0.3f, 0.0f  // right bottom
    };
    GLuint indices[6] = {
        0, 1, 2,
        3, 1, 2
    };

};

#endif // MYGLWIDGET_H
