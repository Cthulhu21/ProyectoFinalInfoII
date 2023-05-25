#ifndef ZONAGRAVITACIONAL_H
#define ZONAGRAVITACIONAL_H

#include <QGraphicsRectItem>
#include <QBrush>

enum TipoDeZona
{
    Radial,
    Recta
};

class ZonaGravitacional:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ZonaGravitacional(int Fuerza, float Rotacion_=0, float DireccionFuerza_=0, QPointF Pos={0,0}, float Largo=0, float Ancho=0, float Opacidad=1, TipoDeZona Tipo=Recta, QGraphicsItem *parent=nullptr);
    ~ZonaGravitacional();
    int getFuerzaGravitacional() const;
    float DireccionFuerza;
    TipoDeZona ZonaTipo;


private:
    int FuerzaGravitacional;
    float Rotacion;
    virtual void CargarSprite();
};

#endif // ZONAGRAVITACIONAL_H
