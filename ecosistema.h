#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H
#include "Entidad_Viva.h"
#include <vector>



// Clase Ecosistema
class Ecosistema{
private: // Private para que solo esta calse pueda acceder

std::vector<std::vector<EntidadViva*>> matriz;  // La matriz
    int filas = 0;
    int columnas = 0;
    int ciclo = 0;

public:

    Ecosistema(int filas, int columnas);  // Constructor: inicializa la matriz con el tamaño dado


    //getters para que la ventana main pueda obtener los datos
    int getCiclo();
    int getCantPlantas();
    int getCantHerbivoros();
    int getCantCarnivoros();


    EntidadViva* getCelda(int fila, int col);   // Puntero a cada Entidad para obtener su celda, o si esta vacia devuelve nullptr

    void flujo_tiempo();  // Funcion para la simulacion de las Entidades y de los ciclos
    void reiniciar(); // Funcion para reiniciar la simulacion

};






#endif // ECOSISTEMA_H
