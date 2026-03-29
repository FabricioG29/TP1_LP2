#ifndef HERBIVORO_H
#define HERBIVORO_H
#include "Entidad_Viva.h"



// Clase Herbivoro hereda de la Clase EntidaViva
class Herbivoro : public EntidadViva{
public:
    Herbivoro(int px,int py, int e): EntidadViva(px,py,e){ // Le pasamos al constructor losm parametros de posiciones y energia para los Herbivoros

    }


    void actuar() override; // Funcion actuar para los Herbivoros, con override porque se va a sobreescribir



};

#endif // HERBIVORO_H
