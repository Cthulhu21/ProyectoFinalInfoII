#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    Pantalla = new QGraphicsScene;
    PantallaSizeX=GetSystemMetrics(SM_CXSCREEN);
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
    ZonasGravitacionales->append(new ZonaGravitacional(100,90,{3000,0},3000,3000,0));
    for(int i=0; i<ZonasGravitacionales->size(); i++)
    {
        Pantalla->addItem(ZonasGravitacionales->at(i));
    }

<<<<<<< Updated upstream
=======
    ObjetosEstaticos = new QList<ObjetoEstatico*>;
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeX),20}));//Arriba
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{static_cast<qreal>(PantallaSizeX),0},{static_cast<qreal>(PantallaSizeY),20},90));//Derecha
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,static_cast<qreal>(PantallaSizeY)-100},{static_cast<qreal>(PantallaSizeX),20}));//Abajo
    ObjetosEstaticos->append(new Plataforma(Color::Negra,{0,0},{static_cast<qreal>(PantallaSizeY),20},90));//Izquierda
    for(int i=0; i<ObjetosEstaticos->size(); i++)
    {
        Pantalla->addItem(ObjetosEstaticos->at(i));
    }

>>>>>>> Stashed changes
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
        //Player->setAceleracion(Player->Aceleracion.first,-AceleracionExtra);
        break;
    case Qt::Key_A:
        //Player->setAceleracion(-AceleracionExtra*0.3,Player->Aceleracion.second);
        break;
    case Qt::Key_D:
        //Player->setAceleracion(AceleracionExtra*0.3,Player->Aceleracion->second);
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
    if(!(Zona==Player->getPistola()->getRangoArma() and Objeto==Player))
    {
        QPointF Pos0 = Objeto->pos();

        float magnitudFuerza = Zona->getFuerzaGravitacional();

        float anguloRadianes = Zona->getRotacion() * (M_PI / 180.0);

        float fuerzaHorizontal = magnitudFuerza * cos(anguloRadianes);
        float fuerzaVertical = magnitudFuerza * sin(anguloRadianes);
        if(abs(fuerzaHorizontal)<0.1)
            fuerzaHorizontal=0;
        if(abs(fuerzaVertical)<0.1)
            fuerzaVertical=0;

        float aceleracionHorizontal = fuerzaHorizontal / Objeto->getMasa();
        float aceleracionVertical = fuerzaVertical / Objeto->getMasa();

        Objeto->Velocidad->setX(Objeto->Velocidad->x() + aceleracionHorizontal * Delta);
        Objeto->Velocidad->setY(Objeto->Velocidad->y() + aceleracionVertical * Delta);

        QPointF desplazamiento = *Objeto->Velocidad * Delta;
        Objeto->Posicion->setX(Objeto->Posicion->x() + desplazamiento.x());
        Objeto->Posicion->setY(Objeto->Posicion->y() + desplazamiento.y());

        QList<QGraphicsItem*> Items=Objeto->collidingItems();
        bool Colision=false;
        for(QGraphicsItem * Item : Items)
        {
            ObjetoEstatico *Objeto_ = dynamic_cast<ObjetoEstatico*>(Item);
            if(Objeto_)
            {
                Colision=true;
                break;
            }
        }
        if(Colision)
        {
            *Objeto->Posicion=Pos0;
            *Objeto->Velocidad={0,0};
        }
        Objeto->SetPos(*Objeto->Posicion);
        /*Jugador *player = dynamic_cast<Jugador*>(Objeto);
        if(player)
        {
            player->SetPos(*player->Posicion);
        }
        else
            Objeto->SetPos(*Objeto->Posicion);*/
    }
}

void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    close();
}

void Juego::InteraccionArma()
{
    if(Player->getPistola()->Activa)
    {
        QList<QGraphicsItem*> Items=Player->getPistola()->getRangoArma()->collidingItems();
        QList<ObjetoMovible*> *ObjetosZona = new QList<ObjetoMovible*>;
        for(QGraphicsItem *Item : Items)
        {
            ObjetoMovible *Movible = dynamic_cast<ObjetoMovible*>(Item);
            if(Movible and Movible!=Player)
            {
                ObjetosZona->append(Movible);
            }
        }
        for(ObjetoMovible *Objeto : *ObjetosZona)
        {
        }
    }
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
    Player->getPistola()->Rotar(rotation);
}

void Juego::mousePresEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        Player->Disparar(Pantalla);
    }
}

void Juego::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //Player->Disparar(Pantalla);
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
        //InteraccionArma();
    }
}
