#ifndef PAREDES_H
#define PAREDES_H

#include <QGraphicsPixmapItem>

class Paredes: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Paredes();
    ~Paredes();
};

#endif // PAREDES_H
