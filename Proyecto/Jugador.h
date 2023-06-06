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
    Jugador(int Masa, QPointF Pos={0,0},  QPointF Vel={0,0},
             QPointF Acel={0,0}, float VelMax=300, float Fric=0.95, QGraphicsItem *parent=nullptr);
    Jugador();
    ~Jugador();

    void AgregarArma(QGraphicsScene *Pantalla);
    Arma *getPistola() const;
    void SetPos(QPointF Pos) override;
    void SiguienteFrame() override;
    void Disparar(QGraphicsScene *Escena);
    void DispararObjeto();
    void RotarArma();

    void DifusionBarra();
    bool MostrarBarra;

    bool Saltando;
    float VelocidadMovimiento;

private:
    Arma *Pistola;
    QGraphicsRectItem *BarraVida;
    int ContadorBarra;

};

#endif // JUGADOR_H
