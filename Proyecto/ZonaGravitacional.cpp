#include "ZonaGravitacional.h"

ZonaGravitacional::ZonaGravitacional(int Fuerza, float Rotacion_, float DireccionFuerza_, QPointF Pos, float Largo, float Ancho,float Opacidad, TipoDeZona Tipo, QGraphicsItem *parent)
{
    setBrush(QBrush(QColor(Qt::magenta)));

    FuerzaGravitacional=Fuerza;
    Rotacion=Rotacion_;
    DireccionFuerza=DireccionFuerza_;
    setRect(Pos.x(), Pos.y(),Largo, Ancho);

    setOpacity(Opacidad);
    setTransformOriginPoint(Pos);
    setRotation(Rotacion);

    ZonaTipo=Tipo;

    CargarSprite();

}

ZonaGravitacional::~ZonaGravitacional()
{

}

int ZonaGravitacional::getFuerzaGravitacional() const
{
    return FuerzaGravitacional;
}

void ZonaGravitacional::CargarSprite()
{
    QPixmap Patron= QPixmap(":/Flechas/Flecha").scaled(25,25);
    Patron =Patron.transformed(QTransform().rotate(DireccionFuerza));
    QBrush Brocha(Patron);
    setBrush(Brocha);
}
