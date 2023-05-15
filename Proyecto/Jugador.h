#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsScene>
#include <QList>
#include <math.h>

#include "ObjetoMovible.h"
#include "Arma.h"

class Jugador: public ObjetoMovible
{
    Q_OBJECT
public:
    Jugador(int Masa, QPointF Pos={0,0}, std::pair<float,float> Vel={0,0},
            std::pair<float,float> Acel={0,0}, float VelMax=300, float Fric=0.95, QGraphicsItem *parent=nullptr);
    void AgregarArma(QGraphicsScene *Pantalla);

    Arma *getPistola() const;
    void setPosPistola(float x, float y);
    void SetPos(QPointF Pos) override;

    ~Jugador();

private:

    Arma *Pistola;
};

#endif // JUGADOR_H
