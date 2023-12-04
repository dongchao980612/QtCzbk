#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 启动定时器
    m_id1 = startTimer(1000);   //label_2

    m_id2 = startTimer(2000); //label_3

    m_timer = new QTimer;
    m_timer->start(500);
    //定时器事件到了 发出timeout信号
    connect(m_timer, &QTimer::timeout, [ = ]()
    {
        ui->label_4->setText(QString::number(m_num3++));
    });

    // 给label1安装事件过滤器
    // 步骤1：给控件安装事件过滤器
    ui->label->installEventFilter(this);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_id1)
    {
        ui->label_2->setText(QString::number(m_num1++));
    }

    if(event->timerId() == m_id2)
    {
        ui->label_3->setText(QString::number(m_num2++));
    }


}
// 步骤2：重写事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->label)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev  = static_cast<QMouseEvent *>(event);
            QString str = QString( "事件过滤器中：：鼠标按下了 x = %1   y = %2  globalX = %3 globalY = %4 " ).arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;
            return true;
        }
    }

    return QWidget::eventFilter(obj, event);
}


void Widget::on_pushButton_clicked()
{
    m_timer->stop();
}
