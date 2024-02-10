#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core> // use newer standard
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions_4_5_Core
{
public:
    explicit MyGLWidget(QWidget *parent);

protected:
    virtual void initializeGL();
    virtual void paintGL();

private:
    GLuint VAO, VBO, EBO = 0;
    QOpenGLShaderProgram shaderProgram;
    QOpenGLTexture *tex0;
    QOpenGLTexture *tex1;
    GLfloat vertices[20] = {
        // position(vec3)   // texture cord(vec2)
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, // left top
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // right top
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // left bottom
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f  // right bottom
    };
    GLuint indices[6] = {
        0, 1, 2,
        3, 1, 2
    };
};

#endif // MYGLWIDGET_H
