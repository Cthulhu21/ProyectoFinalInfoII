#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QList>

class Enemigo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemigo();
    void Mover();
    void CambiarDireccion();
    void SetPos(float X, float Y);
    void SiguienteFrame();
    ~Enemigo();
    QGraphicsRectItem *getRectangulo() const;

private:
    const float Velocidad=20;
    float VelocidadX;
    float VelocidadY;
    float Delta;
    float PosX;
    float PosY;
    int Direccion;

    unsigned int FrameActual;
    QList<QPixmap> Sprites;
    void CargarSprites();
    QGraphicsRectItem *Rectangulo;
};

#endif // ENEMIGO_H
