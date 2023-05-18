#ifndef ARMA_H
#define ARMA_H

#include <QObject>
#include <QGraphicsPixmapItem>

enum Disparo
{
    Atractivo,
    Repulsivo
};

class Arma: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arma();
    ~Arma();
    Disparo TipoDeDisparo;

private:
    void CargarSprite();
};

#endif // ARMA_H
