#ifndef OBJETOESTATICO_H
#define OBJETOESTATICO_H

#include <QGraphicsPixmapItem>

class ObjetoEstatico: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ObjetoEstatico(QPointF Pos, QPointF Size, float Rotacion=0, QGraphicsItem *parent = nullptr);
    float Angulo;
    QPointF Size;
    QPixmap *Imagen;
};

#endif // OBJETOESTATICO_H
