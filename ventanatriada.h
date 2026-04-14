#ifndef VENTANATRIADA_H
#define VENTANATRIADA_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ventanatriada;
}
QT_END_NAMESPACE

// Definicion de la clase VentanaTriada
class VentanaTriada : public QDialog
{
    Q_OBJECT

public:
    // Constructor: recibe las filas y columnas del tablero
    explicit VentanaTriada(int filas, int columnas, QWidget *parent = nullptr);
    ~VentanaTriada();

private slots:
    void on_botonBosque_clicked(); // Slot que se ejecuta al hacer click en el BotonBosque
    void on_botonCampo_clicked(); // Slot que se ejecuta al hacer click en el BotonCampo

private:
    Ui::ventanatriada *ui;
    int filasTablero;      // Guardamos la cantidad de filas del tablero
    int columnasTablero;  // Guardamos la cantidad de columnas del tablero
};

#endif // VENTANATRIADA_H