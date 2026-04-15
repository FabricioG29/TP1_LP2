# TP1_LP2
Tp1-lp2 Simulador de Ecosistema 
## Integrantes: Fabricio Gonzalez, Irina Insfran

## Descripcion del proyecto 
El proyecto consiste en la implementacion de un simulador de ecosistema desarrollado en C++ y Qt
El sistema repesenta un tablero bidimensional (matriz) donde actuan distintas entidades vivas:
- Plantas
- Carnivoros
- Herbivoros
Cada una de estas entidades posee comportamientos propios como moverse por la grilla, alimentarse y morir,
generando asi una simulacion dinamica que va evolucionando en el tiempo mediante ciclos

## Funcionalidad principal
- Representacion grafica del ecosistema
- Simulacion automaticca mediante un temporizador
- Interaccion entre las entidades
- Finalizacion del juego cuando no quedan entidades 

## Estructura del proyecto 
Clases principales:
- EntidadViva : clase abstracta
- Planta, Herbivoro, Carnivoro : clases derivadas
- Ecosistema : Maneja la logica del tablero
- Ventana Inicial : Seleccion del tamaño del tablero 
- Ventana Triada : Seleccion del tipo de entorno 

## Requisitos
- Qt Creator 
- Compilador compatible con C++

## Compilacion y Ejecucion 
- Abrir el proyecto en Qt Creator 
- Seleccionar el kit de compilacion 
- Ejecutar 

## Uso del programa
- Ventana Inicial : Selecccionar el tamaño del tablero (8x8 o 10x10)
- Ventana Triada : Seleccionar el tipo de entorno en forma de triada (arbusto,conejo,zorro o cesped,oveja,lobo)
- Iniciar la simulacion
- Observar el comportamiento de las entidades
