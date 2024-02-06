#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClear_triggered();

    void on_actionDraw_Triangle_triggered();

    void on_actionGL_FILL_triggered();

    void on_actionGL_LINE_triggered();

    void on_actionDraw_Rect_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
