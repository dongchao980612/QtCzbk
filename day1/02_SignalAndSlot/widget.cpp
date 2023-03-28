#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    zt = new Teacher(this);
    st = new Student(this);

    btn = new QPushButton("下课",this);
    this->resize(600,400);

    // 无参
//   connect(zt, &Teacher::hurgry, st, &Student::treat);

    // 调用下课函数
//    this->classIsOver();


    // 有参
//     void  (Teacher::*teacherSignal)(QString) = &Teacher::hungry;
//     void  (Student::*studentSlot)(QString) = &Student::treat;
//     connect(zt, teacherSignal, st, studentSlot);
//     this->classIsOver();



    // 按钮触发
     void  (Teacher::*teacherSignal2)(QString) = &Teacher::hungry;
     void  (Student::*studentSlot2)(QString) = &Student::treat;
     connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);
     connect(zt, teacherSignal2, st, studentSlot2);

    //信号连接信号，不须要调用 classIsOver 函数
//     void(Teacher:: *teacherSignal3)(void) = &Teacher::hungry;
//     void(Student:: *studentSlot3)(void)  = &Student::treat;
//     connect(zt, teacherSignal3, st, studentSlot3);
//     connect(btn,&QPushButton::clicked, zt, teacherSignal3);

    // 断开信号
    // disconnect(zt,teacherSignal3,st,studentSlot3);

    // 无参
//    void(Teacher:: *teacherSignal4)(void) = &Teacher::hungry;
//    void(Student:: *studentSlot4)(void)  = &Student::treat;
//    connect(btn,&QPushButton::clicked, zt, teacherSignal4);
//    connect(zt,SIGNAL(hungry()) , st , SLOT(treat()));


    QPushButton * btn2 = new QPushButton;

//    [=](){
//        btn->setText("aaaa");
//        // btn2->setText("bbb"); //btn2看不到
//    }();

    // mutable关键字 用于修饰值传递的变量，修改的是拷贝，而不是本体

    QPushButton * myBtn = new QPushButton ("myBtn",this);
    QPushButton * myBtn2 = new QPushButton ("myBtn2",this);
    myBtn->move(200,200);
    myBtn2->move(400,200);

    int m = 10;

    connect(myBtn,&QPushButton::clicked,this,[m] ()mutable {
        m = 100 + 10;
        qDebug() << m;
    });

    connect(myBtn2,&QPushButton::clicked,this,[=] ()  {
        qDebug() << m;
    });

    qDebug() << m;


    int ret = []()->int{return 1000;}();
    qDebug() << "ret = " << ret ;

    //利用lambda表达式 实现点击按钮 关闭窗口
    btn3 = new QPushButton("关闭",this) ;
    btn3->move(100,100);

    connect(btn3,&QPushButton::clicked, this,[=](){
        this->close();
        // emit zt->hungry("宫保鸡丁1");
        // btn3->setText("aaaa"); //失败
    });

    //lambda表达式 最常用  [=](){}

}

Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver()
{
    // emit zt->hurgry(); // 无参
    emit zt->hungry("宫保鸡丁");// 有参
}

