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
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        AgregarParedes();

        ZonasGravitacionales->append(new ZonaRadial({700,700}, 1000, ZonaRadial::Interaccion::Repulsivo, 150, 0.5));
        ZonasGravitacionales->append(new ZonaRadial({1200,300}, 950, ZonaRadial::Interaccion::Atractivo, 200, 0.5));


        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1400, 400), QPointF(500, 20))); //Pared de bloqueo 1

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{500,900}));

        AgregarElementos();


        ZonaDeMeta = new QGraphicsRectItem(1820,10,75,390);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({25,900});
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    case 2:

        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        AgregarParedes();

        ZonasGravitacionales->append(new ZonaRecta({300,0},{200,700}, 300,0, -90, 0.3));
        ZonasGravitacionales->append(new ZonaRecta({600,0},{200,700},300,0,-90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({900,0},{200,700},300,0,90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({1200,0},{200,700},300,0,90,0.3));

        ZonasGravitacionales->append(new ZonaRadial({500,650},1800, ZonaRadial::Interaccion::Repulsivo, 200, 0.5));
        ZonasGravitacionales->append(new ZonaRadial({0,250},4000, ZonaRadial::Interaccion::Repulsivo, 200, 0.5));
        ZonasGravitacionales->append(new ZonaRadial({1100,0},300, ZonaRadial::Interaccion::Atractivo, 200, 0.7));

        Plataformas->append(new Plataforma(Color::Negra, QPointF(20, 550), QPointF(100, 20)));
        Plataformas->append(new Plataforma(Color::Negra, QPointF(300, 700), QPointF(100, 500)));

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{20,925}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(1490,935,400,50);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({50,925});
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    case 3:

        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        ZonasGravitacionales->append(new ZonaRecta({500,10},{200,1100},3000,0,180,0.3));
        ZonasGravitacionales->append(new ZonaRecta({20,10},{200,500},40000,0,0,0.3));

        AgregarParedes();

        Plataformas->append(new Plataforma(Color::Negra, QPointF(1490, 10), QPointF(20, 1000)));
        Plataformas->append(new Plataforma(Color::Negra, QPointF(1490, 600), QPointF(20, 800)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(0, 500), QPointF(300, 20)));

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,5,{1490,550}));
        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{150,850}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(1550,10,340,SizePantalla.y()-30);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);


        Player->SetPos({20,850});
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    case 4:
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        ZonasGravitacionales->append(new ZonaRecta({20,500},{800,100},10000,0,90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({1090,500},{800,100},10000,0,90,0.3));

        ZonasGravitacionales->append(new ZonaRecta({20,400},{600,100},25000,0,-45,0.3));
        ZonasGravitacionales->append(new ZonaRecta({1290,400},{600,100},25000,0,-135,0.3));

        ZonasGravitacionales->append(new ZonaRadial({955,450},2000, ZonaRadial::Interaccion::Atractivo, 100, 0.7)); //335

        Plataformas->append(new Plataforma(Color::Blanca, QPointF(620, 200), QPointF(670, 20)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(620, 300), QPointF(20, 200)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1270, 300), QPointF(20, 200)));

        AgregarParedes();

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{150,850}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(690,190,530,10);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);


        Player->SetPos({750,850});
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
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

void Mapa::AgregarParedes()
{
    Plataformas->append(new Plataforma(Color::Negra, QPointF(0, 0), QPointF(SizePantalla.x(), 20))); // Pared superior
    Plataformas->append(new Plataforma(Color::Negra, QPointF(SizePantalla.x()-20, 0), QPointF(20, 2000))); // Pared derecha
    Plataformas->append(new Plataforma(Color::Negra, QPointF(0, SizePantalla.y() - 20), QPointF(SizePantalla.x(),20))); // Pared inferior
    Plataformas->append(new Plataforma(Color::Negra, QPointF(0, 0), QPointF(20, 2000))); // Pared izquierda
}

void Mapa::AgregarElementos()
{
    for(int i=0; i<Plataformas->size(); i++)
    {
        Escenario->addItem(Plataformas->at(i));
    }
    for(int i=0; i<ZonasGravitacionales->size(); i++)
    {
        Escenario->addItem(ZonasGravitacionales->at(i));
    }
    for(int i=0; i<ObjetosMovibles->size(); i++)
    {
        Escenario->addItem(ObjetosMovibles->at(i));
    }
}
