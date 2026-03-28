#include "Carnivoro.h"


void Carnivoro::actuar(){
    edad++;
    energia--;
    if(edad >= 35 || energia <= 0) {
        estado = false;
    }

}