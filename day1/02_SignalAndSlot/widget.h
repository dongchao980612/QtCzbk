#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    Teacher *zt; // 老师对象
    Student *st; // 学生对象
    QPushButton *btn; //下课按钮
    QPushButton * btn2;
    QPushButton * btn3;

    QPushButton * myBtn;
    QPushButton * myBtn2;


    void classIsOver();
};
#endif // WIDGET_H
