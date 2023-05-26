#include "ZonaRecta.h"

ZonaRecta::ZonaRecta(QPointF Pos, QPointF Size, float Fuerza, float Rotacion, float DireccionFuerza, float Opacidad, bool Arma):
    ZonaGravitacional(Fuerza, Rotacion, DireccionFuerza, Pos, Size, Opacidad,TipoDeZona::Recta)
{
    setRect(0,0, Size.x(), Size.y());
    Imagen = new QPixmap(":/Flechas/Flecha");
    *Imagen = Imagen->scaled(25,25);
    setRotation(Rotacion);
    ZonaDeArma=Arma;
}

ZonaRecta::~ZonaRecta()
{

}

QRectF ZonaRecta::boundingRect() const
{
    return QRectF(QPointF(0,0), *getSize());
}

void ZonaRecta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPainterPath Camino;
    Camino.addRect(boundingRect());
    QBrush Patron(*Imagen);
    Patron.setTransform(QTransform::fromScale(1,1));
    if(ZonaDeArma)
        Patron.setTransform(QTransform().rotate(rotation()+180));
    else
        Patron.setTransform(QTransform().rotate(DireccionFuerza));
    painter->fillPath(Camino, Patron);
}
