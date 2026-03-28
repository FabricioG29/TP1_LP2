#include "Herbivoro.h"


void Herbivoro::actuar(){
    edad++;
    energia--;
    if(edad >= 30 || energia <= 0) {
        estado = false;
    }

}

