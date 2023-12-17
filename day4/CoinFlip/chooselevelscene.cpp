#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    // 1. 设置新窗口
    this->setFixedSize(WIDTH, HEIGHT);
    this->setWindowTitle("关卡选择");
    QPixmap pix(":/res/Coin0001.png");
    this->setWindowIcon(pix);

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

    //选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav", this);
    QSound *backSound = new QSound(":/res/TapButtonSound.wav", this);


    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 20, this->height() - backBtn->height() - 20);
    connect(backBtn, &QPushButton::clicked, [ = ]()
    {
        // qDebug() << "点击了返回按钮";
        // 延时返回
        backSound->play();
        QTimer::singleShot(DELAYTIME, this, [ = ]()
        {
            emit this->chooseBackScene(); // 发出信号，返回到主界面
        });

    });
    // 创建选择关卡的按钮
    for (int i = 0; i < 20; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);  // 参数1：横坐标 参数2：纵坐标 70：按钮间隔 (70, 180)：起始移动坐标
        menuBtn->move(70 + i % 4 * 70, 180 + i / 4 * 70);


        connect(menuBtn, &QPushButton::clicked, [ = ]()
        {
            // qDebug() << QString("您选择的是第 %1 关.").arg(i + 1);
            chooseSound->play();
            this->hide();// 隐藏选关场景
            this->playScene = new PlayScene(i + 1); // 新建游戏场景

            // 设置固定窗口
            playScene->setGeometry(this->geometry());
            playScene->show(); // 显示游戏场景

            // 游戏场景的Back按钮
            connect(playScene, &PlayScene::selectLevelScene, [ = ]()
            {
                // 设置固定窗口
                this->setGeometry(playScene->geometry());
                this->show();
                delete playScene;
                playScene = NULL;
            });
        });

        QLabel *label = new QLabel(menuBtn);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setAttribute(Qt::WA_TransparentForMouseEvents); // 可省, 把label放在下面, selectBtn放在前面
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.6, 40, pix.width() * 1.2, pix.height() * 1.2, pix);
}
