#include "Herbivoro.h"

// Funcion para el actuar del Herbivoro
void Herbivoro::actuar(){
    edad++;
    energia--;
    if(edad >= 30 || energia <= 0) { // Si su edad supera 29 o su energia llega a 0, muere el Herviboro
        estado = false;
    }

}

