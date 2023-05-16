#include "Plataforma.h"

Plataforma::Plataforma(Color Color_, QPointF Pos, QPointF Size, float Rotacion, QGraphicsItem *parent):
    ObjetoEstatico( Pos, Size, Rotacion, parent)
{
    ColorPlataforma=Color_;

    CargarSprite();
}

void Plataforma::CargarSprite()
{
    QString Nombre;
    switch(ColorPlataforma)
    {
    case Negra:
        Nombre=":/Plataformas/Blanca";

        break;
    case Blanca:
        Nombre=":/Plataformas/Negra";
        break;
    default:
        break;
    }
    *Imagen = QPixmap(Nombre);
    *Imagen=Imagen->scaled(QSize(Size.x(),Size.y()),Qt::KeepAspectRatio);
    *Imagen=Imagen->transformed(QTransform().rotate(Angulo));
    setPixmap(*Imagen);

    *Borde =QRectF(x(),y(),Size.x(),Size.y());
}
