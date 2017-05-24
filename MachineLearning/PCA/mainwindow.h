#ifndef MAINWINDOW_H
#define MAINWINDOW_H
///
/// Author: Astrid Hsu
/// Brief: A PCA Application Using and Testing
///        Based On OPENCV PCA Tutorial
///        Created a simple using PCA Class.
///        You can only using mypca.h and mypca.cpp to implement the function shown on OPENCV.
///        class similarpca is written for comparison the similarity between two Principle Component.
///        class pcaaxis is written as a container to storage the vector released form PC1 and PC2
/// Date: 20170524
///
#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <QDebug>
#include <similarpca.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loadImgButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
