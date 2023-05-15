#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    //GetSystemMetrics(SM_CXSCREEN);
    Pantalla = new QGraphicsScene;
    PantallaSizeX=GetSystemMetrics(SM_CXSCREEN);
    PantallaSizeY=GetSystemMetrics(SM_CYSCREEN);
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

    Objetos = new QList<ObjetoMovible*>;
    Objetos->append(new ObjetoMovible(TipoDeObjeto::Cubo,10,{1000,500}));
    for(int i=0; i<Objetos->size(); i++)
    {
        Pantalla->addItem(Objetos->at(i));
    }

    Player = new Jugador(10,{1000,500});
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
        Jugador *player= dynamic_cast<Jugador*>(Objeto);
        if(player)
        {
            float X0=player->x(), Y0=player->y();
            float X, Y;
            CalcularPosicion(Zona, player, &X, &Y);
            if(Borde->contains(*player->getBordes()))
            {
                player->SetPos({X,Y});
            }
            else
            {
                player->SetPos({X0,Y0});
            }
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
    float PosX=Objeto->x(), PosY=Objeto->y();
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
    *X_=PosX;
    *Y_=PosY;
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
        QList<QGraphicsItem*> Items=Player->collidingItems();
        for(QGraphicsItem *Item : Items)
        {
            ZonaGravitacional *Zona=dynamic_cast<ZonaGravitacional*>(Item);
            if(Zona)
            {
                InteraccionZonas(Zona, Player);
            }
        }
    }
}
