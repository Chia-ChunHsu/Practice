#ifndef LABELDOUBLECLICK_H
#define LABELDOUBLECLICK_H

#include <QObject>
#include <QMouseEvent>
#include <QLabel>
#include <QThread>
class LabelDoubleClick:public QLabel
{
    Q_OBJECT

public:
    LabelDoubleClick(QWidget *parent = 0 );
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
signals:
    void sendPoint(QPoint p);
};

#endif // LABELDOUBLECLICK_H
