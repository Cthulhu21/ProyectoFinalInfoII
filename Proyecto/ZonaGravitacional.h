#ifndef ZONAGRAVITACIONAL_H
#define ZONAGRAVITACIONAL_H

#include <QGraphicsRectItem>
#include <QBrush>

class ZonaGravitacional:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ZonaGravitacional(int Fuerza, float Rotacion_, float DireccionFuerza_, QPointF Pos, float Largo, float Ancho, float Opacidad=1, QGraphicsItem *parent=nullptr);
    ~ZonaGravitacional();
    int getFuerzaGravitacional() const;
    float DireccionFuerza;

private:
    int FuerzaGravitacional;
    float Rotacion;
};

#endif // ZONAGRAVITACIONAL_H
