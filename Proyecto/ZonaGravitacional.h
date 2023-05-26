#ifndef ZONAGRAVITACIONAL_H
#define ZONAGRAVITACIONAL_H

#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QPainter>

enum TipoDeZona
{
    Radial,
    Recta
};

class ZonaGravitacional:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ZonaGravitacional(int Fuerza, float Rotacion_=0, float DireccionFuerza_=0, QPointF Pos={0,0}, QPointF Size_={0,0}, float Opacidad=1, TipoDeZona Tipo=Recta, QGraphicsItem *parent=nullptr);
    ~ZonaGravitacional();

    int getFuerzaGravitacional() const;

    float DireccionFuerza;
    TipoDeZona ZonaTipo;
    QPixmap *Imagen;

    QPointF *getSize() const;

private:
    int FuerzaGravitacional;
    float Rotacion;
    QPointF *Size;
};

#endif // ZONAGRAVITACIONAL_H
