#include "Jugador.h"

Jugador::Jugador(int Masa, QPointF Pos, QPointF Vel,
                  QPointF Acel, float VelMax, float Fric, QGraphicsItem *parent)
                :ObjetoMovible(TipoDeObjeto::Controlable, Masa, Pos, Vel, Acel, VelMax, Fric,parent )
{
    Pistola = new Arma();
    Jugador::SetPos(Pos);
    Saltando=false;
    VelocidadMovimiento=50;
    Vida=100;
    BarraVida = nullptr;
    Invulnerable=0;
    MostrarBarra();
}

Jugador::Jugador()
{

}

Jugador::~Jugador()
{

}

Arma *Jugador::getPistola() const
{
    return Pistola;
}

void Jugador::SetPos(QPointF Pos)
{
    ObjetoMovible::SetPos(Pos);
    Pos.setX(Pos.x()+20);
    Pos.setY(Pos.y()+10);
    Pistola->SetPos(Pos);
    RotarArma();
}

void Jugador::SiguienteFrame(QGraphicsScene *Escenario)
{
    ObjetoMovible::SiguienteFrame();
    DifusionBarra(Escenario);
}

void Jugador::AgregarArma(QGraphicsScene *Pantalla)
{
    Pantalla->addItem(Pistola);
}

void Jugador::Disparar(QGraphicsScene *Escena)
{
    Pistola->CrearZona(Escena);
}

void Jugador::DispararObjeto()
{
    if(!Pistola->MoviblePegado)
        return;
    ObjetoMovible *Objeto = Pistola ->getObjetoPegado();
    int Rotacion=Pistola->rotation();
    int VelocidadDisparo=200;
    Objeto->Velocidad->setX(Velocidad->x()+VelocidadDisparo*cos(Rotacion*M_PI/180));
    Objeto->Velocidad->setY(Velocidad->y()+VelocidadDisparo*sin(Rotacion*M_PI/180));
    Objeto->ObjetoPegado=false;
    Pistola->MoviblePegado=false;
    Invulnerable=5;
}

void Jugador::RotarArma()
{
    QPointF mousePos = QCursor::pos();

    // Calcular la dirección del mouse con respecto al arma
    QPointF direction = mousePos - Pistola->pos() - QPointF{225,125};//QPointF(10,50);

    // Calcular el ángulo de rotación en radianes
    qreal angle = std::atan2(direction.y(), direction.x());

    // Convertir el ángulo a grados
    qreal rotation = qRadiansToDegrees(angle);

    // Rotar el arma
    Pistola->Rotar(rotation);
}

void Jugador::Herir(qreal Damage)
{
    Vida-=Damage;
}

void Jugador::DifusionBarra(QGraphicsScene *Escena)
{
    if(!BarraVida)
        return;
    if(!boolBarra)
        return;

    float Coeficiente=float(ContadorBarra)/5;
    BarraVida->setOpacity(Coeficiente);
    ContadorBarra-=1;
    ContadorBarra%=6;
    if(ContadorBarra!=-1)
        return;

    boolBarra=false;
    Escena->removeItem(BarraVida);
    delete BarraVida;
    BarraVida=nullptr;
}

void Jugador::MostrarBarra()
{
    if(BarraVida==nullptr)
    {
        if(Vida>0)
        {
            BarraVida = new QGraphicsRectItem(-Vida/2+20,-10,Vida,10,this);
            BarraVida->setBrush(QBrush(Qt::red));
            boolBarra=true;
            ContadorBarra=5;
        }
    }
    else
    {
        boolBarra=true;
        ContadorBarra=5;
    }
}

int Jugador::getVida() const
{
    return Vida;
}
