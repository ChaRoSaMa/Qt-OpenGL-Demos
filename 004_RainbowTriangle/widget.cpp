#include "widget.h"
#include "./ui_widget.h"

#include "myglwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_glWidget = new MyGLWidget(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    m_glWidget->resize(this->size());
}

