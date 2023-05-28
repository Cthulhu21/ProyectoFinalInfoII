#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "ObjetoEstatico.h"

enum Color
{
    Negra,
    Blanca
};

class Plataforma: public ObjetoEstatico
{
    Q_OBJECT
public:
    Plataforma(Color Color_, QPointF Pos, QPointF Size, float Rotacion=0, QGraphicsItem *parent=nullptr);
    ~Plataforma();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;;
private:

    Color ColorPlataforma;
    void CargarSprite();

};

#endif // PLATAFORMA_H
