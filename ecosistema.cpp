#include "ecosistema.h"
#include "Planta.h"
#include "Carnivoro.h"
#include "Herbivoro.h"
#include <cstdlib>

// Constructor: inicializamos la matriz con el tamaño dado y llamamamos a reiniciar
Ecosistema::Ecosistema(int filas, int columnas){
    this->filas = filas;
    this->columnas = columnas;
    matriz = std::vector<std::vector<EntidadViva*>>(filas, std::vector<EntidadViva*>(columnas, nullptr));
    reiniciar();
}

// Reinicia la simulacion: resetea el ciclo, limpia la matriz y coloca las entidades iniciales
void Ecosistema::reiniciar(){
    ciclo = 0;
    matriz = std::vector<std::vector<EntidadViva*>>(filas, std::vector<EntidadViva*>(columnas, nullptr));

    int f, c;

    // Colocamos plantas en posiciones aleatorias
    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Planta(f, c, 20);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Planta(f, c, 20);

    // Colocamos herbivoros en posiciones aleatorias
    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    // Colocamos carnivoros en posiciones aleatorias
    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Carnivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Carnivoro(f, c, 50);
}

// Devolvemos el numero del ciclo actual
int Ecosistema::getCiclo(){
    return ciclo;
}

// Contamos y devolvemos la cantidad de plantas en la matriz
int Ecosistema::getCantPlantas(){
    int cont = 0;
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            if(dynamic_cast<Planta*>(matriz[i][j]) != nullptr)
                cont++;
    return cont;
}

// Contamos y devolvemos la cantidad de herbivoros en la matriz
int Ecosistema::getCantHerbivoros(){
    int cont = 0;
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            if(dynamic_cast<Herbivoro*>(matriz[i][j]) != nullptr)
                cont++;
    return cont;
}

// Contamos y devolvemos la cantidad de carnivoros en la matriz
int Ecosistema::getCantCarnivoros(){
    int cont = 0;
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            if(dynamic_cast<Carnivoro*>(matriz[i][j]) != nullptr)
                cont++;
    return cont;
}

// Devolvemos el puntero a la entidad en la celda (fila, col), o nullptr si es que esta vacia
EntidadViva* Ecosistema::getCelda(int fila, int col){
    return matriz[fila][col];
}

// Avanza un ciclo de simulacion: hace actuar a todas las entidades,
// elimina las muertas y aplica movimiento, alimentacion y reproduccion
void Ecosistema::flujo_tiempo(){
    ciclo++;

    // Fase 1: cada entidad ejecuta su accion (incrementa edad, pierde energia, etc.)
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            if(matriz[i][j] != nullptr)
                matriz[i][j]->actuar();

    // Fase 2: eliminamos entidades muertas (energia <= 0 o edad maxima superada)
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
            if(matriz[i][j] != nullptr && !matriz[i][j]->estaViva()){
                delete matriz[i][j];
                matriz[i][j] = nullptr;
            }

    // Vectores de desplazamiento para las 4 direcciones (arriba, abajo, izquierda, derecha)
    int df[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Fase 3: movimiento y alimentacion para los herbivoros
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(dynamic_cast<Herbivoro*>(matriz[i][j]) != nullptr){
                bool comio = false;

                // Mezclamos el orden de busqueda para que no siempre miren en la misma direccion
                int orden[] = {0, 1, 2, 3};  // Las 4 direcciones
                for(int x = 3; x > 0; x--){
                    int r = rand() % (x+1); // Elije una posicion aleatoria
                    // Intercambiamos orden[x] con orden[r]
                    int temp = orden[x];
                    orden[x] = orden[r];
                    orden[r] = temp;
                }

                // Busca una planta vecina para comer
                for(int k = 0; k < 4; k++){
                    int ni = i + df[orden[k]];
                    int nj = j + dc[orden[k]];
                    if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                        if(dynamic_cast<Planta*>(matriz[ni][nj]) != nullptr){
                            delete matriz[ni][nj];           // eliminamos la planta
                            matriz[ni][nj] = matriz[i][j];  // movemos el herbivoro
                            matriz[ni][nj]->setEnergia(matriz[ni][nj]->getEnergia() + 10); // gana energia
                            matriz[i][j] = nullptr;
                            comio = true;
                            break;
                        }
                    }
                }

                // Si no encontro planta, se mueve a una celda vacia vecina
                if(!comio){
                    for(int k = 0; k < 4; k++){
                        int ni = i + df[orden[k]];
                        int nj = j + dc[orden[k]];
                        if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                            if(matriz[ni][nj] == nullptr){
                                matriz[ni][nj] = matriz[i][j];
                                matriz[i][j] = nullptr;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Fase 4: movimiento y alimentacion para los carnivoros
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(dynamic_cast<Carnivoro*>(matriz[i][j]) != nullptr){
                bool comio = false;


                int orden[] = {0, 1, 2, 3};
                for(int x = 3; x > 0; x--){
                    int r = rand() % (x+1);
                    int temp = orden[x]; orden[x] = orden[r]; orden[r] = temp;
                }

                // Busca un herbivoro vecino para comer
                for(int k = 0; k < 4; k++){
                    int ni = i + df[orden[k]];
                    int nj = j + dc[orden[k]];
                    if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                        if(dynamic_cast<Herbivoro*>(matriz[ni][nj]) != nullptr){
                            delete matriz[ni][nj];           // eliminamos el herbivoro
                            matriz[ni][nj] = matriz[i][j];  // movemos el carnivoro
                            matriz[ni][nj]->setEnergia(matriz[ni][nj]->getEnergia() + 10); // gana energia
                            matriz[i][j] = nullptr;
                            comio = true;
                            break;
                        }
                    }
                }

                // Si no encontro herbivoro, se mueve a una celda vacia vecina
                if(!comio){
                    for(int k = 0; k < 4; k++){
                        int ni = i + df[orden[k]];
                        int nj = j + dc[orden[k]];
                        if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                            if(matriz[ni][nj] == nullptr){
                                matriz[ni][nj] = matriz[i][j];
                                matriz[i][j] = nullptr;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Fase 5: reproduccion de plantas con 10% de probabilidad por ciclo
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(dynamic_cast<Planta*>(matriz[i][j]) != nullptr){
                if(rand() % 100 < 10){
                    for(int k = 0; k < 4; k++){
                        int ni = i + df[k];
                        int nj = j + dc[k];
                        if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                            if(matriz[ni][nj] == nullptr){
                                matriz[ni][nj] = new Planta(ni, nj, 20);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}