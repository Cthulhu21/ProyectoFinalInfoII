#ifndef ZONARECTA_H
#define ZONARECTA_H

#include "ZonaGravitacional.h"

class ZonaRecta: public ZonaGravitacional
{
    Q_OBJECT
public:
    ZonaRecta(QPointF Pos, QPointF Size, float Fuerza, float Rotacion, float DireccionFuerza, float Opacidad=0, bool Arma=false);
    ~ZonaRecta();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    bool ZonaDeArma;
};

#endif // ZONARECTA_H
