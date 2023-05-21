#include "ZonaGravitacional.h"

ZonaGravitacional::ZonaGravitacional(int Fuerza, float Rotacion_, float DireccionFuerza_, QPointF Pos, float Largo, float Ancho,float Opacidad, QGraphicsItem *parent)
{
    setBrush(QBrush(QColor(Qt::magenta)));

    FuerzaGravitacional=Fuerza;
    Rotacion=Rotacion_;
    DireccionFuerza=DireccionFuerza_;
    setRect(Pos.x(), Pos.y(),Largo, Ancho);

    setOpacity(Opacidad);
    setTransformOriginPoint(Pos);
    setRotation(Rotacion);

    QPixmap Patron(":/Flechas/Flecha");
    Patron =Patron.transformed(QTransform().rotate(DireccionFuerza));
    QBrush Brocha(Patron);
    setBrush(Brocha);
}

ZonaGravitacional::~ZonaGravitacional()
{

}

int ZonaGravitacional::getFuerzaGravitacional() const
{
    return FuerzaGravitacional;
}

float ZonaGravitacional::getDireccionFuerza() const
{
    return DireccionFuerza;
}

