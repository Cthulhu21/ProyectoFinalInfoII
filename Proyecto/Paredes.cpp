#include "Paredes.h"

Paredes::Paredes()
{
    setPixmap(QPixmap(":/Imagenes/Laberinto").transformed(QTransform().scale(0.50,0.39)));
}

Paredes::~Paredes()
{

}
