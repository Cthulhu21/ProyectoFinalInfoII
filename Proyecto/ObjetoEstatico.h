#ifndef OBJETOESTATICO_H
#define OBJETOESTATICO_H

#include <QGraphicsPixmapItem>

class ObjetoEstatico: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ObjetoEstatico(QPointF Pos, QPointF Size, float Rotacion, QGraphicsItem *parent = nullptr);
    float Angulo;
    QPointF Size;
    QPixmap *Imagen;
    QRectF *Borde;
};

#endif // OBJETOESTATICO_H
