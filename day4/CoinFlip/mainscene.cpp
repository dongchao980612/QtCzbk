#include "mainscene.h"
#include "ui_mainscene.h"

Mainscene::Mainscene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainscene)
{
    ui->setupUi(this);

    //配置场景

    //配置窗口大小
    this->setFixedSize(WIDTH, HEIGHT);

    // 设置图标
    QIcon icon(":/res/Coin0001.png");
    if(icon.isNull()) // todo
    {
        qDebug() << "icon is Null..." << endl;
    }
    else
    {
        this->setWindowIcon(icon);
    }


    // 设置标题
    this->setWindowTitle("翻金币主场景");

    // 添加音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);
    // startSound->setLoops(-1); // 设置循环
    startSound->play();

    // 创建Start按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5, this->height() * 0.7);

    m_chooseScene = new ChooseLevelScene;


    connect(startBtn, &QPushButton::clicked, [ = ]()
    {
        startSound->play();
        // startBtn->downBounce();
        startBtn->upBounce();
        // qDebug() << "点击了开始按钮";

        // 延时进入场景
        QTimer::singleShot(DELAYTIME, this, [ = ]()
        {
            // 设置窗口固定
            m_chooseScene->setGeometry(this->geometry());
            //进入关关卡选择场景
            this->hide();
            m_chooseScene->show();
        });

    });

    // 返回主界面
    connect(m_chooseScene, &ChooseLevelScene::chooseBackScene, this, [ = ]()
    {
        // 设置固定窗口
        this->setGeometry(m_chooseScene->geometry());
        m_chooseScene->close();
        this->show();
    });


}

Mainscene::~Mainscene()
{
    delete ui;
}

// 画背景图
void Mainscene::paintEvent(QPaintEvent *event)
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
    pix = pix.scaled( pix.width() * 0.8, pix.height() * 0.8); // 缩放
    painter.drawPixmap(10, 30, pix);
}


void Mainscene::on_actionquit_triggered()
{
    // 退出按钮实现
    this->close();
}


