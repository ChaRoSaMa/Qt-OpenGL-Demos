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
    GLuint shaderProgram = 0;
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    const char *vertexShaderSource =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main() {\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
        "}\0";

    const char *fragmentShaderSource =
        "#version 330 core \n"
        "out vec4 FragColor;\n"
        "void main() { \n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n";

private:

protected:
    virtual void initializeGL();
    virtual void paintGL();

};

#endif // MYGLWIDGET_H
