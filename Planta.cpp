#include "Planta.h"

// Funcion para la forma de actuar de la planta
void Planta :: actuar (){
    edad++;
    if (edad >= 20){
        estado = false; // Si su edad es mayor a 19 muere la planta
    }

}