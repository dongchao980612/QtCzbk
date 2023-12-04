#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_posX = 0;
    m_timer = new QTimer(this);
    m_timer->start(100);

    connect(m_timer, &QTimer::timeout, [ = ]()
    {
        m_posX++;
        update();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
#if 0
    QPainter painter(this);

    //设置画笔
    QPen pen(Qt::lightGray);
    //设置画笔宽度
    pen.setWidth(3);
    //设置画笔风格
    pen.setStyle(Qt::DotLine);
    //让画家 使用这个笔
    painter.setPen(pen);

    //设置画刷
    QBrush brush(Qt::cyan);
    //设置画刷风格
    brush.setStyle(Qt::Dense7Pattern);
    //让画家使用画刷
    painter.setBrush(brush);


    //画线
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

    //画圆 椭圆
    painter.drawEllipse(QPoint(100, 100), 50, 50);

    //画矩形
    painter.drawRect(QRect(20, 20, 50, 50));

    //画文字
    painter.drawText(QRect(10, 200, 150, 50), "好好学习，天天向上");
#endif
#if 0
//////////////////////////////高级设置 ///////////////////////////////

    QPainter painter(this);

    //设置 抗锯齿能力  效率较低
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    // painter.drawEllipse(QPoint(100, 50), 50, 50);
    // painter.drawEllipse(QPoint(200, 50), 50, 50);


    // 画矩形
    painter.drawRect(QRect(20, 20, 50, 50));

    //移动画家
    painter.translate(100, 0);

    //保存画家状态
    painter.save();

    painter.drawRect(QRect(20, 20, 50, 50));

    painter.translate(100, 0);

    //还原画家保存状态
    painter.restore();
#endif

/////////////////////////////////利用画家 画资源图片 ///////////////////
    QPainter painter(this);
    QPixmap pix = QPixmap(":/Image/Luffy.png");

    //如果超出屏幕 从0开始
    if(m_posX >= this->width())
    {
        m_posX = -pix.width();
    }

    painter.drawPixmap(m_posX, 0, pix);
}


void Widget::on_pushButton_clicked()
{
    m_posX += 20;
    //如果要手动调用绘图事件 用update更新
    update();
}
