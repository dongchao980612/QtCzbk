#include "mypushbutton.h"

MyPushButton::MyPushButton(QPushButton *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用";
}


MyPushButton::~MyPushButton()
{
    qDebug() << "我的按钮类析构";
}
