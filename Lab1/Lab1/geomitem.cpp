#include "geomitem.h"

#include <QPainter>
#include <QtMath>
#include <QDebug>

GeomItem::GeomItem(float xPos, float yPos,
                   float radius, int numberOfLines, QColor linesColor)
{
    this->xPos = xPos;
    this->yPos = yPos;
    this->radius = radius;
    this->numberOfLines = numberOfLines;
    this->linesColor = linesColor;
}

GeomItem::~GeomItem()
{

}



QRectF GeomItem::boundingRect() const
{
    QRectF rect(QPointF(-radius - 1, -radius - 1), QSizeF(2 * radius + 1, 2 * radius + 1));
    return rect;
}

void GeomItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush;
    brush.setColor(this->linesColor);
    painter->setBrush(brush);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(this->linesColor);
    painter->setPen(pen);

    for (int i = 0; i < 2 * numberOfLines; ++i)
    {
        float x = xPos + radius * qSin((float)i * M_PI / (numberOfLines));
        float y = yPos + radius * qCos((float)i * M_PI / (numberOfLines));

        QLineF line(QPointF(xPos, yPos), QPointF(x, y));
        painter->drawLine(line);
    }


}

void GeomItem::changeParams(float radius, int numberOfLines, QColor linesColor)
{   
    this->radius = radius;
    this->numberOfLines = numberOfLines;
    this->linesColor = linesColor;
}

void GeomItem::changePosition(float xPos, float yPos)
{
    this->xPos = xPos;
    this->yPos = yPos;
}
