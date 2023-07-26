#include "mainwindow.h"

#include <QApplication>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyGLWidget* glWidget = new MyGLWidget();
    w.setCentralWidget(glWidget);
    return a.exec();
}
