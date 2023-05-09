#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsPixmapItem>
#include <QList>

class Jugador:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jugador(float PosX_, float PosY_, QGraphicsItem *parent = NULL);
    void AplicarMovimiento();
    void CambiarDireccion(int Tecla);
    void SetPos(float X, float Y);
    void SiguienteFrame();
    float getPosX() const;
    float getPosY() const;
    QGraphicsRectItem *getRectangulo() const;
    ~Jugador();
    bool getInvencible() const;
    void setInvencible(bool newInvencible);

private:
    bool Invencible;
    const int Velocidad=30;
    const float Delta=0.1;
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
