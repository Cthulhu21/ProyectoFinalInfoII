#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, QPointF Vel,
                  QPointF Acel, float VelMax, float Fric, QGraphicsItem *parent)
                :ObjetoMovible(TipoDeObjeto::Controlable, Masa, Pos, Vel, Acel, VelMax, Fric,parent )
{
    Pistola = new Arma();
    Jugador::SetPos(Pos);
}

Jugador::Jugador()
{

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
    Pos.setX(Pos.x()+20);
    Pos.setY(Pos.y()+10);
    Pistola->SetPos(Pos);
    RotarArma();
}

void Jugador::AgregarArma(QGraphicsScene *Pantalla)
{
    Pantalla->addItem(Pistola);
}

void Jugador::Disparar(QGraphicsScene *Escena)
{
    Pistola->CrearZona(Escena);
}

void Jugador::DispararObjeto()
{
    if(!Pistola->MoviblePegado)
        return;
    ObjetoMovible *Objeto = Pistola ->getObjetoPegado();
    int Rotacion=Pistola->rotation();
    int VelocidadDisparo=200;
    Objeto->Velocidad->setX(Velocidad->x()+VelocidadDisparo*cos(Rotacion*M_PI/180));
    Objeto->Velocidad->setY(Velocidad->y()+VelocidadDisparo*sin(Rotacion*M_PI/180));
    Objeto->ObjetoPegado=false;
    Pistola->MoviblePegado=false;
}

void Jugador::RotarArma()
{
    //QGraphicsView::mouseMoveEvent(event);

    QPointF mousePos = QCursor::pos();

    // Calcular la dirección del mouse con respecto al arma
    QPointF direction = mousePos - Pistola->pos()-QPointF(10,50);

    // Calcular el ángulo de rotación en radianes
    qreal angle = std::atan2(direction.y(), direction.x());

    // Convertir el ángulo a grados
    qreal rotation = qRadiansToDegrees(angle);

    // Rotar el arma
    Pistola->Rotar(rotation);
}
