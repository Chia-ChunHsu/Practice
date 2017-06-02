#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vector2D vector1(1,-1);
    Vector2D vector2(-1,1);
    qDebug()<<"";
    qDebug()<<"Dot Product = "<<vector1*vector2;
    qDebug()<<"Vector Addition = ("<< (vector1+vector2).GetPointX()<<" , "<<(vector1+vector2).GetPointY()<<")";
    qDebug()<<"Vector Minus = ("<< (vector1-vector2).GetPointX()<<" , "<<(vector1-vector2).GetPointY()<<")";

}

MainWindow::~MainWindow()
{
    delete ui;
}
