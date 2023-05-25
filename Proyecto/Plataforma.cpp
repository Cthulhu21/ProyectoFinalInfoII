#include "Plataforma.h"

Plataforma::Plataforma(Color Color_, QPointF Pos, QPointF Size, float Rotacion, QGraphicsItem *parent):
    ObjetoEstatico( Pos, Size, Rotacion, parent)
{
    ColorPlataforma=Color_;

    CargarSprite();
}

Plataforma::~Plataforma()
{

}

void Plataforma::CargarSprite()
{
    QString Nombre;
    switch(ColorPlataforma)
    {
    case Negra:
        Nombre=":/Plataformas/Negra";
        break;
    case Blanca:
        Nombre=":/Plataformas/Blanca";
        break;
    default:
        break;
    }
    *Imagen = QPixmap(Nombre);
    QSize Escala={static_cast<int>(Size->x()),static_cast<int>(Size->y())};
    *Imagen=Imagen->scaled(Escala);
    setPixmap(*Imagen);
}
