#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#if 1




    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    item->setTextAlignment(Qt::AlignCenter);//  设置居中
    ui->listWidget->addItem(item);









# else




    QStringList items;
    items << "锄禾日当午" << "汗滴禾下土";
    ui->listWidget->addItems(items);

#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
