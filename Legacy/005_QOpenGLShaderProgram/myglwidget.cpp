#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
{

}

MyGLWidget::~MyGLWidget()
{
    makeCurrent();
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    doneCurrent();
}

void MyGLWidget::setPaintObject(PaintObject paintObject)
{
    m_paintObject = paintObject;
    update();
}

void MyGLWidget::renderLine()
{
    makeCurrent();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    update();
    doneCurrent();
}

void MyGLWidget::renderFill()
{
    makeCurrent();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    update();
    doneCurrent();
}

void MyGLWidget::paintTwoTriangles()
{
    shaderProgram1.bind();
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    shaderProgram2.bind();
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWidget::paintRectangle()
{
    shaderProgram2.bind();
    glBindVertexArray(rectVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);

    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);

    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // rect
    glGenVertexArrays(1, &rectVAO);
    glGenBuffers(1, &rectVBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(rectVAO);
    glBindBuffer(GL_ARRAY_BUFFER, rectVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices), rectVertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    shaderProgram1.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader1.vert");
    shaderProgram1.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader1.frag");
    shaderProgram1.link();
    shaderProgram2.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shader1.vert");
    shaderProgram2.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader2.frag");
    shaderProgram2.link();
}


void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    switch (m_paintObject) {
    case TwoTriangles:
        paintTwoTriangles();
        break;
    case Rectangle:
        paintRectangle();
    default:
        break;
    }


}
