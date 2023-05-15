#ifndef ARMA_H
#define ARMA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Arma: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arma();
private:
    void CargarSprite();
};

#endif // ARMA_H
