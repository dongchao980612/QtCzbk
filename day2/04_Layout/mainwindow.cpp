#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setWindowIcon(QIcon(":/image/login.png"));
    setFixedSize(330, 280);
    setWindowTitle("登录");

    //  密码输入不可见
    ui->lineEdit_pwd->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString uname = ui->lineEdit_uname->text().trimmed(); // 先去除首尾空格
    QString pwd = ui->lineEdit_pwd->text();

    // 1. 判断用户名是否为空（去除空格后）
    if (uname.isEmpty())
    {
        QMessageBox::information(this, "提示", "请输入用户名");
        ui->lineEdit_uname->setFocus(); // 光标定位到用户名输入框
        return; // 终止后续校验
    }

    // 2. 判断密码是否为空
    if (pwd.isEmpty())
    {
        QMessageBox::information(this, "提示", "请输入密码");
        ui->lineEdit_pwd->setFocus(); // 光标定位到密码输入框
        return; // 终止后续校验
    }

    // 3. 校验用户名是否正确
    if (uname != UNAME)
    {
        QMessageBox::critical(this, "提示", "用户名错误");
        ui->lineEdit_uname->selectAll(); // 选中错误的用户名，方便修改
        ui->lineEdit_uname->setFocus();
        qDebug() << "用户名错误:" << uname.toUtf8().data();
    }
    // 4. 用户名正确时，校验密码
    else if (pwd != PWD)
    {
        QMessageBox::critical(this, "提示", "密码错误");
        ui->lineEdit_pwd->selectAll(); // 选中错误的密码，方便修改
        ui->lineEdit_pwd->setFocus();
        qDebug() << "密码错误（用户:" << uname.toUtf8().data() << "）";
    }
    // 5. 用户名和密码都正确
    else
    {
        QMessageBox::information(this, "提示", "登录成功");
        qDebug() << LOGING_OK_MESSAGE;
        // 这里可以添加登录成功后的逻辑（如跳转主窗口）
    }
}


void MainWindow::on_pushButton_cencel_clicked()
{
    close();
}

