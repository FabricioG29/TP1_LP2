#ifndef HERBIVORO_H
#define HERBIVORO_H
#include "Entidad_Viva.h"

class Herbivoro : public EntidadViva{
public:
    Herbivoro(int px,int py, int e): EntidadViva(px,py,e){

    }


    void actuar() override;



};

#endif // HERBIVORO_H
