#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include "headers.h"


/*
 * MyPushButton类，主要用于实现Start，Back按钮
 */
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyPushButton(QObject *parent = nullptr);
    MyPushButton(QString normalImgPath, QString pressedImgPath = "");

    // 下坠
    void downBounce();
    // 上弹
    void upBounce();


    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);


private:
    // 正常显示的图片路径
    QString m_normalImgPath;
    // 按压时的图片路径
    QString m_pressedImgPath;

signals:

};

#endif // MYPUSHBUTTON_H
