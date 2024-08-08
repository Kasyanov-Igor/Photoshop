#ifndef PAINT_H
#define PAINT_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QVector>

class paint : public QWidget {
    Q_OBJECT

public:
    paint(QWidget *parent = nullptr);

protected:
     void paintEvent(QPaintEvent *event) override;

     void Qpen();

    void mousePressEvent(QMouseEvent *event) ;

     void mouseMoveEvent(QMouseEvent *event);

     void mouseReleaseEvent(QMouseEvent *event);

private:
    QVector<QLine> lines; // Список всех нарисованных линий
    QLine currentLine;   // Текущая линия, которая рисуется
};

#endif // PAINT_H
