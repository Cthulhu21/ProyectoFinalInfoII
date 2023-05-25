#ifndef OBJETOMOVIBLE_H
#define OBJETOMOVIBLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

class ObjetoMovible:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ObjetoMovible(int Masa_=10, QPointF Pos={0,0}, QPointF  Size_={10,10},QPointF Vel={0,0}, QPointF Acel={0,0}, float VelMax=300, float Fric=0.95, QGraphicsItem *parent=nullptr);
    ~ObjetoMovible();

    QPointF *Posicion;
    QPointF *Velocidad;
    QPointF *Aceleracion;
    bool ObjetoPegado;
    QPointF *Size;
    QList<QPixmap*> *Sprites;

    virtual void SetPos(QPointF Pos);
    void SiguienteFrame();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;

    int getMasa() const;

private:
    int Masa;
    float VelocidadMax;
    float Friccion;
    unsigned int FrameActual;

    virtual void CargarSprites();

};

#endif // OBJETOMOVIBLE_H
