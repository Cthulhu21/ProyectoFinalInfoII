#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>

class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem *parent = NULL);
};

#endif // JUGADOR_H
