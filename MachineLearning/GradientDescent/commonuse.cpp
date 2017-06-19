#include <commonuse.h>
void ShowOnLabel(QLabel *k, cv::Mat m)
{
    if(m.channels() == 3)
    {
        cv::Mat transm;
        cv::cvtColor(m,transm,CV_BGR2RGB);
        QImage img = QImage((const unsigned char*)transm.data,transm.cols,transm.rows,transm.step,QImage::Format_RGB888);
        k->setPixmap(QPixmap::fromImage(img.scaled(k->width(),k->height(),Qt::KeepAspectRatio)));
        k->show();
    }
    else if(m.channels() == 1)
    {
        QVector<QRgb> colorTable;
        for(int i=0;i<256;i++)
        {
            colorTable.push_back(qRgb(i,i,i));
        }
        QImage qtemp = QImage((const unsigned char*)(m.data),m.cols,m.rows,m.step,QImage::Format_Indexed8);
        qtemp.setColorTable(colorTable);
        k->clear();
        k->setPixmap(QPixmap::fromImage(qtemp.scaled(k->width(),k->height(),Qt::KeepAspectRatio)));
        k->show();
    }
}
