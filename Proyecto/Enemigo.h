#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QList>

class Enemigo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemigo(float PosX, float PosY, QGraphicsItem *parent = NULL);
    void Mover();
    void CambiarDireccion();
    void SetPos(float X, float Y);
    void SiguienteFrame();
    ~Enemigo();
    QGraphicsRectItem *getRectangulo() const;
    void setRectangulo(float X, float Y);

private:
    const float Velocidad=20;
    float VelocidadX;
    float VelocidadY;
    const float Delta =0.01;
    float PosX;
    float PosY;
    int Direccion;

    unsigned int FrameActual;
    QList<QPixmap> Sprites;
    void CargarSprites();
    QGraphicsRectItem *Rectangulo;
};

#endif // ENEMIGO_H
