#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QMouseEvent>
#include <opencv.hpp>
#include <commonuse.h>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//protected:
//    void mouseDoubleClickEvent(QMouseEvent *event);
private slots:
    void on_loadButton_clicked();

    void drawPos(QPoint p);

    void updatePoint();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    void intitalSetup();
    cv::Mat _background;
    int _cols;
    int _rows;
    cv::Point pos;

    QTimer *timer = 0;
};

#endif // MAINWINDOW_H
