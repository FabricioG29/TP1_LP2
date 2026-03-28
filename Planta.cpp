#include "Planta.h"


void Planta :: actuar (){
    edad++;
    if (edad >= 20){
        estado = false;
    }

}