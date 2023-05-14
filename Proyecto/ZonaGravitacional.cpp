#include "ZonaGravitacional.h"


ZonaGravitacional::ZonaGravitacional(int Fuerza, float Direccion, float X, float Y, float Largo, float Ancho,float Opacidad, QGraphicsItem *parent)
{
    setBrush(QBrush(QColor(Qt::magenta)));
    FuerzaGravitacional=Fuerza;
    Rotacion=Direccion;
    setRect(X,Y,Largo, Ancho);
    setOpacity(Opacidad);
    setRotation(Rotacion);
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
