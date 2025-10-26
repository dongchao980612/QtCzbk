#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>

// 包含头文件 QWidget 窗口类
#include <QWidget>

class myWidget : public QWidget
{
    // Q_OBJECT宏，允许类中使用信号和槽的机制
    // 默认在此不要删除
    Q_OBJECT

public:
    // 构造函数
    myWidget(QWidget *parent = nullptr);

     // 析构函数
    ~myWidget();
};
#endif // MYWIDGET_H
