#include "Cubo.h"

Cubo::Cubo(QPointF Pos, QPointF Size, int Masa):
    ObjetoMovible(Masa, Pos, Size)
{

}

Cubo::~Cubo()
{
}

void Cubo::CargarSprites()
{
    QPixmap Imagen(":/Imagenes/Cubo");
    Imagen = Imagen.scaled(QSize(Size->x(), Size->y()));
    Sprites->append( new QPixmap(":/Imagenes/Cubo"));
}
