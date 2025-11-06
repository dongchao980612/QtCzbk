#include <iostream>
#include <QDebug>

#include "model.h"
#include "jsonutils.h"

using namespace std;



int main()
{
    // 1. 创建Json工具（学生表）
    JsonUtils < Student > studentDB;

    // 2. 新建并打开JSON文件（类似创建并打开数据库表）
    if (!studentDB.create("students.json"))
    {
        qDebug() << "创建文件失败";
        return -1;
    }
    if (!studentDB.open("students.json"))
    {
        qDebug() << "打开文件失败";
        return -1;
    }

    // 3. 插入数据（增）
    Student s1{1, "张三", 20, "计算机科学"};
    Student s2{2, "李四", 21, "电子信息"};
    Student s3{3, "李四", 25, "电子信息"};

    studentDB.insert(s1);
    studentDB.insert(s2);
    studentDB.insert(s3);
    studentDB.save(); // 手动保存（或close时自动保存）

    // 4. 查询数据（查）：查询所有学生
    QList < Student > allStudents = studentDB.query();
    qDebug() << "所有学生：";
    for (const auto& s : allStudents)
    {
        qDebug() << s.m_id << s.m_name << s.m_age << s.m_major;
    }
#if  0
    // 5. 更新数据（改）：将张三的年龄改为21
    int updated = studentDB.update([](Student & s)
    {
        if (s.m_name == "张三")
        {
            s.m_age = 21;
            return true; // 表示数据已修改
        }
        return false;
    });
    qDebug() << "更新了" << updated << "条数据";

    // 6. 删除数据（删）：删除专业为电子信息的学生
    int removed = studentDB.remove([](const Student & s)
    {
        return s.m_major == "电子信息";
    });
    qDebug() << "删除了" << removed << "条数据";

#endif
    // 7. 关闭文件（自动保存）
    studentDB.close();
    return 0;
}
