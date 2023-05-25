#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, QPointF Vel,
                  QPointF Acel, float VelMax, float Fric, QGraphicsItem *parent)
    :ObjetoMovible(Masa, Pos, {30,35}, Vel, Acel, VelMax, Fric, parent )
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

void Jugador::CargarSprites()
{
    for(int i=3; i<4; i++)//11 para el sprite completo
    {
        QString Ruta=":/Jugador/%1";
        QPixmap *Map = new QPixmap((Ruta.arg(i)));;
        Sprites->append(new QPixmap(*Map));
    }
}
