#ifndef ARMA_H
#define ARMA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <ZonaGravitacional.h>
#include <QGraphicsScene>
#include <math.h>

#define PI 3.14159265

enum Disparo
{
    Atractivo,
    Respulsivo
};

class Arma: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Arma();
    Disparo TipoDeDisparo;
    bool Activa;
    void CrearZona(QGraphicsScene *Escena);
    void Rotar(qreal Angulo);
    void SetPos(QPointF Pos);

    ZonaGravitacional *getRangoArma() const;

private:
    void CargarSprite();
    ZonaGravitacional *RangoArma;
};

#endif // ARMA_H
