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

private:

    Color ColorPlataforma;
    void CargarSprite();
};

#endif // PLATAFORMA_H
