#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vector2D vector1(1,-1);
    Vector2D vector2(-1,1);
    qDebug()<<"Dot Product = "<<vector1*vector2;
}

MainWindow::~MainWindow()
{
    delete ui;
}
