#include "scene.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>

#include "geomitem.h"

Scene::Scene(QObject* parent) : QGraphicsScene(parent)
{

}

Scene::~Scene()
{

}

void Scene::changeParams(float radius, int numberOfLines, QColor linesColor)
{
    this->radius = radius;
    this->numberOfLines = numberOfLines;
    this->linesColor = linesColor;
    update();
}



void Scene::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
    switch (event->key()) {

    case 43:
        numberOfLines++;
        break;
    case 45:
        if (numberOfLines > 0)
        {
            numberOfLines--;
        }
        break;
    default:
        break;
    }

    for (QGraphicsItem* item : this->items())
    {
        ((GeomItem*)item)->changeParams(radius, numberOfLines, linesColor);
    }
    update();
}
