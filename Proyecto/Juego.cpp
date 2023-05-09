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
}

void Juego::Jugar()
{
    Puntuacion = 0;
    scoreLabel = new QGraphicsTextItem();
    scoreLabel->setPlainText(QString("Puntuacion: %1").arg(Puntuacion));
    scoreLabel->setPos(1000, 10);
    scoreLabel->setFont(QFont("Arial", 16));
    scoreLabel->setDefaultTextColor(Qt::white); // Establece el color de texto a negro
    scoreLabel->setTextWidth(scoreLabel->boundingRect().width());
    Pantalla->addItem(scoreLabel);



    Player = new Jugador(810,300);
    Pantalla->addItem(Player);

    Vidas=3;
    vidasLabel = new QGraphicsTextItem();
    vidasLabel->setPlainText(QString("Vidas: %1").arg(Vidas));
    vidasLabel->setPos(100, 10);
    vidasLabel->setFont(QFont("Arial", 16));
    vidasLabel->setDefaultTextColor(Qt::white); // Establece el color de texto a negro
    vidasLabel->setTextWidth(scoreLabel->boundingRect().width());
    Pantalla->addItem(vidasLabel);

    Fantasmas = new QList<Enemigo*>;
    for(int i=0; i<4; i++)
    {

        Fantasmas->append(new Enemigo(800+i*45,480));
        Pantalla->addItem(Fantasmas->at(i));
    }
    Comestibles = new QList<Comestible*>;
    //Frutas
    {
        Comestibles->append(new Comestible(0,270*0.50,480*0.39));
        Comestibles->append(new Comestible(0,1705*0.50,450*0.39));
        Comestibles->append(new Comestible(0,2130*0.50,450*0.39));
        Comestibles->append(new Comestible(0,3570*0.50,480*0.39));
        Comestibles->append(new Comestible(0,1300*0.50,1650*0.39));
        Comestibles->append(new Comestible(0,2500*0.50,1650*0.39));
    }
    //Puntos normales
    {
        //        Comestibles->append(new Comestible(1,270*0.50,130*0.39));
        for(int i=0; i<10; i++)
        {
            Comestibles->append(new Comestible(1,270*0.50+75*i,130*0.39));
            Comestibles->append(new Comestible(1,2200*0.50+75*i,130*0.39));
            Comestibles->append(new Comestible(1,270*0.50+85*4,130*0.39+75*i));
            Comestibles->append(new Comestible(1,2200*0.50+75*4,130*0.39+75*i));
        }
    }
    for(int i=0; i<Comestibles->size(); i++)
    {
        Pantalla->addItem(Comestibles->at(i));
    }
    Pared = new Paredes;
    Pantalla->addItem(Pared);

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
    Timer->start(10);

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

void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    TimerAnimaciones->stop();
    QMessageBox::information(this, "Juego terminado", "¡El juego ha terminado!");
    close();
}

void Juego::Actualizar()
{
    if (TiempoInvencible>0)
    {
        TiempoInvencible-=1;
    }
    else if(Player->getInvencible())
    {
        Player->setInvencible(false);
    }
    bool GameOver_=false;
    QList<QGraphicsItem*> items=Player->collidingItems();
    for(QGraphicsItem *item : items)
    {
        Enemigo *fantasma = dynamic_cast<Enemigo*>(item);
        Comestible *comestible =dynamic_cast<Comestible*>(item);
        if(fantasma and items.contains(item))
        {
            if(Player->getInvencible())
            {
                for(int i=0; i<Fantasmas->size(); i++)
                {
                    if(Fantasmas->at(i)==fantasma)
                    {
                        delete Fantasmas->at(i);
                        Fantasmas->removeAt(i);
                    }
                }
            }
            else if(Vidas>1)
            {
                Player->SetPos(810,300);
                Vidas-=1;
                vidasLabel->setPlainText(QString("Puntuacion: %1").arg(Vidas));
            }
            else
            {
                GameOver_=true;
                break;
            }
        }
        if(comestible and items.contains(item))
        {
            if(comestible->Fruta)
            {
                Player->setInvencible(true);
                TiempoInvencible=1500;
            }
            else
            {
                Puntuacion+=1;
                scoreLabel->setPlainText(QString("Puntuacion: %1").arg(Puntuacion));
            }
            for(int i=0; i<Comestibles->size(); i++)
            {
                if(Comestibles->at(i)==comestible)
                {
                    delete Comestibles->at(i);
                    Comestibles->removeAt(i);
                }
            }
        }
    }
    if(!GameOver_)
    {
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
    else
    {
        GameOver();
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
