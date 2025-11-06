#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRandomGenerator>

#include <QMainWindow>

typedef struct Student
{
    QString name;
    QString gender;
    quint8 age;

    Student(QString n = "", QString g = "", quint8 a = 0)
        : name(n), gender(g), age(a) {}
} Student;

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
