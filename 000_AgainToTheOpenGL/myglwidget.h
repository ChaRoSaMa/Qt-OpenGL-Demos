#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QOpenGLFunctions_4_5_Core> // use newer standard

class MyGLWidget : public QOpenGLWidget, public QOpenGLFunctions_4_5_Core
{
public:
    explicit MyGLWidget(QWidget *parent);

protected:
    virtual void initializeGL();
    virtual void paintGL();
};

#endif // MYGLWIDGET_H
