#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪状态
    setMouseTracking(true);
}

void MyLabel::enterEvent(QEnterEvent *event)
{
    qDebug() << "鼠标进入...";
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开...";

}


void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if( event->button() ==  Qt::LeftButton )
    {
        // Qt中格式化字符串
        QString str = QString( "鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4" ).arg(event->x()).arg(event->y()).arg(event->globalX()).arg(event->globalY());
        qDebug() << str;
    }

    // qDebug() << "鼠标按下...";

}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() ==  Qt::LeftButton )
    {
        QString str = QString( "鼠标释放了 x = %1   y = %2  globalX = %3 globalY = %4" ).arg(event->x()).arg(event->y()).arg(event->globalX()).arg(event->globalY());
        qDebug() << str;
    }
    // qDebug() << "鼠标松开...";
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    // if( event->buttons() &   Qt::LeftButton )
    // {
    QString str = QString( "鼠标移动了 x = %1   y = %2  globalX = %3 globalY = %4" ).arg(event->x()).arg(event->y()).arg(event->globalX()).arg(event->globalY());
    qDebug() << str;
    //}
    //qDebug() << "鼠标移动...";
}

