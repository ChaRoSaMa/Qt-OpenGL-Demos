#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class MyGLWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Widget *ui;
    MyGLWidget *m_glWidget;
};
#endif // WIDGET_H
