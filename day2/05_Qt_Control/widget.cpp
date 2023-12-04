#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选框默认选中
    this->ui->radioButton_man->setChecked(true);

    // 选中女，打印信息
    connect(ui->radioButton_woman,&QRadioButton::clicked,[=](){
         qDebug()<<"选中了女";
    });

    //多选 三选
    connect(ui->checkBox_1,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<state;
    });

    //利用listWidget写诗,将一行诗放入到listWidget控件中
    QListWidgetItem * item = new QListWidgetItem("锄禾");
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter); //水平居中

    //QStringList   QList<QString>
    QStringList list ;
    list << "锄禾日当午" << "旱地和下土" << "谁知盘中餐"<< "粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

