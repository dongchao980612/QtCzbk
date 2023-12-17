#include "mypushbutton.h"

#if 0
MyPushButton::MyPushButton(QObject *parent) : QPushButton(parent)
{

}
#endif

MyPushButton::MyPushButton(QString normalImgPath, QString pressedImgPath)
{
    this->m_normalImgPath = normalImgPath;
    this->m_pressedImgPath = pressedImgPath;


    QPixmap pix;
    bool res = pix.load(normalImgPath);
    if(!res)
    {
        qDebug() << "图片加载失败！";
        return;
    }

    //设置图片的固定尺寸
    this->setFixedSize(pix.size());

    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}

void MyPushButton::downBounce()
{
    // 1. 创建动态对象
    QPropertyAnimation *ani = new QPropertyAnimation(this, "geometry");

    // 2. 设置动画时间间隔
    ani->setDuration(DURATIONTIME);

    // 3. 起始位置
    ani->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 4. 结束位置
    ani->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    // 5. 设置弹跳曲线
    ani->setEasingCurve(QEasingCurve::OutBounce);

    // 6. 执行动画
    ani->start();
}

void MyPushButton::upBounce()
{
    // 1. 创建动态对象
    QPropertyAnimation *ani = new QPropertyAnimation(this, "geometry");

    // 2. 设置动画时间间隔
    ani->setDuration(DURATIONTIME);

    // 3. 起始位置
    ani->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    // 4. 结束位置
    ani->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    // 5. 设置弹跳曲线
    ani->setEasingCurve(QEasingCurve::OutBounce);

    // 6. 执行动画
    ani->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    // qDebug() << __FUNCTION__;
    if(this->m_pressedImgPath != "")
    {
        QPixmap pix;
        bool res = pix.load(this->m_pressedImgPath);
        if(!res)
        {
            qDebug() << "图片加载失败！";
            return;
        }

        this->setFixedSize(pix.size());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(pix.size());
    }

    // return 给父类
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    // qDebug() << __FUNCTION__;
    if(this->m_pressedImgPath != "")
    {
        QPixmap pix;
        bool res = pix.load(this->m_normalImgPath);
        if(!res)
        {
            qDebug() << "图片加载失败！";
            return;
        }

        // this->resize(pix.width(), pix.height());

        this->setStyleSheet("QPushButton{border:0px;}");

        this->setIcon(pix);

        this->setIconSize(pix.size());
    }

    // return 给父类
    return QPushButton::mouseReleaseEvent(e);
}
