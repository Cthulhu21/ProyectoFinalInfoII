#include "ZonaGravitacional.h"

ZonaGravitacional::ZonaGravitacional(int Fuerza, float Rotacion_, float DireccionFuerza_, QPointF Pos, QPointF Size_, float Opacidad, TipoDeZona Tipo, QGraphicsItem *parent)
{


    FuerzaGravitacional=Fuerza;
    Rotacion=Rotacion_;
    DireccionFuerza=DireccionFuerza_;
    Size = new QPointF(Size_);

    setPos(Pos);
    setOpacity(Opacidad);
    setTransformOriginPoint(Pos);
    setRotation(Rotacion);

    ZonaTipo=Tipo;
}

ZonaGravitacional::~ZonaGravitacional()
{

}

int ZonaGravitacional::getFuerzaGravitacional() const
{
    return FuerzaGravitacional;
}

QPointF *ZonaGravitacional::getSize() const
{
    return Size;
}
