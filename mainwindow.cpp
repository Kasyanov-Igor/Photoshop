#include "mainwindow.h"
#include "./ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto it = ui->centralwidget->children().begin();

     std::advance(it, 1);
    this->_SpinBox_Zoom = (QSpinBox*)*it;
    this->_SpinBox_Zoom->hide();

    std::advance(it, 1);

    this->_sizeW = (QSpinBox*)*it;
    this->_sizeW->hide();

    std::advance(it, 1);
    this->_sizeH = (QSpinBox*)*it;
    this->_sizeH->hide();

     std::advance(it,1);
    this->_brush=(QSpinBox*)*it;
    this->_brush->hide();



}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    this->_lastPoint = event->pos();
    this-> _textPoint = event->pos();

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPainter painter(&this->_PixmapSave);

    if (event->buttons() & Qt::LeftButton && ui->But_red->isChecked())
    {
        QPen line(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        if(ui->checkBox_2->isChecked())
        {

        }
        if(ui->checkBox_3->isChecked())
        {

        }

        painter.setPen(QPen(line));
        painter.drawLine(_lastPoint, event->pos());

    }
    if (event->buttons() & Qt::LeftButton && ui->But_green->isChecked())
    {

        painter.setPen(QPen(Qt::green, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(_lastPoint, event->pos());

    }
    if (event->buttons() & Qt::LeftButton && ui->But_blue->isChecked())
    {

        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(_lastPoint, event->pos());
    }
    if (event->buttons() & Qt::LeftButton && ui->But_black->isChecked())
    {

        painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(_lastPoint, event->pos());
    }
    //if (event->button() == Qt::LeftButton)
   // {
       //this-> _textPoint = event->pos();
   // }

    _lastPoint = event->pos();
    ui->label->setPixmap(this->_PixmapSave);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    this->_lastPoint = QPoint(); // Сброс точки
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

    image.fill(QColor(255, 255, 255));

    this-> _PixmapSave=QPixmap::fromImage(image);
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

   this-> _PixmapSave.load(str);
    QPixmap pix;

    pix.load(str);
    Path_directory=str;
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
    ui->label->setFixedSize(520,340);
    this->_PixmapSave.scaled(520,340);
}



void MainWindow::on_action5_4_triggered()
{

    ui->label->setFixedSize(480,340);
    this->_PixmapSave.scaled(480,340);
}


void MainWindow::on_action2_3_triggered()
{
    ui->label->setFixedSize(600,340);
    this->_PixmapSave.scaled(600,340);
}


void MainWindow::on_actionCuo_off_triggered()
{
    this->but=! this->but;
    qDebug() <<this->but;
    this->_sizeW->show();
    this->_sizeH->show();
    if(this->but==false)
    {

        this->_sizeW->hide();
        this->_sizeH->hide();
    }

}

void MainWindow::on_pushButton_clicked()
{
   // repaint(paintEvent());


}

void MainWindow::on_But_red_clicked()
{
    repaint();
}

void MainWindow::on_But_green_clicked()
{
    repaint();
}


void MainWindow::on_But_blue_clicked()
{
    repaint();
}


void MainWindow::on_But_black_clicked()
{
    repaint();
}



void MainWindow::on_actionBrush_triggered(bool checked)
{

 this->but=! this->but;
    qDebug() <<this->but;
 this->_brush->show();
 if(this->but==false)
    {
        this->_brush->hide();

    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{




    if(ui->But_red->isChecked())
    {



    }
    else if(ui->But_green->isChecked())
    {

    }
    else if(ui->But_blue->isChecked())
    {

    }
}



void MainWindow::on_spinBox_textChanged(const QString &arg1)
{



}




void MainWindow::on_actionZoom_triggered(bool checked)
{

    this->but=! this->but;
    qDebug() <<this->but;
    this->_SpinBox_Zoom->show();
    if(this->but==false)
    {
        this->_SpinBox_Zoom->hide();

    }
}


void MainWindow::on_pushButton_Text_clicked()
{
    QPainter painter(&this->_PixmapSave);


    QString text = QInputDialog::getText(this, "Ввод текста", "Введите ваш текст:", QLineEdit::Normal, "");


    painter.drawText(this->_textPoint, text); // Рисуем текст


    ui-> label->setPixmap(this->_PixmapSave);
}


void MainWindow::on_pushButton_Rectangle_clicked()
{
    QPainter painter(&this->_PixmapSave);
    painter.setPen(QPen(Qt::black, 2)); // Черный цвет, толщина 2 пикселя

    painter.drawRect(100, 100, 180, 80); // Рисуем прямоугольник
}





void MainWindow::on_checkBox_2_clicked()
{
     repaint();
}

