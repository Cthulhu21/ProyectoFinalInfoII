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
    void SetPos(float X, float Y);
    ~Jugador();
private:
    float VelocidadX;
    float VelocidadY;
    float Delta;
    float PosX;
    float PosY;
};

#endif // JUGADOR_H
