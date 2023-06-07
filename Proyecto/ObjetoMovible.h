#ifndef OBJETOMOVIBLE_H
#define OBJETOMOVIBLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

enum TipoDeObjeto
{
    Controlable,
    Cubo
};

class ObjetoMovible:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ObjetoMovible(TipoDeObjeto Tipo,int Masa_=10, QPointF Pos={0,0},QPointF Vel={0,0}, QPointF Acel={0,0}, float VelMax=300, float Fric=0.95, QGraphicsItem *parent=nullptr);
    ObjetoMovible(const ObjetoMovible &Otro);
    ObjetoMovible();
    ~ObjetoMovible();

    QPointF *Posicion;
    QPointF *Velocidad;
    QPointF *Aceleracion;
    bool ObjetoPegado;

    virtual void SetPos(QPointF Pos);
    virtual void SiguienteFrame(QGraphicsScene *Escenario=nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;

    int getMasa() const;
    TipoDeObjeto getTipo() const;

    QPointF *getSize() const;

private:

    TipoDeObjeto Tipo;
    int Masa;
    float VelocidadMax;
    float Friccion;


    QPointF *Size;

    QList<QPixmap> Sprites;
    void CargarSprites();
    unsigned int FrameActual;
};

#endif // OBJETOMOVIBLE_H
