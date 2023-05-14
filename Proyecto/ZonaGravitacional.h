#ifndef ZONAGRAVITACIONAL_H
#define ZONAGRAVITACIONAL_H

#include <QGraphicsRectItem>
#include <QBrush>

class ZonaGravitacional:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ZonaGravitacional(int Fuerza, float Dirección,float X, float Y, float Largo, float Ancho, float Opacidad=1, QGraphicsItem *parent=nullptr);
    ~ZonaGravitacional();
    int getFuerzaGravitacional() const;

    float getRotacion() const;

    private:
    int FuerzaGravitacional;
    float Rotacion;
};

#endif // ZONAGRAVITACIONAL_H
