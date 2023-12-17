#include "mycoin.h"
#if 0
MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}
#endif
MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool res = pix.load(btnImg);
    if(!res)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;
    }
    this->setFixedSize(pix.width() * 1.4, pix.height() * 1.4);

    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 金币翻成银币
    connect(timer1, &QTimer::timeout, [ = ]()
    {
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);

        QPixmap pix;
        pix.load(str);

        this->setFixedSize(pix.width() * 1.4, pix.height() * 1.4);

        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        // 判断翻完了
        if(this->min > this->max)
        {
            this->min = 1;
            this->isAnimation = false;// 做完动画
            timer1->stop();
        }
    });

    // 银币翻成金币
    connect(timer2, &QTimer::timeout, [ = ]()
    {
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);

        QPixmap pix;
        pix.load(str);

        this->setFixedSize(pix.width() * 1.4, pix.height() * 1.4);

        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        // 判断翻完了
        if(this->max < this->min)
        {
            this->max = 8;
            this->isAnimation = false; // 做完动画
            timer2->stop();
        }
    });
}
void MyCoin::changeFlag()
{
    if(this->flag)
    {
        timer1->start(TIMERS);
        this->isAnimation = true; // 开始动画
        this->flag = false;
    }
    else
    {
        timer2->start(TIMERS);
        this->isAnimation = true;// 开始动画
        this->flag = true;
    }

}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->notPress)
    {
        return;
    }
    return QPushButton::mousePressEvent(e);
}

