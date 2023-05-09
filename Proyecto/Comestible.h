#ifndef COMESTIBLE_H
#define COMESTIBLE_H

#include <QGraphicsPixmapItem>

class Comestible: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Comestible(unsigned int Sprite, float PosX, float PosY);
    bool Fruta=false;
    ~Comestible();
};

#endif // COMESTIBLE_H
