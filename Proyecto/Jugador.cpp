#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, QPointF Vel,
                  QPointF Acel, float VelMax, float Fric, QGraphicsItem *parent)
                :ObjetoMovible(TipoDeObjeto::Controlable, Masa, Pos, Vel, Acel, VelMax, Fric,parent )
{
    Pistola = new Arma();
    Jugador::SetPos(Pos);
}

Jugador::~Jugador()
{

}

Arma *Jugador::getPistola() const
{
    return Pistola;
}

void Jugador::SetPos(QPointF Pos)
{
    ObjetoMovible::SetPos(Pos);
    Pos.setX(Pos.x()+15);
    Pos.setY(Pos.y()+10);
    Pistola->SetPos(Pos);
}

void Jugador::AgregarArma(QGraphicsScene *Pantalla)
{
    Pantalla->addItem(Pistola);
}

void Jugador::Disparar(QGraphicsScene *Escena)
{
    Pistola->CrearZona(Escena);
}
