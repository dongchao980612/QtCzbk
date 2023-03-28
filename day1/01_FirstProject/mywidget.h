#ifndef MYWIDGET_H
#define MYWIDGET_H

//包含头文件 QWidget 窗口类
#include <QWidget>
#include <QPushButton> //按钮控件的头文件
#include <QDebug>

#include "mypushbutton.h"

class myWidget : public QWidget
{
    // Q_OBJECT宏，允许类中使用信号和槽的机制
    Q_OBJECT

public:
    //构造函数
    myWidget(QWidget *parent = nullptr);

    //析构函数
    ~myWidget();
};
#endif // MYWIDGET_H
