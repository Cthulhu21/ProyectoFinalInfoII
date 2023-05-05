#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>

class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem *parent = NULL);
    void AplicarMovimiento();
    void CambiarDireccion(int Tecla);
private:
    float VelocidadX;
    float VelocidadY;
    float Angulo;
    float AceleracionX;
    float AceleracionY;
    float Delta;
    float VectorVelocidad;
    float PosX;
    float PosY;
    float Resistencia;
};

#endif // JUGADOR_H
