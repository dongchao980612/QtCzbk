#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#define UNAME  "root"
#define PWD  "admin"
#define LOGING_OK_MESSAGE "登陆成功"
#define LOGING_ERROR_MESSAGE "登陆失败"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_cencel_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
