#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <QVariant>
#include <stdexcept>
#include <functional>

// 前置声明：数据转换接口（需用户针对自定义类型实现特化）
template <typename T>
struct JsonConverter
{
    // 将自定义类型转换为QJsonObject
    static QJsonObject toJson(const T& data);
    // 将QJsonObject转换为自定义类型
    static T fromJson(const QJsonObject& obj);
};

template <typename T>
class JsonUtils
{
public:
    // 构造函数
    JsonUtils() : m_isOpen(false) {}

    // 析构函数：自动关闭文件
    ~JsonUtils()
    {
        close();
    }

    // 新建JSON文件（若文件已存在则清空）
    bool create(const QString& filePath)
    {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return false;
        }
        // 初始化空数组作为根节点（存储多条数据）
        QJsonArray rootArray;
        QJsonDocument doc(rootArray);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        m_filePath = filePath;
        m_isOpen = false; // 新建后需手动打开
        return true;
    }

    // 打开JSON文件
    bool open(const QString& filePath)
    {
        if (m_isOpen)
        {
            close(); // 关闭已打开的文件
        }
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }
        // 解析JSON内容
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isArray())
        {
            return false; // 根节点必须是数组
        }
        m_rootArray = doc.array();
        m_filePath = filePath;
        m_isOpen = true;
        return true;
    }

    // 关闭JSON文件（自动保存）
    void close()
    {
        if (m_isOpen)
        {
            save();
            m_isOpen = false;
            m_filePath.clear();
            m_rootArray = QJsonArray();
        }
    }

    // 保存数据到文件
    bool save()
    {
        if (!m_isOpen)
        {
            return false;
        }
        QFile file(m_filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return false;
        }
        QJsonDocument doc(m_rootArray);
        file.write(doc.toJson(QJsonDocument::Indented));
        return true;
    }

    // 插入数据（增）
    bool insert(const T& data)
    {
        if (!m_isOpen)
        {
            return false;
        }
        // 转换数据为JSON对象并添加到数组
        QJsonObject obj = JsonConverter<T>::toJson(data);
        m_rootArray.append(obj);
        return true;
    }

    // 删除数据（删）：通过条件函数匹配
    int remove(const std::function<bool(const T&)>& condition)
    {
        if (!m_isOpen)
        {
            return 0;
        }
        int count = 0;
        // 反向遍历删除，避免索引错乱
        for (int i = m_rootArray.size() - 1; i >= 0; --i)
        {
            QJsonValue val = m_rootArray[i];
            if (!val.isObject())
            {
                continue;
            }

            T data = JsonConverter<T>::fromJson(val.toObject());
            if (condition(data))
            {
                m_rootArray.removeAt(i);
                count++;
            }
        }
        return count;
    }

    // 更新数据（改）：通过条件函数匹配并更新
    int update(const std::function<bool(T&)>& updater)
    {
        if (!m_isOpen)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < m_rootArray.size(); ++i)
        {
            QJsonValue val = m_rootArray[i];
            if (!val.isObject())
            {
                continue;
            }

            T data = JsonConverter<T>::fromJson(val.toObject());
            if (updater(data))   // 若更新函数返回true，表示数据被修改
            {
                m_rootArray[i] = JsonConverter<T>::toJson(data);
                count++;
            }
        }
        return count;
    }

    // 查询数据（查）：返回所有满足条件的数据
    QList<T> query(const std::function<bool(const T&)>& condition = nullptr)
    {
        QList<T> result;
        if (!m_isOpen)
        {
            return result;
        }
        for (const QJsonValue& val : m_rootArray)
        {
            if (!val.isObject())
            {
                continue;
            }

            T data = JsonConverter<T>::fromJson(val.toObject());
            // 若没有条件，则返回所有数据；否则返回满足条件的数据
            if (!condition || condition(data))
            {
                result.append(data);
            }
        }
        return result;
    }

    // 判断是否已打开
    bool isOpen() const
    {
        return m_isOpen;
    }

private:
    QString m_filePath;       // JSON文件路径
    bool m_isOpen;            // 是否已打开
    QJsonArray m_rootArray;   // 根节点（存储所有数据的数组）
};

#endif // JSONUTILS_H
