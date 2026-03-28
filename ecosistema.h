#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H
#include "Entidad_Viva.h"
#include <vector>


class Ecosistema{
private:
std::vector<std::vector<EntidadViva*>> matriz;
    int filas = 0;
    int columnas = 0;
    int ciclo = 0;
public:
    Ecosistema(int filas, int columnas);

    //getters para que la ventana main pueda obtener los datos
    int getCiclo();
    int getCantPlantas();
    int getCantHerbivoros();
    int getCantCarnivoros();


    EntidadViva* getCelda(int fila, int col);

    void flujo_tiempo();
    void reiniciar();

};






#endif // ECOSISTEMA_H
