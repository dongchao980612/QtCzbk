#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
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

    void timerEvent(QTimerEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int timer_id1;
    int timer_id2;

    QTimer  *t;
};
#endif // MAINWINDOW_H
