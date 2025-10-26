#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    this->resize(600,400);


    // 菜单栏
    QMenuBar *bar =  menuBar();
    this->setMenuBar(bar);

    // 菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * edidMenu = bar->addMenu("编辑");
    Q_UNUSED(edidMenu);
    // 添加菜单项
    QAction *newAction = fileMenu->addAction("新建");
    QAction *openAction = fileMenu->addAction("打开");

    // 添加分割线
    fileMenu->addSeparator();

    fileMenu->addAction("退出");



    QToolBar* toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //移动总开关
    toolBar->setMovable(true);

    // 设置允许停靠的位置、只能停靠在左右
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    // 取消浮动
    toolBar->setFloatable(false);

    //添加菜单项
    toolBar->addAction(newAction); // 添加新建QAction
    toolBar->addSeparator();  // 添加分割线
    toolBar->addAction(openAction); // 添加打开QAction

    // 添加控件
    QPushButton* btn = new QPushButton("按钮",this);
    toolBar->addWidget(btn);

    QStatusBar* stBar = statusBar();
    setStatusBar(stBar);

    QLabel* l1 = new QLabel("提示信息1",this);
    QLabel* l2 = new QLabel("提示信息2",this);

    stBar->addWidget(l1);
    stBar->addPermanentWidget(l2);

    // 浮动窗口
    QDockWidget* dockWidget=new  QDockWidget("浮动窗口",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    // 中心部件,只能有一个
    // QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 设置允许停靠位置
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);

}

MainWindow::~MainWindow() {}



