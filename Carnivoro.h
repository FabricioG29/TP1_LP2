#ifndef CARNIVORO_H
#define CARNIVORO_H
#include "Entidad_Viva.h"


class Carnivoro : public EntidadViva{
public:
    Carnivoro(int px,int py, int e) : EntidadViva(px,py,e){

    }


    void actuar() override;

};



#endif // CARNIVORO_H
