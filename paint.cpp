#include "paint.h"


paint::paint(QWidget *parent) : QWidget(parent) {

}

void paint::paintEvent(QPaintEvent *event)  {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue, 2)); // Синяя кисть толщиной 2 пикселя


        for (int i = 0; i < lines.size(); ++i)
        {
            painter.drawLine(lines[i]);
        }
    }

void paint::Qpen()
{

}

void paint::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        currentLine = QLine(event->pos(), event->pos()); // Создаем новую линию
        lines.append(currentLine); // Добавляем ее в список
        update(); // Перерисовываем виджет
    }
}

void paint::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        currentLine.setP2(event->pos()); // Обновляем конечную точку линии
        update(); // Перерисовываем виджет
    }
}

void paint::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // Линия завершена
    }
}

