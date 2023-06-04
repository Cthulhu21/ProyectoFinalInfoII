#include "Juego.h"

Juego::Juego(QWidget *parent)
{
    Pantalla = new QGraphicsScene;
    PantallaSizeX=1500;
    PantallaSizeY=800;
    Pantalla->setSceneRect(0,0,PantallaSizeX,PantallaSizeY);
    setFixedSize(PantallaSizeX,PantallaSizeY);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(Pantalla);

    setAutoFillBackground(false);

    setMouseTracking(true);
}

Juego::~Juego()
{
    delete Timer;
    delete Pantalla;
    delete Player;
    delete MapaActual;
}

void Juego::EmpezarJuego(unsigned int IDMapa)
{
    Pantalla->clear();

    ContadorGlobal=0;

    Player = new Jugador(10);

    Timer = new QTimer;

    connect(Timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
    MapaActual = new Mapa(IDMapa, Pantalla, Player);
    JuegoActivo=false;
}

void Juego::SiguienteMapa()
{
    EmpezarJuego(MapaActual->getID()+1);
}

void Juego::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_Space)
    {
        if(JuegoActivo)
        {
            JuegoActivo=false;
            Timer->stop();
        }
        else
        {
            JuegoActivo=true;
            Timer->start(10);
        }
    }
    if(!JuegoActivo)
        return;
    float Vel=Player->VelocidadMovimiento;
    switch(evento->key())
    {
    case Qt::Key_W:
        if(Player->Saltando)
            return;
        Player->Velocidad->setY(-Vel);
        Player->Saltando=true;
        break;
    case Qt::Key_A:
        Player->Velocidad->setX(-Vel);
        break;
    case Qt::Key_D:
        Player->Velocidad->setX(Vel);
        break;
    case Qt::Key_R:
        Pantalla->clear();
        delete Timer;
        EmpezarJuego(MapaActual->getID());
        JuegoActivo=false;
        break;
    default:
        break;
    }
}

void Juego::InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto, bool *Next)
{
    if(Objeto->ObjetoPegado)
    {
        return;
    }
    if(Zona==Player->getPistola()->getRangoArma() and Objeto==Player)
        return;

    QPointF Pos0 = Objeto->pos();

    float MagnitudFuerza = Zona->getFuerzaGravitacional();
    float AnguloRadianes = Zona->DireccionFuerza * (M_PI / 180.0);
    ZonaRadial *Radial =dynamic_cast<ZonaRadial*>(Zona);
    if(Radial)
    {
        QPointF Centro = Radial->getCentro();
        QPointF Direccion = Centro - Pos0;
        if(Radial->TipoDeInteraccion==ZonaRadial::Interaccion::Repulsivo)
        {
            Direccion = Pos0-Centro;
        }
        AnguloRadianes= atan2(Direccion.y(), Direccion.x());

    }

    float FuerzaHorizontal = MagnitudFuerza * cos(AnguloRadianes);
    float FuerzaVertical = MagnitudFuerza * sin(AnguloRadianes);
    if(abs(FuerzaHorizontal)<0.1)
        FuerzaHorizontal=0;
    if(abs(FuerzaVertical)<0.1)
        FuerzaVertical=0;

    float AceleracionHorizontal = FuerzaHorizontal / Objeto->getMasa();
    float AceleracionVertical = FuerzaVertical / Objeto->getMasa();

    Objeto->Velocidad->setX(Objeto->Velocidad->x() + AceleracionHorizontal * Delta);
    Objeto->Velocidad->setY(Objeto->Velocidad->y() + AceleracionVertical * Delta);

    QPointF Desplazamiento = *Objeto->Velocidad * Delta;
    QPointF SiguientePos=Pos0+Desplazamiento;

    Objeto->Posicion->setX(Objeto->Posicion->x() + Desplazamiento.x());
    Objeto->Posicion->setY(Objeto->Posicion->y() + Desplazamiento.y());

    //Colisión en Y
    Objeto->SetPos({Pos0.x(), SiguientePos.y()});
    QList<QGraphicsItem*> *Colisiones=new QList<QGraphicsItem*>(Objeto->collidingItems());
    QList<ObjetoMovible*> *Movibles = new QList<ObjetoMovible*>;
    QList<ObjetoEstatico*> *Estaticos = new QList<ObjetoEstatico*>;
    for(QGraphicsItem *Item : *Colisiones)
    {
        if(dynamic_cast<ObjetoMovible*>(Item))
        {
            Movibles->append(dynamic_cast<ObjetoMovible*>(Item));
        }
        else if(dynamic_cast<ObjetoEstatico*>(Item))
        {
            Estaticos->append(dynamic_cast<ObjetoEstatico*>(Item));
        }
        else if(Item==Player->getPistola() and Objeto!=Player and Player->getPistola()->Activa)
        {
            PegarObjetoAArma(Objeto);
            delete Colisiones;
            delete Movibles;
            delete Estaticos;
            return;
        }
        else if(Item==MapaActual->getZonaDeMeta())
        {
            delete Colisiones;
            delete Movibles;
            delete Estaticos;
            *Next=true;
            return;
        }
    }
    if(!Movibles->empty())
        MomentoEnergia(Objeto, Movibles->at(0));

    if(!Estaticos->empty())
    {
        float k=0.1;
        if(Objeto!=Player)
        {
            k=0.2;
        }
        Objeto->Velocidad->setY(Objeto->Velocidad->y()*-k);
        Objeto->Posicion->setY(Pos0.y());
        if(Objeto==Player)
            Player->Saltando=false;
    }

    //Colisión en X
    Objeto->SetPos({SiguientePos.x(), Objeto->Posicion->y()});

    Colisiones=new QList<QGraphicsItem*>(Objeto->collidingItems());
    Movibles = new QList<ObjetoMovible*>;
    Estaticos = new QList<ObjetoEstatico*>;
    for(QGraphicsItem *Item : *Colisiones)
    {
        if(dynamic_cast<ObjetoMovible*>(Item))
        {
            Movibles->append(dynamic_cast<ObjetoMovible*>(Item));
        }
        else if(dynamic_cast<ObjetoEstatico*>(Item))
        {
            Estaticos->append(dynamic_cast<ObjetoEstatico*>(Item));
        }
        else if(Item==Player->getPistola() and Objeto!=Player and Player->getPistola()->Activa)
        {
            PegarObjetoAArma(Objeto);
            delete Colisiones;
            delete Movibles;
            delete Estaticos;
            return;
        }
        else if(Item==MapaActual->getZonaDeMeta())
        {
            delete Colisiones;
            delete Movibles;
            delete Estaticos;
            *Next=true;
            return;
        }
    }
    if(!Movibles->empty())
        MomentoEnergia(Objeto, Movibles->at(0));
    if(!Estaticos->empty())
    {
        float k=0.1;
        if(Objeto!=Player)
        {
            k=0.2;
        }
        Objeto->Velocidad->setX(Objeto->Velocidad->x()*-k);
        Objeto->Posicion->setX(Pos0.x());
    }
    Objeto->SetPos(*Objeto->Posicion);
    if(Objeto==Player)
        Objeto->Velocidad->setX(Objeto->Velocidad->x()*0.95);
    else
        Objeto->Velocidad->setX(Objeto->Velocidad->x()*0.995);
    *Objeto->Velocidad*=0.995;
    if(abs(Objeto->Velocidad->x())<0.1)
    {
        Objeto->Velocidad->setX(0);
    }
    if(abs(Objeto->Velocidad->y())<0.1)
    {
        Objeto->Velocidad->setY(0);
    }
    delete Colisiones;
    delete Movibles;
    delete Estaticos;
}

