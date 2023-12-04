#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
     // 重置窗口大小
    this->resize(600,400);

    //创建菜单栏，最多有一个
    QMenuBar *ba=new QMenuBar();

    // 创建文件菜单
    QMenu* fileMenu = ba->addMenu("文件");
    // 创建菜单项
    QAction* newAction = fileMenu->addAction("新建");
    QAction* openAction = fileMenu->addAction("打开");
    fileMenu->addSeparator();  // 添加分割线
    fileMenu->addAction("退出");
    // 创建编辑菜单
    QMenu* editMenu = ba->addMenu("编辑");
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");
    editMenu->addAction("剪切");
    editMenu->addSeparator();  // 添加分割线
    editMenu->addAction("全选");

    this->setMenuBar(ba);


    //创建工具栏，可以有多个
    QToolBar* toolBar=new QToolBar(this);
    // this->addToolBar(toolBar);
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    //只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //取消浮动
    toolBar->setFloatable(false);

    //设置不可移动
    toolBar->setMovable(true);

    // 添加
    toolBar->addAction(newAction);
    toolBar->addSeparator();//添加分割线
    toolBar->addAction(openAction);
    
    //添加控件
    QPushButton* btn=new QPushButton("按钮",this);
    toolBar->addWidget(btn);


    //状态栏 最多一个
    QStatusBar* stBar=new QStatusBar();
    this->setStatusBar(stBar);

    // 添加标签控件
    QLabel* label =new QLabel("右侧提示信息",this);
    // stBar->addWidget(label);// 左侧
    stBar->addPermanentWidget(label); // 右侧

    //浮动窗口，可以多个
    QDockWidget* dockWidget= new QDockWidget("浮动窗口",this);
    this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    //只允许左右停靠
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    //取消浮动
    dockWidget->setFloating(false);

    //设置中心部件，只能一个
    QTextEdit* edit = new QTextEdit(this);
    this->setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

