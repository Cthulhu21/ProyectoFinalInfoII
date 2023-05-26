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

private:
    unsigned int ID;

    QGraphicsScene *Escenario;
    QPoint SizePantalla;

    Jugador *Player;

    QPointF *PosicionInicialJugador;
    QList<ObjetoMovible*> *ObjetosMovibles;
    QList<Plataforma*> *Plataformas;
    QList<ZonaGravitacional*> *ZonasGravitacionales;

    QGraphicsRectItem *ZonaDeMeta;
};

#endif // MAPA_H
