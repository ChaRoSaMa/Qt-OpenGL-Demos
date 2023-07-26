#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLExtraFunctions>

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    MyGLWidget(QWidget* parent = nullptr);

    GLuint VAO, VBO = 0;
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

private:

protected:
    virtual void initializeGL();
    virtual void paintGL();

};

#endif // MYGLWIDGET_H
