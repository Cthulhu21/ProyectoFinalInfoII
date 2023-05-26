#include "ZonaRecta.h"

ZonaRecta::ZonaRecta(QPointF Pos, QPointF Size, float Fuerza, float Rotacion, float DireccionFuerza, float Opacidad):
    ZonaGravitacional(Fuerza, Rotacion, DireccionFuerza, Pos, Size, Opacidad,TipoDeZona::Recta)
{
    setRect(Pos.x(), Pos.y(), Size.x(), Size.y());
    Imagen = new QPixmap(":/Flechas/Flecha");
    *Imagen = Imagen->scaled(25,25);
}

ZonaRecta::~ZonaRecta()
{

}

QRectF ZonaRecta::boundingRect() const
{
    return QRectF(QPointF(), *getSize());
}

void ZonaRecta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPainterPath Camino;
    Camino.addRect(boundingRect());
    QBrush Patron(*Imagen);
    Patron.setColor(Qt::magenta);
    Patron.setTransform(QTransform::fromScale(1,1));
    Patron.setTransform(QTransform().rotate(rotation()+180));
    painter->setBrush(Patron);
    painter->drawPath(Camino);
}
