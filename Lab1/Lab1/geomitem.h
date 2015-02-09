#ifndef GEOMITEM_H
#define GEOMITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QColor>


class GeomItem : public QGraphicsItem, public QObject
{
public:
    GeomItem(float xPos, float yPos,
             float radius = 100.0f, int numberOfLines = 10, QColor linesColor = QColor(255, 0, 0));
    ~GeomItem();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setParameters(float xPos, float yPos, float radius, int numberOfLines, QColor linesColor);


private:
    float xPos, yPos;
    float radius;
    int numberOfLines;
    QColor linesColor;

};

#endif // GEOMITEM_H
