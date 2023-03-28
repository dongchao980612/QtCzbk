# QtCzbk
B站视频[传智播客《QT从入门到实战完整版》](https://www.bilibili.com/video/BV1g4411H78N)

## 第一天：
1、Qt的介绍、优点、成功案例
2、创建第一个Qt程序

**.pro文件就是工程文件(project)，它是qmake自动生成的用于生产makefile的配置文件**

```tex
QT       += core gui   # Qt包含的模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  # 大于4版本以上 包含 widget模块

TARGET = 01_FirstProject  # 目标   生成的.exe程序的名称
TEMPLATE = app       	  # 模板   应用程序模板  Application  


SOURCES += main.cpp\      # 源文件
		mywidget.cpp

HEADERS  += mywidget.h    # 头文件
```
命名规范与快捷键

```tex
命名规范
	类名 首字母大写，单词和单词之间首字母大写
	函数名 变量名称 首字母小写，单词和单词之间首字母大写
快捷键
    注释  ctrl + /
    运行  ctrl + r
    编译  ctrl + b
    字体缩放 ctrl + 鼠标滚轮
    查找  ctrl + f
    整行移动 ctrl + shift + ↑ 或者↓
    帮助文档 F1
    自动对齐  ctrl + i;
    同名之间的.h 和 .cpp切换  F4
```

3、熟悉按钮控件常用API
4、对象树的基本概念
5、Qt中的坐标系统
6、信号和槽的基本使用以及拓展

```c++
connect信号的发送者,发送的信号（函数的地址）,信号的接受者,处理的槽函数);
// connect(myBtn, &MyPushButton::clicked, this, &myWidget::close);
connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
```

- 自定义信号

```tex
写到 signals下
返回 void
需要声明，不需要实现
可以有参数，可以重载
```

-  自定义槽函数

```tex
返回void
需要声明，也需要实现
可以有参数，可以重载
写到public slot下或者public或者全局函数
```

- 重载版本

```c++
// 无参
connect(zt, &Teacher::hurgry, st, &Student::treat);


// 有参
void  (Teacher::*teacherSignal)(QString) = &Teacher::hurgry;
void  (Student::*studentSignal)(QString) = &Student::treat;

connect(zt, teacherSignal, st, studentSignal);
```


## 第二天：

1、带菜单栏的窗口
2、资源文件
3、对话框
4、界面布局
5、常用控件
6、自定义控件

## 第三天：
1、事件处理
2、定时器
3、Event事件分发器
4、事件过滤器
5、QPainter绘图
6、绘图设备的使用
7、Qfile文件读写操作

## 第四、五天：
Qt游戏制作-翻金币案例