#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
{

}

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,1);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

//    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader); // 绑定Shader
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // 002 New Code
    /*
     * 去创建EBO的过程和VBO的过程大同小异，因为都是一个Buffer Object。走流程就是：
     * 1.在类内声明一个id    GLuint EBO;
     * 2.生成一个EBO    glGenBuffer(1, &EBO);
     * 3.绑定Buffer    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
     * 4.缓存数据    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
     */
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 值得一提的是因为VAO需要记录我们关于顶点的数据
    // 所以我们之前在前面解绑的VAO必须放到后面解绑
    // 要不然会记录不到EBO导致直接崩溃
    glBindVertexArray(0);

    // 更值得关注的是VAO对于Buffer Object的记录的重视程度是不一样的：
    // VAO不会存储VBO的glBindBuffer函数调用，但是会存储EBO的glBindBuffer函数调用.
    // 这意味着如果你在VAO还在记录Buffer Object状态的时候解绑了EBO那么你使用EBO的时候必须再次绑定才行
}


void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glColor3f(1,1,1);
//    glDrawArrays(GL_TRIANGLES, 0, 6);  - old way to draw rect

    //这里值得注意的是 glDrawElements的最后一个参数
    // 传入0就是让OpenGL使用已经绑定的EBO
    // 当EBO没有绑定时可以直接传入数组的指针，这样OpenGL会使用你传进来的数据
    // （但是如果你绑定了EBO却直接传入数组指针，那可能会导致绘制异常）
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
