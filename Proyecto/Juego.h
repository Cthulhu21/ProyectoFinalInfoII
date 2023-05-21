#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>
#include <QMouseEvent>

#include "Jugador.h"
#include "ZonaGravitacional.h"
#include "ObjetoMovible.h"

#define PI 3.14159265

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
<<<<<<< Updated upstream
    Juego(QWidget *parent = NULL );
=======
    Juego(QWidget *parent = nullptr );
    ~Juego();
>>>>>>> Stashed changes
    void Jugar();
    ~Juego();
private:
    QTimer *Timer;
    QGraphicsScene *Pantalla;
    Jugador *Player;
    QList<ZonaGravitacional*> *ZonasGravitacionales;
    void InteraccionZonas(ZonaGravitacional *Zona, ObjetoMovible *Objeto);
    QList<ObjetoMovible*> *Objetos;

    void GameOver();
    void InteraccionArma();
    bool VerificarLimites(QRectF *Borde);

    unsigned int ContadorGlobal;
    int PantallaSizeX;
    int PantallaSizeY;

    QRectF *Borde;

    const float Delta=0.1;

    void keyPressEvent(QKeyEvent *evento);
    void mouseMoveEvent(QMouseEvent *event);
<<<<<<< Updated upstream
    void mousePresEvent(QMouseEvent *event);
=======
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
>>>>>>> Stashed changes

private slots:
    void Actualizar();
};

#endif // JUEGO_H
