#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_click->setText("新设置的文本");
    // ui->actionopen->setIcon(QIcon("C:/Users/dongc/Downloads/open.png"));

    //  使用Qt资源 ": + 前缀名 + 文件名"
    ui->actionopen->setIcon(QIcon(":/image/open.png"));
    ui->actionclose->setIcon(QIcon(":/image/close.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayHello()
{
    qDebug()<<"UI界面中的信号与槽设置";
}
