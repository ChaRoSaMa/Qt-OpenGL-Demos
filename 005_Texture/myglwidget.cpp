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
    glBindVertexArray(VAO);
    // start recording

    // pass datas to shader
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // end recording
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // init shaders
    shaderProgram.addShaderFromSourceFile(
        QOpenGLShader::Fragment,
        ":/fragmentShader.frag");
    shaderProgram.addShaderFromSourceFile(
        QOpenGLShader::Vertex,
        ":/vertexShader.vert"
        );
    shaderProgram.link();

    shaderProgram.bind();
    // set the location of the samplers
    // it sets to zero means the first texture you bind
    // sets to three means the fourth texture you bind
    shaderProgram.setUniformValue("tex0", 0);

    // create texture
    tex0 = new QOpenGLTexture(QImage(":/texture/Texturelabs_Brick_141S.jpg").mirrored());
}

void MyGLWidget::paintGL()
{
    tex0->bind();
    shaderProgram.bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

