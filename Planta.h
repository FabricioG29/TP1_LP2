#ifndef PLANTA_H
#define PLANTA_H
#include "Entidad_Viva.h"


// Clase Planta hereda de EntidadViva
class Planta : public EntidadViva{
public:
    Planta(int px, int py, int e) : EntidadViva(px,py,e){ // Le pasamos al constructor los parametros de posiciones y energia de la planta


    }

    void actuar() override;  // Funcion del actuar de la Planta con override porque se va a sobreescribir




};

#endif // PLANTA_H
