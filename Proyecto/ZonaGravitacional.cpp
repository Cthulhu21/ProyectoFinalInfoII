#include "ZonaGravitacional.h"


ZonaGravitacional::ZonaGravitacional(int Fuerza, float Direccion, QPointF Pos, float Largo, float Ancho,float Opacidad, QGraphicsItem *parent)
{
    setBrush(QBrush(QColor(Qt::magenta)));
    FuerzaGravitacional=Fuerza;
    Rotacion=Direccion;
    setRect(Pos.x(), Pos.y(),Largo, Ancho);
    setOpacity(Opacidad);
    setTransformOriginPoint(Pos.x(),Pos.y());
    setRotation(Rotacion);
    QPixmap Patron(":/Flechas/Flecha");
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

float ZonaGravitacional::getRotacion() const
{
    return Rotacion;
}

