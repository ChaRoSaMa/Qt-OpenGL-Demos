#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionClear_triggered()
{
    ui->centralwidget->setPaintObject(MyGLWidget::None);
}


void MainWindow::on_actionDraw_Triangle_triggered()
{
    ui->centralwidget->setPaintObject(MyGLWidget::TwoTriangles);
}


void MainWindow::on_actionGL_FILL_triggered()
{
    ui->centralwidget->renderFill();
}


void MainWindow::on_actionGL_LINE_triggered()
{
    ui->centralwidget->renderLine();
}


void MainWindow::on_actionDraw_Rect_triggered()
{
    ui->centralwidget->setPaintObject(MyGLWidget::Rectangle);
}

