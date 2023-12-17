#ifndef MYCOIN_H
#define MYCOIN_H

#include "headers.h"

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);

    int posX; // x坐标
    int posY; // y坐标
    bool flag; // 正反标志
    bool isAnimation = false; // 是否执行动画标志
    bool notPress = false; // false = 能按，true = 不能按


    void changeFlag(); // 改变标志

    int min = 1; // 图片为金币
    int max = 8; // 图片为银币

    QTimer *timer1; // 正面 -> 反面
    QTimer *timer2; // 反面 -> 正面

    void mousePressEvent(QMouseEvent *e);





signals:

};

#endif // MYCOIN_H
