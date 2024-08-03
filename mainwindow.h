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

private:
    Ui::MainWindow *ui;

    QSpinBox* _sizeW;

    QSpinBox* _sizeH;
};
#endif // MAINWINDOW_H
