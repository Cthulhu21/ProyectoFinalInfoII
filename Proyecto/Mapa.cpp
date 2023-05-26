#include "Mapa.h"

Mapa::Mapa(unsigned int ID_, QGraphicsScene *Escena, Jugador *Jugador_)
{
    ID=ID_;
    Escenario = Escena;
    Player = Jugador_;
    SizePantalla={GetSystemMetrics(SM_CXSCREEN)-10, GetSystemMetrics(SM_CYSCREEN)-75};

    CargarElementos();
}

Mapa::Mapa()
{

}

Mapa::~Mapa()
{
    delete PosicionInicialJugador;
    delete ObjetosMovibles;
    delete Plataformas;
    delete ZonasGravitacionales;
    delete ZonaDeMeta;
}

void Mapa::CargarElementos()
{
    ObjetosMovibles = new QList<ObjetoMovible*>;
    Plataformas = new QList<Plataforma*>;
    ZonasGravitacionales = new QList<ZonaGravitacional*>;
    switch (ID) {
    case 1:
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));

        ZonasGravitacionales->append(new ZonaRadial({700,700}, 1000, ZonaRadial::Interaccion::Repulsivo, 150, 0.3));
        ZonasGravitacionales->append(new ZonaRadial({1200,300}, 950, ZonaRadial::Interaccion::Atractivo, 200, 0.3));

        Plataformas->append(new Plataforma(Color::Negra, QPointF(0, 0), QPointF(SizePantalla.x(), 20))); // Pared superior
        Plataformas->append(new Plataforma(Color::Negra, QPointF(SizePantalla.x()-20, 0), QPointF(20, 2000))); // Pared derecha
        Plataformas->append(new Plataforma(Color::Negra, QPointF(0, SizePantalla.y() - 20), QPointF(SizePantalla.x(),20))); // Pared inferior
        Plataformas->append(new Plataforma(Color::Negra, QPointF(0, 0), QPointF(20, 2000))); // Pared izquierda

        Plataformas->append(new Plataforma(Color::Negra, QPointF(1400, 400), QPointF(500, 20))); //Pared de bloqueo 1


        for(int i=0; i<Plataformas->size(); i++)
        {
            Escenario->addItem(Plataformas->at(i));
        }
        for(int i=0; i<ZonasGravitacionales->size(); i++)
        {
            Escenario->addItem(ZonasGravitacionales->at(i));
        }

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{500,900}));
        for(int i=0; i<ObjetosMovibles->size(); i++)
        {
            Escenario->addItem(ObjetosMovibles->at(i));
        }

        ZonaDeMeta = new QGraphicsRectItem(1820,10,75,390);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({25,900});
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

unsigned int Mapa::getID() const
{
    return ID;
}

QGraphicsRectItem *Mapa::getZonaDeMeta() const
{
    return ZonaDeMeta;
}
