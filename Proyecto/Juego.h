#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <windows.h>
#include <QMouseEvent>

#include "ObjetoEstatico.h"
#include "Plataforma.h"

#define PI 3.14159265

class Juego: public QGraphicsView
{
    Q_OBJECT
public:
    Juego(QWidget *parent = nullptr );
    ~Juego();
    void Jugar();

private:
    QTimer *Timer;
    QGraphicsScene *Pantalla;
    QList<ObjetoEstatico*> *ObjetosEstaticos;

    void GameOver();

    unsigned int ContadorGlobal;
    int PantallaSizeX;
    int PantallaSizeY;

    QRectF *Borde;

    const float Delta=0.1;

private slots:
    void Actualizar();
};

#endif // JUEGO_H
