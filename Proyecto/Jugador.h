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
    float getPosX() const;
    float getPosY() const;
    QGraphicsRectItem *getRectangulo() const;

private:

    const int Velocidad=25;
    const float Delta=0.01;
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
