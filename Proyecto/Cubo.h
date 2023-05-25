#ifndef CUBO_H
#define CUBO_H

#include "ObjetoMovible.h"

class Cubo: public ObjetoMovible
{
    Q_OBJECT
public:
    Cubo(QPointF Pos, QPointF Size={30,31}, int Masa=10);
    ~Cubo();
private:
    void CargarSprites() override;
};

#endif // CUBO_H
