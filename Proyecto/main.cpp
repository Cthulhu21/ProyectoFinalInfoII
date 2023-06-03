#include <QApplication>
#include "Juego.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego *Game = new Juego;
    Game->show();
    Game->EmpezarJuego(5);
    return a.exec();
}
