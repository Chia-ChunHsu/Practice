#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eigendecomposition.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int row = 2;
    int col = 2;
    double** array = new double* [row];
    for(int i=0;i<row;i++)
        array[i] = new double[col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            array[i][j] = i*row+j;
    EigenDecomposition eigen(array,col,row);
}

MainWindow::~MainWindow()
{
    delete ui;
}
