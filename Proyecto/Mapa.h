#ifndef MAPA_H
#define MAPA_H

#include <windows.h>

#include "Jugador.h"
#include "Plataforma.h"
#include "ZonaRadial.h"
#include "ZonaRecta.h"
#include "ObjetoMovible.h"


class Mapa
{
public:
    Mapa(unsigned int ID, QGraphicsScene *Escena, Jugador *Jugador_);
    Mapa();
    ~Mapa();

    void JugarMapa();
    void CargarElementos();

    unsigned int getID() const;

    QGraphicsRectItem *getZonaDeMeta() const;

    QList<ObjetoMovible *> *getObjetosMovibles() const;

    QList<Plataforma *> *getPlataformas() const;

    QList<ZonaGravitacional *> *getZonasGravitacionales() const;

private:
    unsigned int ID;

    QGraphicsScene *Escenario;
    QPoint SizePantalla;

    Jugador *Player;

    QList<ObjetoMovible*> *ObjetosMovibles;
    QList<Plataforma*> *Plataformas;
    QList<ZonaGravitacional*> *ZonasGravitacionales;
    void AgregarParedes();
    void AgregarElementos();

    QGraphicsRectItem *ZonaDeMeta;
};

#endif // MAPA_H
