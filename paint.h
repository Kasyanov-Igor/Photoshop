#ifndef PAINT_H
#define PAINT_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QVector>
#include <QLabel>

#include <QPixmap>
class DrawingLabel : public QLabel {
    Q_OBJECT

public:
    DrawingLabel(QWidget *parent = nullptr) : QLabel(parent) {
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue, 2)); // Синяя кисть толщиной 2 пикселя

        // Рисуем все линии
        for (int i = 0; i < lines.size(); ++i) {
            painter.drawLine(lines[i]);
        }
    }

    void mousePressEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            currentLine = QLine(event->pos(), event->pos()); // Создаем новую линию
            lines.append(currentLine); // Добавляем ее в список
            update(); // Перерисовываем виджет
        }
    }

    void mouseMoveEvent(QMouseEvent *event) {
        if (event->buttons() & Qt::LeftButton) {
            currentLine.setP2(event->pos()); // Обновляем конечную точку линии
            update(); // Перерисовываем виджет
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) {
        if (event->button() == Qt::LeftButton) {
            // Линия завершена
        }
    }

private:
    QVector<QLine> lines; // Список всех нарисованных линий
    QLine currentLine;   // Текущая линия, которая рисуется
};


#endif // PAINT_H
