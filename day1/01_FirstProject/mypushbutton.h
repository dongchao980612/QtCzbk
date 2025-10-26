#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>

class MyPushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushbutton(QPushButton *parent = nullptr);

    ~MyPushbutton();

signals:
};

#endif // MYPUSHBUTTON_H