void Juego::PegarObjetoAArma(ObjetoMovible *Objeto)
{
    Objeto->ObjetoPegado=true;
    Player->getPistola()->setObjetoPegado(Objeto);
    Player->Disparar(Pantalla);
    Player->getPistola()->MoviblePegado=true;
}

void Juego::GameOver()
{
    Pantalla->clear();
    Timer->stop();
    close();
}

void Juego::MomentoEnergia(ObjetoMovible *Objeto1, ObjetoMovible *Objeto2)
{
    if(!(Objeto1==Player or Objeto2==Player))
    {
        float Masa1=Objeto1->getMasa(), Masa2=Objeto2->getMasa();
        float Vx0Objeto1=Objeto1->Velocidad->x();
        float Vx0Objeto2=Objeto2->Velocidad->x();

        float Vy0Objeto1=Objeto1->Velocidad->y();
        float Vy0Objeto2=Objeto2->Velocidad->y();

        float VxFObjeto1 = (2*Masa2*Vx0Objeto2-Vx0Objeto1*(Masa2-Masa1))/(Masa1+Masa2);
        float VyFObjeto1 = (2*Masa2*Vy0Objeto2-Vy0Objeto1*(Masa2-Masa1))/(Masa1+Masa2);

        Objeto1->Velocidad->setX(VxFObjeto1);
        Objeto1->Velocidad->setY(VyFObjeto1);

        float VxFObjeto2 = Vx0Objeto1-Vx0Objeto2 +VxFObjeto1;
        float VyFObjeto2 = Vy0Objeto1-Vy0Objeto2 +VyFObjeto1;
        Objeto2->Velocidad->setX(VxFObjeto2);
        Objeto2->Velocidad->setY(VyFObjeto2);
    }
}

void Juego::MoverPlataformas()
{
    QPointF Movimiento;
    for(Plataforma *Plataforma_ : *MapaActual->getPlataformas())
    {
        Plataforma_->SiguientePos(Delta, &Movimiento);

        for(QGraphicsItem *Item: Plataforma_->collidingItems())
        {
            ObjetoMovible *Objeto = dynamic_cast<ObjetoMovible *>(Item);
            if(Objeto)
            {
                Objeto->SetPos(Objeto->pos()+Movimiento);
            }
        }
    }
}

void Juego::mouseMoveEvent(QMouseEvent *event)
{
    if(!JuegoActivo)
        return;
    Player->RotarArma();
}

void Juego::mousePressEvent(QMouseEvent *event)
{
    if(!JuegoActivo)
        return;
    switch(event->button())
    {
    case Qt::LeftButton:
        Player->Disparar(Pantalla);
        break;
    case Qt::RightButton:
        Player->DispararObjeto();
    default:
        break;
    }
}

void Juego::Actualizar()
{
    if(!JuegoActivo)
        return;
    bool NextLevel=false;
    ContadorGlobal+=1;
    ContadorGlobal%=100;
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
                        InteraccionZonas(Zona, Objeto, &NextLevel);
                }
            }
        }
    }
    if(ContadorGlobal%1==0)
    {
        MoverPlataformas();
    }
    if(NextLevel)
        SiguienteMapa();
}
