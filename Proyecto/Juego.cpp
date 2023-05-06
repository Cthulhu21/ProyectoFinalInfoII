#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    //GetSystemMetrics(SM_CXSCREEN);
    Pantalla = new QGraphicsScene;
    Pantalla->setSceneRect(0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
    setFixedSize(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);
    setBackgroundBrush(QBrush(Qt::black));

    Player = new Jugador(810,300);
    Pantalla->addItem(Player);

    Fantasmas = new QList<Enemigo*>;
    for(int i=0; i<4; i++)
    {

        Fantasmas->append(new Enemigo(800+i*45,480));
        Pantalla->addItem(Fantasmas->at(i));
    }

    Pared = new Paredes;
    Pantalla->addItem(Pared);

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
    Timer->start(1);

    TimerAnimaciones = new QTimer;
    connect(TimerAnimaciones, SIGNAL(timeout()), this, SLOT(ActualizarFrames()));
    TimerAnimaciones->start(100);
}

Juego::~Juego()
{

}

void Juego::keyPressEvent(QKeyEvent *evento)
{
    switch(evento->key())
    {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        Player->CambiarDireccion(evento->key());
        break;

    default:
        break;
    }
}

void Juego::Actualizar()
{
    for(int i=0; i<Fantasmas->size(); i++)
    {
        if(Player->getRectangulo()->collidesWithItem(Fantasmas->at(i)->getRectangulo()))
        {
            delete Fantasmas->at(i);
            Fantasmas->removeAt(i);
        }
    }
    //Mueve al jugador
    {
        const float PosX_=Player->getPosX(), PosY_=Player->getPosY();
        Player->AplicarMovimiento();
        if(Player->getRectangulo()->collidesWithItem(Pared))
        {
            Player->SetPos(PosX_,PosY_);
        }

    }
    //Mover a los fantasmas
    {
        for(Enemigo *Enemigo_ : *Fantasmas)
        {
            QPointF Posicion = Enemigo_->pos();
            Enemigo_->Mover();
            if(Enemigo_->getRectangulo()->collidesWithItem(Pared))
            {
                Enemigo_->SetPos(Posicion.x(), Posicion.y());
                Enemigo_->CambiarDireccion();
            }
        }
    }
}

void Juego::ActualizarFrames()
{
    //Jugador
    {
        Player->SiguienteFrame();
    }
    //Enemigo
    {
        for(Enemigo *Enemigo_ : *Fantasmas)
        {
            Enemigo_->SiguienteFrame();
        }

    }
}
