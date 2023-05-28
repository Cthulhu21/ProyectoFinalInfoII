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

QRectF Plataforma::boundingRect() const
{
    QRectF Retorno(0,0, Size.x(), Size.y());
    QTransform Transformacion = QTransform().rotate(Angulo);
    return Transformacion.mapRect(Retorno);;
}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setPixmap(*Imagen);
    painter->drawPixmap(QPointF(), *Imagen);
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
    *Imagen = Imagen->scaled(QSize(Size.x(), Size.y()));
    *Imagen = Imagen->transformed(QTransform().rotate(Angulo));
}
