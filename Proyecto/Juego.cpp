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
