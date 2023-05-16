#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    //GetSystemMetrics(SM_CXSCREEN);
    Pantalla = new QGraphicsScene;
    PantallaSizeX=GetSystemMetrics(SM_CXSCREEN)-10;
    PantallaSizeY=GetSystemMetrics(SM_CYSCREEN)-75;
    Pantalla->setSceneRect(0,0,PantallaSizeX,PantallaSizeY);
    setFixedSize(PantallaSizeX,PantallaSizeY);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);
    Borde = new QRectF(0,0,Pantalla->sceneRect().width(),Pantalla->sceneRect().height()-120);

    setMouseTracking(true);
}

void Juego::Jugar()
{
    ContadorGlobal=0;

    ZonasGravitacionales = new QList<ZonaGravitacional*>;
    ZonasGravitacionales->append(new ZonaGravitacional(100,90,3000,0,3000,3000,0));
    for(int i=0; i<ZonasGravitacionales->size(); i++)
    {
        Pantalla->addItem(ZonasGravitacionales->at(i));
    }

    ObjetosEstaticos = new QList<ObjetoEstatico*>;
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeX),20}));//Arriba
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{static_cast<qreal>(PantallaSizeX),0},{static_cast<qreal>(PantallaSizeY),20},90));//Derecha
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,static_cast<qreal>(PantallaSizeY)},{static_cast<qreal>(PantallaSizeX),20}));//Abajo
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeY),20},90));//Izquierda
    for(int i=0; i<ObjetosEstaticos->size(); i++)
    {
        Pantalla->addItem(ObjetosEstaticos->at(i));
    }

    Objetos = new QList<ObjetoMovible*>;
    Objetos->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{1000,500}));
    for(int i=0; i<Objetos->size(); i++)
    {
        Pantalla->addItem(Objetos->at(i));
    }

    Player = new Jugador(10,{500,500});
    Pantalla->addItem(Player);
    Player->AgregarArma(Pantalla);

    Timer = new QTimer;
    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));

}

Juego::~Juego()
{

}

void Juego::keyPressEvent(QKeyEvent *evento)
{
    int AceleracionExtra=10000;
    switch(evento->key())
    {
    case Qt::Key_W:
        Player->setAceleracion(Player->Aceleracion.first,-AceleracionExtra);
        break;
    case Qt::Key_A:
        Player->setAceleracion(-AceleracionExtra*0.3,Player->Aceleracion.second);
        break;
    case Qt::Key_D:
        Player->setAceleracion(AceleracionExtra*0.3,Player->Aceleracion.second);
        break;
    case Qt::Key_Space:
        if(Timer->isActive())
            Timer->stop();
        else
            Timer->start(10);
        break;
    case Qt::Key_R:
        Pantalla->clear();
        delete Timer;
        Jugar();
        break;
    default:
        break;
    }
}

void Juego::InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto)
{
    if(Zona)
    {
        float X0=Objeto->getBordes()->x(), Y0=Objeto->getBordes()->y();
        float X, Y;
        CalcularPosicion(Zona, Objeto, &X, &Y);
        Jugador *player= dynamic_cast<Jugador*>(Objeto);
        if(player)
        {
            if(!VerificarLimites(Objeto->getBordes()))
                player->SetPos({X0,Y0});
        }
        else
        {
            if(!VerificarLimites(Objeto->getBordes()))
                Objeto->SetPos({X0,Y0});
        }
    }
}

void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    close();
}

void Juego::CalcularPosicion(ZonaGravitacional *Zona, ObjetoMovible *Objeto, float *X_, float *Y_)
{
    float PosX=Objeto->getBordes()->x(), PosY=Objeto->getBordes()->y();
    float VelX=Objeto->Velocidad.first, VelY=Objeto->Velocidad.second;
    float AcelX=Objeto->Aceleracion.first, AcelY=Objeto->Aceleracion.second;
    float Fuerza=Zona->getFuerzaGravitacional();
    float FuerzaX=Fuerza*cos(Zona->getRotacion()*PI/180), FuerzaY=Fuerza*sin(Zona->getRotacion()*PI/180);
    float AcelFueX=FuerzaX/Objeto->getMasa(), AcelFueY=FuerzaY/Objeto->getMasa();

    if(abs(AcelFueX)<0.1)
        AcelFueX=0;
    if(abs(AcelFueY)<0.1)
        AcelFueY=0;

    PosX+=VelX*Delta+Delta*Delta*0.5*(AcelFueX+AcelX);
    PosY+=VelY*Delta+Delta*Delta*0.5*(AcelFueY+AcelY);

    VelX+=AcelFueX*Delta;
    VelY+=AcelFueY*Delta;

    if(abs(AcelX)<0.1)
    {
        AcelX=0;
    }
    if(abs(AcelY)<0.1)
    {
        AcelY=0;
    }
    Objeto->setAceleracion(AcelX, AcelY);
    Objeto->AumentarVelocidad(VelX, VelY);
    Objeto->SetPos({PosX, PosY});
    *X_=PosX;
    *Y_=PosY;
}

bool Juego::VerificarLimites(QRectF *Borde)
{
    QGraphicsView *Pantalla_=scene()->views().first();
    QRectF PantallaRect = Pantalla_->mapToScene(Pantalla_->viewport()->rect()).boundingRect();
    return PantallaRect.contains(*Borde);
}

void Juego::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    QPointF mousePos = mapToScene(event->pos());

    // Calcular la dirección del mouse con respecto al arma
    QPointF direction = mousePos - Player->getPistola()->pos();

    // Calcular el ángulo de rotación en radianes
    qreal angle = std::atan2(direction.y(), direction.x());

    // Convertir el ángulo a grados
    qreal rotation = qRadiansToDegrees(angle);

    // Rotar el arma
    Player->getPistola()->setRotation(rotation);
}

void Juego::mousePresEvent(QMouseEvent *event)
{
    QPointF mousePos = mapToScene(event->pos());

    // Calcular la dirección del mouse con respecto al arma
    QPointF direction = mousePos - Player->getPistola()->pos();

    // Calcular el ángulo de rotación en radianes
    qreal angle = std::atan2(direction.y(), direction.x());

    // Convertir el ángulo a grados
    qreal rotation = qRadiansToDegrees(angle);
    if(Player->getPistola()->TipoDeDisparo==Disparo::Atractivo)
    {
        QPointF PosArma=Player->getPistola()->pos();
    }
}

void Juego::Actualizar()
{
    ContadorGlobal+=1;
    ContadorGlobal%=10;
    //Actualizar el frame
    if(ContadorGlobal%5==0)
    {
        Player->SiguienteFrame();
    }
    {
        QList<QGraphicsItem*> Items=Pantalla->items();
        for(QGraphicsItem *Item : Items)
        {
            ObjetoMovible *Objeto= dynamic_cast<ObjetoMovible*>(Item);
            if(Objeto)
            {
                QList<QGraphicsItem*> items=Objeto->collidingItems();
                for(QGraphicsItem *item : items)
                {
                    ZonaGravitacional *Zona=dynamic_cast<ZonaGravitacional*>(item);
                    if(Zona)
                    {
                        InteraccionZonas(Zona, Objeto);
                    }
                }
            }
        }
    }
}
