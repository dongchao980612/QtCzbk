#ifndef DATACONFIG_H
#define DATACONFIG_H

#include "headers.h"


class DataConfig : public QObject
{
    Q_OBJECT
public:
    explicit DataConfig(QObject *parent = 0);

public:

    QMap<int, QVector< QVector<int> > >mData;//双端数组 int 相当于关卡



signals:

public slots:
};

#endif // DATACONFIG_H
