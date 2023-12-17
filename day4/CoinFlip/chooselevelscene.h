#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

#include "headers.h"

class PlayScene;  // 前置声明

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);


    void paintEvent(QPaintEvent *event);

    PlayScene *playScene = NULL;

signals:
    // 选择返回的信号函数
    void  chooseBackScene();
};

#endif // CHOOSELEVELSCENE_H
