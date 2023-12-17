#include "playscene.h"
#if 0
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{

}
#endif
PlayScene::PlayScene(int levelNum)
{
    QString str = QString("关卡 %1").arg(levelNum);

    this->levelIndex = levelNum;

    // 1. 设置窗口信息
    this->setFixedSize(WIDTH, HEIGHT);
    this->setWindowTitle(str);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    // 2. 创建菜单栏
    QMenuBar *menubar =  menuBar();
    setMenuBar(menubar);

    // 3. 创建菜单栏开始
    QMenu *startMenu = menubar->addMenu("开始");

    // 4. 创建菜单项退出
    QAction *quitAction = startMenu->addAction("退出");

    // 5. 退出
    connect(quitAction, &QAction::triggered, [ = ]()
    {
        this->close();
    });


    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav", this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav", this);
    //返回按钮音效
    QSound *backSound = new QSound(":/res/TapButtonSound.wav", this);


    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 20, this->height() - backBtn->height() - 20);
    connect(backBtn, &QPushButton::clicked, [ = ]()
    {
        // qDebug() << __FILE__ << "点击了返回按钮";
        backSound->play();
        QTimer::singleShot(DELAYTIME, this, [ = ]()
        {
            emit this->selectLevelScene(); // 发出信号，返回到主界面
        });
    });

    DataConfig config;
    // 临时存储金币数组
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    // 显示当前关卡数
    QLabel *label = new QLabel;
    label->setParent(this);

    QFont font;
    font.setFamily("楷体");
    font.setPointSize(26);

    label->setStyleSheet("color:#ff6600;");
    label->setFont(font);

    QString labelText = QString("Level:%1").arg(levelNum);
    label->setText(labelText);

    label->setGeometry(30, this->height() - 66, 200, 50);


    // 胜利时候显示的图片
    QLabel *winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width()) * 0.5, -tmpPix.height());



    //金币背景图案
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QPixmap pix = QPixmap(":/res/BoardNode.png");

            QLabel *label = new QLabel;
            label->setScaledContents(true);
            label->setGeometry(0, 0, pix.width() * 1.2, pix.height() * 1.2);

            label->setPixmap(pix);
            label->setParent(this);
            label->move(80 + i * 60, 200 + j * 60);

            QString str =  this->gameArray[i][j] == 1 ? ":/res/Coin0001.png" : ":/res/Coin0008.png";
            MyCoin *coin = new MyCoin(str);
            coin->setParent(label);

            // 给金币属性赋值
            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j]; // 1正面 0反面
            coin->notPress = false;

            coinBtn[i][j] = coin;


            // 点击金币，进行反转
            connect(coin, &MyCoin::clicked, [ = ]()
            {
                flipSound->play();
                // 点击的过程中，默认为赢，防止恶意卡bug，在点击的同时点其他按钮
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        this->coinBtn[i][j]->notPress = true;
                    }
                }

                coin->changeFlag();
                // 点击金币之后，需要更新一下数组，如果存的是正面，点击后是反面
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                // 反转周围的金币
                QTimer::singleShot(DELAYTIME, this, [ = ]()
                {
                    // 上
                    if(coin->posY - 1 >= 0)
                    {
                        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY - 1] = this->gameArray[coin->posX][coin->posY - 1] == 0 ? 1 : 0;
                    }

                    // 下
                    if(coin->posY + 1 <= 3)
                    {
                        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY + 1] = this->gameArray[coin->posX][coin->posY + 1] == 0 ? 1 : 0;
                    }

                    // 左
                    if(coin->posX - 1 >= 0)
                    {
                        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX - 1][coin->posY] = this->gameArray[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
                    }

                    // 右
                    if(coin->posX + 1 <= 3)
                    {
                        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX + 1][coin->posY] = this->gameArray[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
                    }

                    // 翻完金币，默认还未胜利，继续判断
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            this->coinBtn[i][j]->notPress = false;
                        }
                    }

                    this->isWin = true;

                    // 判断是否有银币，如果有说明游戏还没胜利
                    for(int i = 0; i < 4; i++)
                    {
                        for(int j = 0; j < 4; j++)
                        {
                            if(coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    // 没有银币了，那么游戏胜利！
                    if(this->isWin == true)
                    {
                        winSound->play();
                        // qDebug() << "游戏胜利！";
                        // 禁用按钮
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = 0; j < 4; j++)
                            {
                                this->coinBtn[i][j]->notPress = true;
                            }
                        }

                        QPropertyAnimation *ani = new QPropertyAnimation(winLabel, "geometry");
                        ani->setDuration(DURATIONTIMEWIN);
                        ani->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
                        ani->setEndValue(QRect(winLabel->x(), winLabel->y() + 360, winLabel->width(), winLabel->height()));
                        ani->setEasingCurve(QEasingCurve::OutBounce);
                        ani->start();

                        winLabel->raise(); // 将图片显示在最顶层，如果没有，图片将显示在最底层
                    }
                });
            });
        }
    }
}
void PlayScene::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    // 1. 加载背景图片
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");

    // 2. 创建画家
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 3. 加载游戏图标
    pix.load(":/res/Title.png");
    pix = pix.scaled( pix.width() * 0.8, pix.height() * 0.8);
    painter.drawPixmap(10, 30, pix);
}
