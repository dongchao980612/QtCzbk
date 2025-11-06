#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);

    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");
    //点击按钮 选中拖拉机选项
    connect(ui->pushButton_17,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    //利用QLabel显示图片
    ui->label->setPixmap(QPixmap(":/Image/butterfly.png"));

    //利用QLabel显示 gif动态图片
    QMovie * movie = new QMovie(":/Image/mario.gif");
    ui->label->setMovie(movie);
    //播放动图
    movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
