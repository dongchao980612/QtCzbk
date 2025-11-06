#ifndef MODEL_H
#define MODEL_H

#include"jsonutils.h"

class Student
{
public:
    int m_id;         // 学号
    QString m_name;   // 姓名
    int m_age;        // 年龄
    QString m_major;  // 专业

    Student(int id, QString name, int age, QString major)
    {
        m_id = id;
        m_name = name;
        m_age = age;
        m_major = major;
    }

} ;


template <>
struct JsonConverter<Student>
{
    // 将Student对象转换为QJsonObject（成员变量名改为m_xxx）
    static QJsonObject toJson(const Student& data)
    {
        QJsonObject obj;
        obj["id"] = data.m_id;       // 原id → m_id
        obj["name"] = data.m_name;   // 原name → m_name
        obj["age"] = data.m_age;     // 原age → m_age
        obj["major"] = data.m_major; // 原major → m_major
        return obj;
    }

    // 将QJsonObject转换为Student对象（需调用带参数的构造函数）
    static Student fromJson(const QJsonObject& obj)
    {
        // 从JSON中解析字段，通过构造函数初始化Student对象
        return Student(
                   obj["id"].toInt(),
                   obj["name"].toString(),
                   obj["age"].toInt(),
                   obj["major"].toString()
               );
    }
};

#endif // MODEL_H
