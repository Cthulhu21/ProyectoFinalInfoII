#include "ObjetoEstatico.h"

ObjetoEstatico::ObjetoEstatico(QPointF Pos, QPointF Size_,float Rotacion , QGraphicsItem *parent)
{
    setPos(Pos);

    Size=Size_;

    Angulo=Rotacion;

    Imagen = new QPixmap;
}
