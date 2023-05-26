#ifndef ARMA_H
#define ARMA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <math.h>
#include <QCursor>

#include "ObjetoMovible.h"
#include "ZonaRecta.h"

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
    ~Arma();
    Disparo TipoDeDisparo;
    bool Activa;
    bool MoviblePegado;

    void CrearZona(QGraphicsScene *Escena);
    void Rotar(qreal Angulo);
    void SetPos(QPointF Pos);

    ZonaRecta *getRangoArma() const;

    QPointF getSize() const;

    void setObjetoPegado(ObjetoMovible *newObjetoPegado);
    void MoverObjetoPegado();

private:
    void CargarSprite();
    ZonaRecta *RangoArma;
    QPointF Size;
    ObjetoMovible *ObjetoPegado;
};

#endif // ARMA_H
