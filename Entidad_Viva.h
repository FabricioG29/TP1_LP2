#ifndef ENTIDAD_VIVA_H
#define ENTIDAD_VIVA_H


// Clase Base EntidadViva
class EntidadViva{

protected: // Protected para que las clases hijas puedan acceder

     int pos_x;
     int pos_y;
     int energia;
     int edad;
     bool estado;
 public:

     bool estaViva() { return estado; } // Funcion para verificar si esta vivo o no

    virtual void actuar() = 0;   // Metodo puro que cada subclase debe implementar

    EntidadViva(int px, int py, int e);  // Le pasamos al constructor las posiciones y la energia de cada Entidad

    void setEnergia(int e) { energia = e; }  // Seteamos la energia

    int getEnergia() { return energia; }  // Obtenemos cuanta energia tiene la entidad


virtual ~EntidadViva() = default;  // Destructor virtual para manejo seguro de herencia
};








#endif // ENTIDAD_VIVA_H
