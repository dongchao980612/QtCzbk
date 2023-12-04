#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>

#include <QDebug>
#include <QLabel>
#include <QEvent>

#include <QMouseEvent>
#include <QTimerEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    void enterEvent(QEvent *event); // 进入事件
    void leaveEvent(QEvent *event) ;// 离开事件


    void mousePressEvent(QMouseEvent *ev) ; // 鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *ev) ;// 鼠标松开事件
    void mouseMoveEvent(QMouseEvent *ev) ;// 鼠标移动事件

    bool event(QEvent *ev) ;



signals:

};

#endif // MYLABEL_H
