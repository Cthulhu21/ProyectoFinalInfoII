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
    void AplicarAceleracion(float AceleracionX_, float AceleracionY_);
    void Mover();

    void SetPos(float X, float Y);
    void SiguienteFrame();

    float getPosX() const;
    float getPosY() const;
    QGraphicsRectItem *getRectangulo() const;
    ~Jugador();

private:
    const int Velocidad=30;
    const float Delta=0.1;
    const float KAire=0.95;
    const int Masa=10;
    const int Gravedad=1000;

    float VelocidadInicialY;
    float PosicionInicialY;

    float C1, C2;
    float AceleracionX;
    float AceleracionY;
    float VelocidadX;
    float VelocidadY;
    float PosX;
    float PosY;
    int Direccion;


    unsigned int FrameActual;
    QList<QPixmap> Sprites;
    void CargarSprites();
    QGraphicsRectItem *Rectangulo;


};

#endif // JUGADOR_H
