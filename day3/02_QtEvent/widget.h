#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 重写定时器事件
    void timerEvent(QTimerEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int m_num1 = 1, m_num2 = 1, m_num3 = 1;
    int m_id1, m_id2;
    QTimer *m_timer;
};
#endif // WIDGET_H
