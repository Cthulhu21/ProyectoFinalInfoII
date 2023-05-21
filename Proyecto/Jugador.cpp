#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, QPointF Vel,
                  QPointF Acel, float VelMax, float Fric, QGraphicsItem *parent)
                :ObjetoMovible(TipoDeObjeto::Controlable, Masa, Pos, Vel, Acel, VelMax, Fric,parent )
{
    Jugador::SetPos(Pos);
}

Jugador::~Jugador()
{

}
void Jugador::SetPos(QPointF Pos)
{
    ObjetoMovible::SetPos(Pos);
}
