#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "headers.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Mainscene;
}
QT_END_NAMESPACE

class Mainscene : public QMainWindow
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);
    ~Mainscene();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_actionquit_triggered();

private:
    Ui::Mainscene *ui;
    ChooseLevelScene *m_chooseScene = NULL;
};
#endif // MAINSCENE_H
