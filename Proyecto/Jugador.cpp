#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, std::pair<float,float> Vel,
                 std::pair<float,float> Acel, float VelMax, float Fric, QGraphicsItem *parent)
                :ObjetoMovible(TipoDeObjeto::Controlable, Masa, Pos, Vel, Acel, VelMax, Fric,parent )
{
    Pistola = new Arma();
    Pistola->setPos(Pos.x()+15, Pos.y()+10);
    ObjetoMovible::SetPos(Pos);
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
    Pistola->setPos(Pos.x()+15,Pos.y()+10);
}


void Jugador::AgregarArma(QGraphicsScene *Pantalla)
{
    Pantalla->addItem(Pistola);
}
