#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    Pantalla = new QGraphicsScene;
    PantallaSizeX=GetSystemMetrics(SM_CXSCREEN)-10;
    PantallaSizeY=GetSystemMetrics(SM_CYSCREEN)-75;
    Pantalla->setSceneRect(0,0,PantallaSizeX,PantallaSizeY);
    setFixedSize(PantallaSizeX,PantallaSizeY);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);
    Borde = new QRectF(0,0,Pantalla->sceneRect().width(),Pantalla->sceneRect().height()-120);
}

void Juego::Jugar()
{
    ContadorGlobal=0;

    ObjetosEstaticos = new QList<ObjetoEstatico*>;
    ObjetosEstaticos = new QList<ObjetoEstatico*>;
    //Arriba
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeX),20}));
    //Derecha
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{static_cast<qreal>(PantallaSizeX),0},{static_cast<qreal>(PantallaSizeY),20},90));
    //Abajo
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,static_cast<qreal>(PantallaSizeY)-10},{static_cast<qreal>(PantallaSizeX),20}));
    //Izquierda
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeY),20},90));
    for(int i=0; i<ObjetosEstaticos->size(); i++)
    {
        Pantalla->addItem(ObjetosEstaticos->at(i));
    }

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
}

Juego::~Juego()
{

}


void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    close();
}


void Juego::Actualizar()
{
    ContadorGlobal+=1;
    ContadorGlobal%=10;
}
