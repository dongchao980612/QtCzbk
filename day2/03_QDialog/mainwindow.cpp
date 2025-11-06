#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    //  点击新建按钮，弹出对话框
    connect(ui->actionnew_1, &QAction::triggered, [ = ]()
    {
        //  模态对话框
        // QDialog dlg(this);
        // dlg.resize(200, 100);
        // dlg.exec();
        // qDebug() << "模态对话框弹出了";


        //  非模态对话框(栈上)
        // QDialog dlg(this);
        // dlg.show();
        //  非模态对话框(堆上)
        // QDialog* dlg = new QDialog(this);
        // dlg->setAttribute(Qt::WA_DeleteOnClose);
        // dlg->show();
        // qDebug() << "非模态对话框弹出了";


        // QMessageBox::critical(this, "Critical", "错误");
        // QMessageBox::information(this, "Information", "信息");
#if 0
        QMessageBox::StandardButton btn = QMessageBox::question(this, "Question", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
        if( btn == QMessageBox::Save)
        {
            qDebug() << "Save...";
        }
        else
        {
            qDebug() << "Cancel...";
        }
#endif
        // QMessageBox::warning(this, "warning", "警告");


        // QColor c = QColorDialog::getColor(QColor(255, 255, 0));
        // QColor c = QColorDialog::getColor();
        // qDebug() << c;

        // 打开文件
        // QString fileName = QFileDialog::getOpenFileName(this, "打开文件", QCoreApplication::applicationDirPath(), "所有文件 (*);;文本文件 (*.txt)");
        // qDebug() << fileName;

        // 打开文件夹
        // QString dirName = QFileDialog::getExistingDirectory(this, "打开文件参夹", QCoreApplication::applicationDirPath());
        // qDebug() << dirName;
#if 0
        bool ok ;
        QFont font = QFontDialog::getFont(&ok, this);
        if (ok)    // 用户点击了“确定”，字体有效
        {
            qDebug() << "选中的字体：" << font.family().toUtf8().data();
        }
        else      // 用户点击了“取消”，字体为默认值
        {
            qDebug() << "未选择字体（用户取消）";
        }
#endif

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
