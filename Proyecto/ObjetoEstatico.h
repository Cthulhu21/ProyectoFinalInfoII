#ifndef OBJETOESTATICO_H
#define OBJETOESTATICO_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class ObjetoEstatico: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ObjetoEstatico(QPointF Pos, QPointF Size, float Rotacion=0, QGraphicsItem *parent = nullptr);
    ~ObjetoEstatico();
    float Angulo;
    QPointF *Size;
    QPixmap *Imagen;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // OBJETOESTATICO_H
