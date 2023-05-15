#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <math.h>

class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(float PosX_, float PosY_, QGraphicsItem *parent = NULL);

    void CambiarDireccion(int Tecla);
    void AumentarVelocidad(float VelX=0, float VelY=0);
    void setAceleracion(float AcelX=0, float AcelY=0);
    void SetPos(float X, float Y);
    void SiguienteFrame();

    float AceleracionX;
    float AceleracionY;
    float VelocidadX;
    float VelocidadY;
    float PosX;
    float PosY;

    QGraphicsRectItem *getRectangulo() const;
    ~Jugador();

    int getMasa() const;

private:
    const float Delta=0.01;
    const float KAire=0.95;
    const int Masa=10;
    const int VelMax=100;
    const int AceleracionMaxima=10000;

    int Direccion;



    unsigned int FrameActual;
    QList<QPixmap> Sprites;
    void CargarSprites();
    QGraphicsRectItem *Rectangulo;
};

#endif // JUGADOR_H
