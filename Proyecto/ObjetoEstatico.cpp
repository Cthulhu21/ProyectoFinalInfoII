#include "ObjetoEstatico.h"

ObjetoEstatico::ObjetoEstatico(QPointF Pos, QPointF Size_,float Rotacion , QGraphicsItem *parent)
{
    setPos(Pos);

    Size=Size_;

    Angulo=Rotacion;

    Imagen = new QPixmap;
}

QRectF ObjetoEstatico::boundingRect() const
{
    return QRectF(QPointF(), Size);
}

void ObjetoEstatico::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(0,0,*Imagen);
}
