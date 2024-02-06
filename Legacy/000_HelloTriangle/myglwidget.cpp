#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
{

}

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,1);


    // 创建出VAO和VBO的对象并且将他们的ID赋值给VAO,VBO这两个变量
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // 绑定VAO和VBO，因为VAO本身就是对结构的声明所以不用指定类型
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // 为GL_ARRAY_BUFFER创建一个数据缓存区，大小为sizeof(vertices)
    // 用来初始化的数据是vertices，缓存方式是GL_STATIC_DRAW（自己搜）
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 这里告知了显卡如何解析我们给他的数据
    // 0 表示第0个属性, 3表示每三个GL_FLOAT为一组
    // GL_FALSE表示不标准化，3*sizeof(float)表示用这么大的步长
    // (void*)0 表示偏移量为0
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    // 启用第0个属性
    glEnableVertexAttribArray(0);

    // 取消绑定
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(VAO);
    glColor3f(1,1,1);

    // 用Arrays数据进行GL_TRIANGLES的图元方式渲染，从第0个点开始，每3个点组成一个图元
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
