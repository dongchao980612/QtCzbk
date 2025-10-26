#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
public slots:
    // 1.写在public slots  2.写在public  3. 写在全局函数
    // 返回值是void,需要声明,可以发生重载
    void treat();
    void treat(QString sth);
};

#endif // STUDENT_H
