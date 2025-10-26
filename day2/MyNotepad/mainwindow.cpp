#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(370, 360);

    // 菜单栏
    QMenuBar *bar =  menuBar();
    this->setMenuBar(bar);

    // 菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * edidMenu = bar->addMenu("编辑");
    QMenu *formatMenu = bar->addMenu("格式");
    QMenu *viewMenu = bar->addMenu("查看");
    QMenu *helpMenu = bar->addMenu("帮助");

    // 添加菜单项
    QAction *newAction = fileMenu->addAction("新建");          // 新建文件
    connect(newAction, &QAction::triggered, this, [ = ]()
    {
        qDebug() << "新建";
    });

    QAction *newWindowAction = fileMenu->addAction("新窗口");  // 新建窗口

    connect(newWindowAction, &QAction::triggered, this, [ = ]()
    {
        qDebug() << "新窗口";
    });


    QAction *openAction = fileMenu->addAction("打开");          // 打开文件
    QAction *saveAction = fileMenu->addAction("保存");          // 保存文件
    QAction *saveAsAction = fileMenu->addAction("另存为");      // 另存为
    fileMenu->addSeparator();

    QAction *pageSetupAction = fileMenu->addAction("页面设置");  // 页面设置
    QAction *printAction = fileMenu->addAction("打印");          // 打印

    fileMenu->addSeparator();
    QAction *exitAction = fileMenu->addAction("退出");          // 退出

    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow() {}
