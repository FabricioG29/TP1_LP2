#include "Carnivoro.h"

// Funcion para el actuar del Carnivoro
void Carnivoro::actuar(){
    edad++;
    energia--;
    if(edad >= 35 || energia <= 0) { // Si su edad supera los 34 o su energia llega a 0, muere
        estado = false;
    }

}