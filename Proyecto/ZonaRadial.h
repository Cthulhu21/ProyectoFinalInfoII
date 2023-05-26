#ifndef ZONARADIAL_H
#define ZONARADIAL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include "ZonaGravitacional.h"

class ZonaRadial:public ZonaGravitacional
{
    Q_OBJECT
public:
    enum class Interaccion
    {
        Repulsivo,
        Atractivo
    };

    ZonaRadial(QPointF Posicion, float Fuerza_, Interaccion TipoRadial, float Radio_=50,float Opaciodad=0.1, QGraphicsObject *parent=nullptr);
    QRectF boundingRect() const override;
    Interaccion TipoDeInteraccion;

    float getRadio() const;
    QPointF getCentro();
private:
    //void CargarSprite() override;
    float Radio;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
    QPointF PuntaFlecha(float angle) const;
    QPointF PuntoFlecha(float angle) const;
    QPainterPath shape() const override;
};

#endif // ZONARADIAL_H
