#include "ZonaRadial.h"

ZonaRadial::ZonaRadial(QPointF Posicion, float Fuerza_, Interaccion TipoRadial_, float Radio_,float Opacidad, QGraphicsObject *parent):
    ZonaGravitacional(Fuerza_, 0, 90, Posicion, 0, 0, Opacidad,TipoDeZona::Radial)
{
    setPos(Posicion);
    TipoDeInteraccion = TipoRadial_;
    Radio = Radio_;
}

QRectF ZonaRadial::boundingRect() const
{
    return QRectF(-Radio, -Radio, Radio*2, Radio*2);
}

void ZonaRadial::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);
    unsigned int numFlechas=10;

    for (unsigned int i = 0; i < numFlechas; ++i)
    {
        float angle = i * (360.0 / numFlechas) ;
        QPointF arrowTip = PuntaFlecha(angle);
        QPointF arrowPoint1 = PuntoFlecha(angle + 30);
        QPointF arrowPoint2 = PuntoFlecha(angle - 30);

        QPen Flecha(Qt::magenta);
        Flecha.setWidth(5);
        painter->setPen(Flecha);
        painter->drawLine(QPointF(), arrowTip);
        painter->drawLine(arrowTip, arrowPoint1);
        painter->drawLine(arrowTip, arrowPoint2);
    }
}

QPointF ZonaRadial::PuntaFlecha(float angle) const
{
    float x = Radio * qCos(qDegreesToRadians(angle));
    float y = Radio * qSin(qDegreesToRadians(angle));
    return QPointF(x, y);
}

QPointF ZonaRadial::PuntoFlecha(float angle) const
{
    float x = Radio*0.8 * qCos(qDegreesToRadians(angle));
    float y = Radio*0.8 * qSin(qDegreesToRadians(angle));
    return QPointF(x, y);
}
