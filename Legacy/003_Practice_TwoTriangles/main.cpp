#include "mainwindow.h"

#include <QApplication>
#include "myglwidget.h"

// requirement: 要求用两个不同的VAO，VBO绘制出两个三角形
// requirement2: use two shaders in the program

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyGLWidget* glWidget = new MyGLWidget();
    w.setCentralWidget(glWidget);
    return a.exec();
}
