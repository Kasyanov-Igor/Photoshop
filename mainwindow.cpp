#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::on_pushButton_clicked()
{
    QString str;

    str = QFileDialog::getOpenFileName(this,"Open","c:/");


    QPixmap pix;

    pix.load(str);
    ui->label->setPixmap(pix);
    ui->label->setScaledContents(true);
    int pix1=pix.width();
    int label1=ui->label->width();

    double factor = double(label1)/pix1;
    // qDebug()<<pix1;
    // qDebug()<<label1;
    //qDebug()<<factor;

    ui->label->setFixedWidth(factor * ui->label->pixmap().width());
    ui->label->setFixedHeight(factor * ui->label->pixmap().height());

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{

    ui->label->setFixedWidth(arg1 * ui->label->pixmap().width());
    ui->label->setFixedHeight(arg1 * ui->label->pixmap().height());
}


void MainWindow::on_actionNew_File_triggered()
{

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}





void MainWindow::on_label_linkActivated(const QString &link)
{

}

