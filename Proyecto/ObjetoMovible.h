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
    ObjetoMovible(TipoDeObjeto Tipo,int Masa_=10, QPointF Pos={0,0},std::pair<float,float> Vel={0,0},std::pair<float,float> Acel={0,0}, float VelMax=300, float Fric=0.95, QGraphicsItem *parent=nullptr);
    std::pair<float,float> Velocidad;
    std::pair<float,float> Aceleracion;

    void AumentarVelocidad(float VelX, float VelY);
    void setAceleracion(float AcelX, float AcelY);
    virtual void SetPos(QPointF Pos);
    void SiguienteFrame();

    int getMasa() const;

    QRectF *getBordes() const;

private:

    TipoDeObjeto Tipo;
    int Masa;
    float VelocidadMax;
    float Friccion;


    int Size[2];

    QRectF *Bordes;

    QList<QPixmap> Sprites;
    void CargarSprites();
    unsigned int FrameActual;
};

#endif // OBJETOMOVIBLE_H
