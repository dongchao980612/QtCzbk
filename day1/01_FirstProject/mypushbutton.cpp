#include "mypushbutton.h"

MyPushbutton::MyPushbutton(QPushButton *parent)
    : QPushButton{parent}
{
    qDebug()<<"MyPushbutton的构造函数";
}




MyPushbutton::~MyPushbutton()
{
    qDebug()<<"MyPushbutton的析构函数";
}


