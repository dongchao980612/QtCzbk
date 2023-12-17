#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "headers.h"

class MyCoin;

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    // explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    void paintEvent(QPaintEvent *event);

    MyCoin *coinBtn[4][4];

    // 关卡下标
    int levelIndex;
    int gameArray[4][4];

    bool isWin = true; //是否胜利的标志

signals:
    // 用于返回 选择关卡场景 的信号函数
    void selectLevelScene();
};

#endif // PLAYSCENE_H
