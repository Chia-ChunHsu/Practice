#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->label,SIGNAL(sendPoint(QPoint)),this,SLOT(drawPos(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::intitalSetup()
{
    _cols = 640;
    _rows = 480;
    _background = cv::Mat::zeros(_rows,_cols,CV_8UC3);
    for(int i=0;i<_rows;i++)
    {
        for(int j=0;j<_cols;j++)
        {
            int value = pow(i-_rows/3,2)/800+pow(j-_cols/2,2)/800;
//            if(value>255)
//            {
//                _background.at<cv::Vec3b>(i,j)[0] = 255;
//                _background.at<cv::Vec3b>(i,j)[1] = 255;
//                _background.at<cv::Vec3b>(i,j)[2] = 255;
//            }
//            else
//            {
                _background.at<cv::Vec3b>(i,j)[0] = value;
                _background.at<cv::Vec3b>(i,j)[1] = value;
                _background.at<cv::Vec3b>(i,j)[2] = value;
//            }
        }

    }
    ShowOnLabel(ui->label,_background);
}

void MainWindow::on_loadButton_clicked()
{
    intitalSetup();
}

void MainWindow::drawPos(QPoint p)
{
    if(!timer)
        pos = cv::Point(p.x()*_rows/ui->label->height(),p.y()*_rows/ui->label->height());
    cv::circle(_background,pos,3,cv::Scalar(0,0,255),-1,8,0);
    ShowOnLabel(ui->label,_background);
    disconnect(ui->label,SIGNAL(sendPoint(QPoint)),this,SLOT(drawPos(QPoint)));
}

void MainWindow::updatePoint()
{
    double alpha = 50;
    //int value = pow(i-_rows/2,2)/700+pow(j-_cols/2,2)/700;
    //
    int tempX = pos.x - alpha*(2*pos.x-2*_cols/2)/800;
    int tempY = pos.y - alpha*(2*pos.y-2*_rows/3)/800;
    pos =  cv::Point(tempX,tempY);
    drawPos(QPoint(pos.x,pos.y));
}

void MainWindow::on_startButton_clicked()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePoint()));
    timer->setInterval(1000);
    timer->start();
//    pos.x = 20;
//    pos.y = 20;
}
