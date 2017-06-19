#include "labeldoubleclick.h"

LabelDoubleClick::LabelDoubleClick(QWidget *parent)
{

}

void LabelDoubleClick::mouseDoubleClickEvent(QMouseEvent *event)
{
   sendPoint(event->pos());
}
