#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eigendecomposition.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cv::Mat mat = cv::Mat::zeros(10,10,CV_8UC1);
    for(int i=0;i<mat.rows;i++)
    {
        for(int j=0;j<=mat.cols;j++)
            qDebug()<<mat.at<uchar>(i,j);
    }
//    int a = 10;
//    assert(a==5);

//    int row = 2;
//    int col = 3;
//    double** array = new double* [row];
//    for(int i=0;i<row;i++)
//        array[i] = new double[col];
//    for(int i=0;i<row;i++)
//        for(int j=0;j<col;j++)
//            array[i][j] = i*row+j;
//    EigenDecomposition eigen(array,col,row);
}
