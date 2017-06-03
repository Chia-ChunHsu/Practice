#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Vector2D<int> vector1(1,-1);
    Vector2D<int> vector2(-1,0);
    Vector2D<double> vector3(2.0,3.4);
    qDebug()<<"";
    qDebug()<<vector3.GetPointY();
    qDebug()<<"vector1 "<<vector1.GetLength();
    qDebug()<<"vector2 "<<vector2.GetLength();
    qDebug()<<"Angel between vector1 and vector2 is "<<vector1.GetAngle(vector2);

    qDebug()<<"Dot Product = "<<vector1*vector2;
    qDebug()<<"Vector Addition = ("<< (vector1+vector2).GetPointX()<<" , "<<(vector1+vector2).GetPointY()<<")";
    qDebug()<<"Vector Minus = ("<< (vector1-vector2).GetPointX()<<" , "<<(vector1-vector2).GetPointY()<<")";
}

MainWindow::~MainWindow()
{
    delete ui;
}
