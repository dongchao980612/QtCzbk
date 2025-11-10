#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QStackedWidget
    this->ui->stackedWidget->setCurrentIndex(0);

    //QComboBox 下拉框
    ui->comboBox->addItem("A");
    ui->comboBox->addItem("B");
    ui->comboBox->addItem("C");

    // spinBox
    ui->spinBox->setRange(0, 99);  // 设置范围
    ui->spinBox->setSingleStep(2); //  设置每一步改变的步数
    ui->spinBox->setValue(20); // 设置值
    int  init_value = ui->spinBox->value(); // 获取值
    qDebug() << "初始值是：" << init_value;



    // QTimeEdit
    qDebug() << "****************时间日期**********************";
    qDebug() << "qDebug() << ui->timeEdit->dateTime()";
    qDebug() << ui->timeEdit->dateTime().date();
    qDebug() << ui->timeEdit->dateTime().date().year();
    qDebug() << ui->timeEdit->dateTime().date().month();
    qDebug() << ui->timeEdit->dateTime().date().day();

    qDebug() << ui->timeEdit->dateTime().time();
    qDebug() << ui->timeEdit->dateTime().time().hour();
    qDebug() << ui->timeEdit->dateTime().time().minute();
    qDebug() << ui->timeEdit->dateTime().time().second();

    qDebug() << "qDebug() << ui->timeEdit->date()";
    qDebug() << ui->timeEdit->date();
    qDebug() << ui->timeEdit->date().year();
    qDebug() << ui->timeEdit->date().month();
    qDebug() << ui->timeEdit->date().day();

    qDebug() << "qDebug() << ui->timeEdit->time()";
    qDebug() << ui->timeEdit->time();
    qDebug() << ui->timeEdit->time().hour();
    qDebug() << ui->timeEdit->time().minute();
    qDebug() << ui->timeEdit->time().second();

    qDebug() << "****************时间日期**********************";


    // QDial
    ui->dial->setRange(0, 100);



    // QSlider
    ui->horizontalSlider->setRange(0, 100);

    ui->horizontalSlider->setSliderPosition(50);

    // QLabel
    ui->label->setPixmap(QPixmap(":/image/close.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_18_clicked()
{
    qDebug() << "p1";
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_19_clicked()
{
    qDebug() << "p2";
    ui->comboBox->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_20_clicked()
{
    qDebug() << "p3";
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_17_clicked()
{
    qDebug() << "change to c";
    ui->comboBox->setCurrentIndex(2);
    ui->comboBox->setCurrentText("C");
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug() << "当前值  int arg1 = " << arg1;
}


void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    qDebug() << "当前值  QString arg1 = " << arg1;
}



void MainWindow::on_dial_valueChanged(int value)
{
    qDebug() << "on dial valueChanged   = " << value;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << "on_horizontalSlider_valueChanged" << value;
}

