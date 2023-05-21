#ifndef OBJETOMOVIBLE_H
#define OBJETOMOVIBLE_H

#include <QObject>
#include <QGraphicsPixmapItem>

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
    ~ObjetoMovible();

    QPointF *Posicion;
    QPointF *Velocidad;
    QPointF *Aceleracion;

    void AumentarVelocidad(float VelX, float VelY);
    void setAceleracion(float AcelX, float AcelY);
    virtual void SetPos(QPointF Pos);
    void SiguienteFrame();

    int getMasa() const;


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
