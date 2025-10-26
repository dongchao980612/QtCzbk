#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    t = new Teacher(this);  // 老师对象,并先添加到对象树
    s = new Student(this);  // 学生对象,并先添加到对象树

    // 信号和槽函数连接
    // connect(t,&Teacher::hungry,s,&Student::treat);

    //无参
    void (Teacher:: * teacherSingal)(void) = &Teacher::hungry;
    void (Student:: * studentSlot)(void) = &Student::treat;
    connect(t,teacherSingal,s,studentSlot);

    // 有参
    void (Teacher:: * teacherSingal2)(QString) = &Teacher::hungry;
    void (Student:: * studentSlot2)(QString) = &Student::treat;
    connect(t,teacherSingal2,s,studentSlot2);

    // 信号连接信号
    // connect(ui->pushButton,&QPushButton::clicked,t,teacherSingal);

    // Lambda表达式
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        emit t->hungry();
    });

    connect(ui->pushButton2,&QPushButton::clicked,this,[=](){
        emit t->hungry("麻辣烫");
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // emit t->hungry();
    // emit t->hungry("麻辣烫");// 有参
}

