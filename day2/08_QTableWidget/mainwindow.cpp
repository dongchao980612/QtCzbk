#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    const int C  = 3;
    const int R = 5;


    const int min = 18;
    const int max = 25;


    // 设置列数
    ui->tableWidget->setColumnCount(C);

    // 设置行数
    ui->tableWidget->setRowCount(R);

    // 设置表头
    QStringList items;
    items << "姓名" << "性别" << "年龄";
    ui->tableWidget->setHorizontalHeaderLabels(items);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置内容;
    QList<Student> studentList;
    for (int i = 0; i < R; ++i)
    {
        QString name = QString("姓名%1").arg(i + 1);

        QString gender = QRandomGenerator::global()->bounded(2) == 0 ? "男" : "女";
        int age = QRandomGenerator::global()->bounded(min, max + 1);

        studentList.append(Student(name, gender, age));
    }


    for(int row = 0; row < studentList.size(); row++)
    {
        int col = 0;
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(studentList[row].name));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(studentList[row].gender));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem(QString::number(studentList[row].age)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
