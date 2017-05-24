#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_loadImgButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.bmp *.jpg)"));
    cv::Mat src = cv::imread(fileName.toStdString());
    // Check if image is loaded successfully
    if(!src.data || src.empty())
    {
        //std::cout << "Problem loading image!!!" << std::endl;
        qDebug()<<"Problem loading image!!!";
        return;
    }
    cv::imshow("src", src);

    SimilarPCA SPCA(src);
    cv::Mat result = SPCA.getResult();
    cv::imshow("output", result);

    std::vector<cv::Point> interestPoint;
    SPCA.getInterestPoint(interestPoint);
    for(int i=0;i<interestPoint.size();i++)
        cv::circle(src,interestPoint[i],3,cv::Scalar(0,0,255),-1,8,0);
    cv::imshow("Interest Point",src);
}
