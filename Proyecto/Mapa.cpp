#include "Mapa.h"

Mapa::Mapa(unsigned int ID_, QGraphicsScene *Escena, Jugador *Jugador_)
{
    ID=ID_;
    Escenario = Escena;
    Player = Jugador_;
    SizePantalla={1500, 800};

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
    {
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        AgregarParedes();

        ZonasGravitacionales->append(new ZonaRadial({600,500}, 1500, ZonaRadial::Interaccion::Repulsivo, 150, 0.5));
        ZonasGravitacionales->append(new ZonaRadial({1100,200}, 1200, ZonaRadial::Interaccion::Atractivo, 200, 0.5));


        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1200, 400), QPointF(280, 20))); //Pared de bloqueo 1

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{500,720}));

        AgregarElementos();


        ZonaDeMeta = new QGraphicsRectItem(SizePantalla.x()-75,10,75,390);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({50,720});
        Player->VelocidadMovimiento=50;
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    }
    case 2:
    {
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        AgregarParedes();

        ZonasGravitacionales->append(new ZonaRecta({300,0},{200,700}, 300,0, -90, 0.3));
        ZonasGravitacionales->append(new ZonaRecta({600,0},{200,700},300,0,-90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({900,0},{200,700},300,0,90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({1200,0},{200,700},300,0,90,0.3));

        ZonasGravitacionales->append(new ZonaRadial({500,350},1800, ZonaRadial::Interaccion::Repulsivo, 100, 0.5));
        ZonasGravitacionales->append(new ZonaRadial({120,250},4000, ZonaRadial::Interaccion::Repulsivo, 100, 0.5));
        //ZonasGravitacionales->append(new ZonaRadial({1100,0},300, ZonaRadial::Interaccion::Atractivo, 100, 0.7));

        Plataformas->append(new Plataforma(Color::Negra, QPointF(20, 450), QPointF(100, 20)));
        Plataformas->append(new Plataforma(Color::Negra, QPointF(300, 580), QPointF(20, 400)));

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{20,700}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(SizePantalla.x()-420,750,400,30);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({25,700});
        Player->VelocidadMovimiento=50;
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    }
    case 3:
    {
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        ZonasGravitacionales->append(new ZonaRecta({500,10},{200,1100},3000,0,180,0.3));
        ZonasGravitacionales->append(new ZonaRecta({20,10},{200,500},40000,0,0,0.3));

        AgregarParedes();

        Plataformas->append(new Plataforma(Color::Negra, QPointF(1100, 10), QPointF(20, 500)));
        Plataformas->append(new Plataforma(Color::Negra, QPointF(1100, 320), QPointF(20, 900)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(0, 500), QPointF(300, 20)));

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,50,{1100,270}));
        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{150,700}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(1175,10,340,SizePantalla.y()-30);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);


        Player->SetPos({20,700});
        Player->VelocidadMovimiento=50;
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    }
    case 4:
    {
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        ZonasGravitacionales->append(new ZonaRecta({20,500},{480,100},25000,0,90,0.3));
        ZonasGravitacionales->append(new ZonaRecta({920,500},{560,100},25000,0,90,0.3));

        ZonasGravitacionales->append(new ZonaRecta({20,400},{480,100},25000,0,-45,0.3));
        ZonasGravitacionales->append(new ZonaRecta({920,400},{560,100},25000,0,-135,0.3));

        ZonasGravitacionales->append(new ZonaRadial({700,450},2000, ZonaRadial::Interaccion::Atractivo, 200, 0.7)); //335

        Plataformas->append(new Plataforma(Color::Blanca, QPointF(500, 200), QPointF(400, 20)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(500, 300), QPointF(20, 200)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(900, 300), QPointF(20, 200)));

        AgregarParedes();

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{250,700}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(520,190,360,10);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);


        Player->SetPos({25,700});
        Player->VelocidadMovimiento=50;
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    }
    case 5:
    {
        ZonasGravitacionales->append(new ZonaRecta({-500,-500},{3000,3000},100,0,90));//Gravedad

        ZonasGravitacionales->append(new ZonaRecta({100,600},{1380,180},2500,0,180,0.3));
        ZonasGravitacionales->append(new ZonaRecta({20,320},{80,480},1000,0,-90,0.3));

        ZonasGravitacionales->append(new ZonaRadial({1380,120},2000, ZonaRadial::Interaccion::Atractivo, 120, 0.7)); //335

        AgregarParedes();

        Plataformas->append(new Plataforma(Color::Blanca, QPointF(100, 300), QPointF(100, 20)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1260, 160), QPointF(100, 20)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1260, 180), QPointF(20, 150)));
        Plataformas->append(new Plataforma(Color::Blanca, QPointF(1260, 330), QPointF(100, 20)));

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{250,900}));

        QList<QPointF> Ruta={{0,200},{0,-200}};
        Plataformas->append(new Plataforma(Color::Negra, {250,300},{100,20}));
        Plataformas->back()->AgregarRutas(Ruta, 0.1);
        Plataformas->append(new Plataforma(Color::Negra, {450,300},{100,20}));
        Plataformas->back()->AgregarRutas(Ruta, 0.1);
        Plataformas->append(new Plataforma(Color::Negra, {650,300},{100,20}));
        Plataformas->back()->AgregarRutas(Ruta, 0.1);
        Plataformas->append(new Plataforma(Color::Negra, {850,300},{100,20}));
        Plataformas->back()->AgregarRutas(Ruta, 0.1);
        Plataformas->append(new Plataforma(Color::Negra, {1050,300},{100,20}));
        Plataformas->back()->AgregarRutas(Ruta, 0.1);

        ObjetosMovibles->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{140,245}));

        AgregarElementos();

        ZonaDeMeta = new QGraphicsRectItem(1280,180,20,150);
        ZonaDeMeta->setBrush(QBrush(Qt::green));
        Escenario->addItem(ZonaDeMeta);

        Player->SetPos({120,245});
        Player->VelocidadMovimiento=50;
        Player->AgregarArma(Escenario);
        Escenario->addItem(Player);
        break;
    }
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

QList<ObjetoMovible *> *Mapa::getObjetosMovibles() const
{
    return ObjetosMovibles;
}

QList<Plataforma *> *Mapa::getPlataformas() const
{
    return Plataformas;
}

QList<ZonaGravitacional *> *Mapa::getZonasGravitacionales() const
{
    return ZonasGravitacionales;
}

void Mapa::AgregarParedes()
{
    Plataformas->append(new Plataforma(Color::Negra, QPointF(0, 0), QPointF(SizePantalla.x(), 20))); // Pared superior
    Plataformas->append(new Plataforma(Color::Blanca, QPointF(SizePantalla.x()-20, 0), QPointF(20, 2000))); // Pared derecha
    Plataformas->append(new Plataforma(Color::Negra, QPointF(0, SizePantalla.y() - 20), QPointF(SizePantalla.x(),20))); // Pared inferior
    Plataformas->append(new Plataforma(Color::Blanca, QPointF(0, 0), QPointF(20, 2000))); // Pared izquierda
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
