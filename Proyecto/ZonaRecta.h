#ifndef ZONARECTA_H
#define ZONARECTA_H

#include "ZonaGravitacional.h"

class ZonaRecta: public ZonaGravitacional
{
public:
    ZonaRecta(QPointF Pos, QPointF Size, float Fuerza, float Rotacion, float DireccionFuerza, float Opacidad=0);
    ~ZonaRecta();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // ZONARECTA_H
