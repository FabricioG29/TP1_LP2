#include "ecosistema.h"
#include "Planta.h"
#include "Carnivoro.h"
#include "Herbivoro.h"
#include <cstdlib>

Ecosistema::Ecosistema(int filas, int columnas){
    this->filas = filas;
    this->columnas = columnas;
    matriz = std::vector<std::vector<EntidadViva*>>(filas, std::vector<EntidadViva*>(columnas, nullptr));
    reiniciar();
}

void Ecosistema::reiniciar(){
    ciclo = 0;
    matriz = std::vector<std::vector<EntidadViva*>>(filas, std::vector<EntidadViva*>(columnas, nullptr));
    // Para cada entidad:
    int f,c;


    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Planta(f, c, 20);


    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Carnivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Carnivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Planta(f, c, 20);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);

    do { f = rand()%filas; c = rand()%columnas; } while(matriz[f][c] != nullptr);
    matriz[f][c] = new Herbivoro(f, c, 50);
}

int Ecosistema::getCiclo(){
    return ciclo;
}

int Ecosistema:: getCantPlantas(){
    int i,j;
    int cont_plantas = 0;

    for(i = 0; i < filas ; i++){
        for(j = 0; j < columnas; j++){
            if(dynamic_cast<Planta*>(matriz[i][j]) != nullptr){
                cont_plantas++;

            }
        }

    }
    return cont_plantas;
}

int Ecosistema:: getCantHerbivoros(){
    int i,j;
    int cont_Herbivoros = 0;

    for(i = 0; i < filas ; i++){
        for(j = 0; j < columnas; j++){
            if(dynamic_cast<Herbivoro*>(matriz[i][j]) != nullptr){
                cont_Herbivoros++;

            }
        }

    }
    return cont_Herbivoros;
}


int Ecosistema:: getCantCarnivoros(){
    int i,j;
    int cont_carnivoros = 0;

    for(i = 0; i < filas ; i++){
        for(j = 0; j < columnas; j++){
            if(dynamic_cast<Carnivoro*>(matriz[i][j]) != nullptr){
                cont_carnivoros++;

            }
        }

    }
    return cont_carnivoros;
}

EntidadViva* Ecosistema::getCelda(int fila, int col){
    return matriz[fila][col];
}


void Ecosistema::flujo_tiempo(){
    ciclo++;
    int i,j;


    // Recorremos la matriz y llamamos al actuar de cada entidad
    for(i = 0; i < filas ; i++){
        for(j = 0; j < columnas; j++){
            if(matriz[i][j] != nullptr){
                matriz[i][j]->actuar();
            }
        }

    }

    // Verificamos si la entidad esta muerta, si es asi, la eliminamos
    for(i = 0; i < filas ; i++){
        for(j = 0; j < columnas; j++){
            if((matriz[i][j] != nullptr) && !matriz[i][j]->estaViva()){
                delete matriz[i][j]; //le eliminamos
                matriz[i][j] = nullptr; //vaciamos su celda
            }
        }

    }

    int df[] = {-1, 1, 0, 0}; // Movimiento de a la izq y derecha
    int dc[] = {0, 0, -1, 1}; // Movimiento de arriba y abajo


    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            if(dynamic_cast<Herbivoro*>(matriz[i][j]) != nullptr){
                bool comio = false;  // resetea para cada herbívoro

                int orden[] = {0, 1, 2, 3};
                for(int x = 3; x > 0; x--){
                    int r = rand() % (x+1);
                    int temp = orden[x];
                    orden[x] = orden[r];
                    orden[r] = temp;
                }

                // busca planta vecina
                for(int k = 0; k < 4; k++){
                    int ni = i + df[orden[k]];
                    int nj = j + dc[orden[k]];
                    if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                        if(dynamic_cast<Planta*>(matriz[ni][nj]) != nullptr){
                            delete matriz[ni][nj];
                            matriz[ni][nj] = matriz[i][j];
                            matriz[ni][nj]->setEnergia(matriz[ni][nj]->getEnergia() + 10);
                            matriz[i][j] = nullptr;
                            comio = true;
                            break;
                        }
                    }
                }

                // si no comió, se mueve a celda vacía
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






    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            if(dynamic_cast<Carnivoro*>(matriz[i][j]) != nullptr){
                bool comio = false;  // Se resetea para cada carnivoro

                int orden[] = {0, 1, 2, 3};
                for(int x = 3; x > 0; x--){
                    int r = rand() % (x+1);
                    int temp = orden[x];
                    orden[x] = orden[r];
                    orden[r] = temp;
                }

                // busca herbivoro vecino
                for(int k = 0; k < 4; k++){
                    int ni = i + df[orden[k]];
                    int nj = j + dc[orden[k]];
                    if(ni >= 0 && ni < filas && nj >= 0 && nj < columnas){
                        if(dynamic_cast<Herbivoro*>(matriz[ni][nj]) != nullptr){
                            delete matriz[ni][nj];
                            matriz[ni][nj] = matriz[i][j];
                            matriz[ni][nj]->setEnergia(matriz[ni][nj]->getEnergia() + 10);
                            matriz[i][j] = nullptr;
                            comio = true;
                            break;
                        }
                    }
                }

                // si no comio, se mueve a celda vacia
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


    for(int i = 0; i < filas ; i++){
        for(int j = 0; j < columnas; j++){
             if(dynamic_cast<Planta*>(matriz[i][j]) != nullptr){
                if(rand() % 100 < 10){  // 30% de probabilidad
                     // busca planta vecina
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






