#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置单选按钮默认状态
    ui->radioButton_man->setChecked(true);
    ui->radioButton_married->setChecked(true);

    connect(ui->radioButton_man, &QRadioButton::clicked, this, [ = ]
    {
        qDebug() << "选中了男!";
    });
    connect(ui->radioButton_woman, &QRadioButton::clicked, this, [ = ]
    {
        qDebug() << "选中了女!";
    });


    //  多选按钮
    connect(ui->checkBox_beijing, &QCheckBox::checkStateChanged, this, [ = ](int state)
    {
        qDebug() << state;
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
