#include "Plataforma.h"

Plataforma::Plataforma(Color Color_, QPointF Pos, QPointF Size, float Rotacion, QGraphicsItem *parent):
    ObjetoEstatico( Pos, Size, Rotacion, parent)
{
    ColorPlataforma=Color_;

    CargarSprite();

    Ruta = new QList<QPointF>;
    Velocidad = 0;
    ConRuta=false;
    PosicionInicial=pos();
}

Plataforma::~Plataforma()
{
    delete Ruta;
}

void Plataforma::AgregarRutas(QList<QPointF> Ruta_, qreal Velocidad_)
{

    //Mínimo 2 rutas
    if (Ruta_.size()<2)
        return;
    Velocidad=Velocidad_;
    Ruta= new QList<QPointF>(Ruta_);
    RutaActual =  Ruta->at(0);
    ConRuta=true;
    NumeroRutaActual=0;
    Distancia=INFINITY;
}

void Plataforma::SiguientePos(qreal Delta, QPointF *Cambio)
{
    if(!ConRuta)
        return;
    Delta*=0.1;
    QPointF PosActual = pos();
    QPointF PosFinal =PosicionInicial + RutaActual;
    QPointF SiguientePos = PosActual + RutaActual*Delta*Velocidad;
    qreal DistanciaMovimiento = sqrt(QPointF::dotProduct(PosFinal-SiguientePos,PosFinal-SiguientePos));
    if(Distancia>DistanciaMovimiento)
    {
        setPos(SiguientePos);
        Distancia=DistanciaMovimiento;
    }
    else
    {
        setPos(PosFinal);
        ++NumeroRutaActual%=Ruta->size();
        RutaActual=Ruta->at(NumeroRutaActual);

        PosicionInicial=pos();
        Distancia=INFINITY;
    }
    *Cambio=RutaActual*Delta*Velocidad;;
    /*
    if(PosActual!=PosFinal)
        setPos(SiguientePos);
    if(PosicionInicial)
    if(std::abs(PosActual.x())>std::abs(PosFinal.x()))
    {
        setX(PosFinal.x());
        NumeroRutaActual+=1;
        RutaActual=Ruta->at(NumeroRutaActual);
        NumeroRutaActual%=Ruta->size();
        PosicionInicial=pos();
    }
    else if(std::abs(PosActual.y())>std::abs(PosFinal.y()))
    {
        setY(PosFinal.y());
        NumeroRutaActual+=1;
        RutaActual=Ruta->at(NumeroRutaActual);
        NumeroRutaActual%=Ruta->size();
        PosicionInicial=pos();
    }*/
}

QRectF Plataforma::boundingRect() const
{
    QRectF Retorno(0,0, Size.x(), Size.y());
    QTransform Transformacion = QTransform().rotate(Angulo);
    return Transformacion.mapRect(Retorno);;
}

void Plataforma::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setPixmap(*Imagen);
    painter->drawPixmap(QPointF(), *Imagen);
}

QPointF Plataforma::getRutaActual() const
{
    return RutaActual;
}

qreal Plataforma::getVelocidad() const
{
    return Velocidad;
}

bool Plataforma::getConRuta() const
{
    return ConRuta;
}

void Plataforma::CargarSprite()
{
    QString Nombre;
    switch(ColorPlataforma)
    {
    case Negra:
        Nombre=":/Plataformas/Negra";
        break;
    case Blanca:
        Nombre=":/Plataformas/Blanca";
        break;
    default:
        break;
    }
    *Imagen = QPixmap(Nombre);
    *Imagen = Imagen->scaled(QSize(Size.x(), Size.y()));
    *Imagen = Imagen->transformed(QTransform().rotate(Angulo));
}
