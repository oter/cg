#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>


class Scene : public QGraphicsScene
{
public:
    Scene(QObject* parent = 0);
    ~Scene();

public:
    void changeParams(float radius, int numberOfLines, QColor linesColor);

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    float radius;
    int numberOfLines;
    QColor linesColor;
};

#endif // SCENE_H
