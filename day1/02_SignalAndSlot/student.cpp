#include "student.h"

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"老师请吃饭!";
}

void Student::treat(QString sth)
{
    qDebug()<<"老师请吃" << sth.toUtf8().data()<< "!";
}

