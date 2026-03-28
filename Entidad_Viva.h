#ifndef ENTIDAD_VIVA_H
#define ENTIDAD_VIVA_H

class EntidadViva{

protected:
     int pos_x;
     int pos_y;
     int energia;
     int edad;
     bool estado;
 public:
     bool estaViva() { return estado; }
    virtual void actuar() = 0;
    EntidadViva(int px, int py, int e);
    void setEnergia(int e) { energia = e; }
    int getEnergia() { return energia; }


virtual ~EntidadViva() = default;
};








#endif // ENTIDAD_VIVA_H
