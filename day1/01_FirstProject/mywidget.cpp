#include "mywidget.h"

// 初始化列表
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    // 创建一个按钮
    QPushButton* btn1 = new QPushButton();
    // btn1->show(); //show以顶层方式弹出窗口控件

    // 让btn对象 依赖在 myWidget窗口中
    btn1->setParent(this);

    // 显示文本
    btn1->setText("第一个按钮");

    // 创建第二个按钮 按照控件的大小创建窗口
    QPushButton * btn2 = new QPushButton("第二个按钮",this);

    // 移动btn2按钮
    btn2->move(100,100);

    // 按钮可不可以 重新制定大小 可以！
    btn2->resize(150,50);

    resize(600,400);

    // 设置固定窗口大小
    this->setFixedSize(600,400);

    // 设置窗口标题
    this->setWindowTitle("第一个窗口");

    MyPushbutton* btn3=new MyPushbutton;
    btn3->setText("我的自定义的按钮");

    btn3->setParent(this);
    btn3->move(200,200);

    qDebug()<<btn3->pos();

    // 需求  点击我的按钮 关闭窗口
    // 参数1  信号的发送者 参数2  发送的信号（函数的地址） 参数3  信号的接受者 参数4  处理的槽函数
    // connect(btn3, &MyPushButton::clicked, this, &myWidget::close);
    connect(btn3, &QPushButton::clicked, this, &QWidget::close);


}




myWidget::~myWidget()
{
    qDebug()<<"myWidget的析构函数";
}



