#include "ObjetoEstatico.h"

ObjetoEstatico::ObjetoEstatico(QPointF Pos, QPointF Size_,float Rotacion , QGraphicsItem *parent)
{
    setPos(Pos);


    Size= new QPointF(Size_);

    Angulo=Rotacion;

    Imagen = new QPixmap;
}

ObjetoEstatico::~ObjetoEstatico()
{
    delete Size;
    delete Imagen;
}

QRectF ObjetoEstatico::boundingRect() const
{
    return QRectF(QPointF(), *Size);
}

void ObjetoEstatico::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QPointF(), *Imagen);
}
