#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>

#include <QDebug>
#include <QLabel>
#include <QEvent>

#include <QMouseEvent>
#include <QTimerEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);


    void enterEvent(QEnterEvent * event); // 进入事件
    void leaveEvent(QEvent *event); // 离开事件


    void mousePressEvent(QMouseEvent *event);// 鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event) ;// 鼠标松开事件
    void mouseMoveEvent(QMouseEvent *event) ;// 鼠标移动事件


signals:

};

#endif // MYLABEL_H
