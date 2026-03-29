#ifndef CARNIVORO_H
#define CARNIVORO_H
#include "Entidad_Viva.h"



// Clase Carnivoro que hereda de la Clase EntidadViva
class Carnivoro : public EntidadViva{
public:
    Carnivoro(int px,int py, int e) : EntidadViva(px,py,e){  // Le pasamos al constructor los parametros de las  posiciones de cada Carnivoro

    }


    void actuar() override;  // Funcion del actuar de los Carnivoros con override porque se va a sobreescribir

};



#endif // CARNIVORO_H
