#ifndef PLANTA_H
#define PLANTA_H
#include "Entidad_Viva.h"

class Planta : public EntidadViva{
public:
    Planta(int px, int py, int e) : EntidadViva(px,py,e){


    }

    void actuar() override;




};

#endif // PLANTA_H
