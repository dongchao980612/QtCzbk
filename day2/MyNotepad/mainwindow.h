#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMenuBar>  // 菜单栏
#include <QToolBar>  // 工具栏
#include <QStatusBar>  // 状态栏
#include <QDockWidget>  // 浮动窗口
#include <QTextEdit>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

};
#endif // MAINWINDOW_H
