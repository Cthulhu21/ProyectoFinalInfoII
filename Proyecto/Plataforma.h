#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "ObjetoEstatico.h"

enum Color
{
    Negra,
    Blanca
};

class Plataforma: public ObjetoEstatico
{
    Q_OBJECT
public:
    Plataforma(Color Color_, QPointF Pos, QPointF Size, float Rotacion=0, QGraphicsItem *parent=nullptr);
    ~Plataforma();

    QList<QPointF> *Ruta;
    unsigned int NumeroRutaActual;

    void AgregarRutas(QList<QPointF>, qreal Velocidad_);
    void SiguientePos(qreal Delta);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;;

    QPointF getRutaActual() const;

    qreal getVelocidad() const;

    bool getConRuta() const;

private:

    Color ColorPlataforma;
    QPointF RutaActual;
    QPointF PosicionInicial;

    qreal Distancia;

    qreal Velocidad;
    bool ConRuta;

    void CargarSprite();

};

#endif // PLATAFORMA_H
