#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QImage>
#include <QColor>
#include <QPainter>
#include <QSpinBox>
#include <QPainter>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QMouseEvent>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_doubleSpinBox_valueChanged(double arg1);

    void on_actionNew_File_triggered();

    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_actionOpen_File_triggered();

    void on_actionSave_triggered();

    void on_actionChange_of_size_triggered();

    void on_action3_4_triggered();

    void on_action5_4_triggered();

    void on_action2_3_triggered();

    void on_actionCuo_off_triggered();



    void on_But_red_clicked();



    void on_actionBrush_triggered(bool checked);

    void on_But_green_clicked();

    void on_But_blue_clicked();

    void on_But_black_clicked();





    void on_spinBox_textChanged(const QString &arg1);



    void on_actionZoom_triggered(bool checked);

    void on_pushButton_Text_clicked();
    void mousePressEvent(QMouseEvent *event) override ;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void on_pushButton_Rectangle_clicked();



    void on_checkBox_2_clicked();

private:
    Ui::MainWindow *ui;

    QSpinBox* _SpinBox_Zoom;

    QSpinBox* _sizeW;

    QSpinBox* _sizeH;

    QSpinBox* _brush;

    QVector<QLine> lines; // Список всех нарисованных линий

    QLine currentLine;

    QString Path_directory;

    QPixmap _PixmapSave;

    QPoint _lastPoint;

    QPoint _textPoint;

    int _pixesHorizontally=720;
    int _pixelsVertical=480;

bool but=false;

protected:






};
#endif // MAINWINDOW_H
