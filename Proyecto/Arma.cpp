#include "Arma.h"

Arma::Arma()
{
    CargarSprite();
}

void Arma::CargarSprite()
{
    setPixmap(QPixmap(":/Armas/1").transformed(QTransform().scale(0.05,0.05)));
}
