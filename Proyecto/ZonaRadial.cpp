#include "ZonaRadial.h"
#include "Arma.h"

ZonaRadial::ZonaRadial(QPointF Posicion, float Fuerza_, Interaccion TipoRadial_, float Radio_,float Opacidad, QGraphicsObject *parent):
    ZonaGravitacional(Fuerza_, 0, 90, Posicion, {0, 0}, Opacidad,TipoDeZona::Radial)
{
    setPos(Posicion);
    TipoDeInteraccion = TipoRadial_;
    Radio = Radio_;

    Imagen = new QPixmap(":/Flechas/Flecha");
    *Imagen = Imagen->scaled(25, 25);
    setBrush(*Imagen);

    QPainterPath Camino;
    Camino.addEllipse(QRectF(-Radio, -Radio, Radio * 2, Radio * 2));

    setCacheMode(QGraphicsPixmapItem::DeviceCoordinateCache);
    setScale(1);
}
QRectF ZonaRadial::boundingRect() const
{
    return QRectF(-Radio, -Radio, Radio*2, Radio*2);
}

float ZonaRadial::getRadio() const
{
    return Radio;
}

QPointF ZonaRadial::getCentro()
{
    return mapToScene(QPointF(0,0));
}

void ZonaRadial::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(TipoDeInteraccion==Interaccion::Atractivo)
    {
        QRadialGradient Gradiente(QPointF(0,0), Radio);
        Gradiente.setColorAt(0,Qt::magenta);
        Gradiente.setColorAt(1,Qt::transparent);
        painter->setBrush(Gradiente);
        painter->setPen(Qt::NoPen);
        painter->drawEllipse(boundingRect());
    }
    else
    {
        QRadialGradient Gradiente(QPointF(0,0), Radio);
        Gradiente.setColorAt(1,Qt::magenta);
        Gradiente.setColorAt(0,Qt::transparent);
        painter->setBrush(Gradiente);
        painter->setPen(Qt::NoPen);
        painter->drawEllipse(boundingRect());
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
    float x = Radio*0.1 * qCos(qDegreesToRadians(angle));
    float y = Radio*0.1 * qSin(qDegreesToRadians(angle));
    return QPointF(x, y);
}

QPainterPath ZonaRadial::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
