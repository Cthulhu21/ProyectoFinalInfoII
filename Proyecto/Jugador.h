#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>
#include <QList>

class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(QGraphicsItem *parent = NULL);
    void AplicarMovimiento();
    void CambiarDireccion(int Tecla);
    void SetPos(float X, float Y);
    void SiguienteFrame();
    ~Jugador();
private:

    float VelocidadX;
    float VelocidadY;
    float Delta;
    float PosX;
    float PosY;
    int Direccion;

    unsigned int FrameActual;
    QList<QPixmap> Sprites;
    void CargarSprites();
};

#endif // JUGADOR_H
