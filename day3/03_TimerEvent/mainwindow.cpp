#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 启动定时器 100毫秒
    timer_id1 = startTimer(1000);
    timer_id2 = startTimer(2000);


    t = new QTimer(this);
    t->start(500);

    connect(t, &QTimer::timeout, this, [ = ]()
    {
        static int num3 = 0;
        qDebug() << "定时器3" << num3;
        ui->label_3->setText(QString::number(num3++));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == timer_id1)
    {
        // 每隔一秒+1
        static int num1 = 1;
        qDebug() << "定时器1" << num1;
        ui->label_1->setText(QString::number(num1++));
    }
    else
    {
        // 每隔两秒+1
        static int num2 = 1;
        qDebug() << "定时器2" << num2;
        ui->label_2->setText(QString::number(num2++));
    }
}

void MainWindow::on_pushButton_clicked()
{
    //  暂停计时器
    t->stop();
}

