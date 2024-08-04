#include "mainwindow.h"
#include "./ui_mainwindow.h"


void MainWindow::on_pushButton_clicked()
{


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto it = ui->centralwidget->children().begin();
    std::advance(it, 2);

    this->_sizeW = (QSpinBox*)*it;
    this->_sizeW->hide();

    std::advance(it, 1);
    this->_sizeH = (QSpinBox*)*it;
    this->_sizeH->hide();
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
    QImage image(720 , 480, QImage::Format_ARGB32);

   // image.fill(QColor(255, 0, 0));

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}





void MainWindow::on_label_linkActivated(const QString &link)
{

}


void MainWindow::on_actionOpen_File_triggered()
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


void MainWindow::on_actionSave_triggered()
{
     QString fileName = QFileDialog::getSaveFileName(this,  tr("Open Image"), "c:/", tr("Image Files (*.png *.jpg *.bmp)"));

    QImage image = ui->label->pixmap().toImage();

    // Сохраните изображение в формате PNG
    if (image.save(fileName, "PNG")) {
        qDebug() << "Изображение успешно сохранено в output.png";
    }
    else if (image.isNull()) {
        qDebug() << "Изображение пустое.";
    }
}


void MainWindow::on_actionChange_of_size_triggered()
{


}


void MainWindow::on_action3_4_triggered()
{
    ui->label->setFixedSize(720,540);
    ui->label->show();
}



void MainWindow::on_action5_4_triggered()
{
    ui->label->setFixedSize(680,540);
    ui->label->show();
}


void MainWindow::on_action2_3_triggered()
{
    ui->label->setFixedSize(800,540);
    ui->label->show();
}


void MainWindow::on_actionCuo_off_triggered()
{
    this->_sizeW->show();
    this->_sizeH->show();
}

