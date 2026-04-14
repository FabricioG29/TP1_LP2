#include "ventanatriada.h"
#include "mainwindow.h"
#include "ui_ventanatriada.h"

// Constructor de la ventana triada
VentanaTriada::VentanaTriada(int filas, int columnas, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ventanatriada)
    , filasTablero(filas)
    , columnasTablero(columnas)
{
    ui->setupUi(this);
    // Estilo visual de la ventana
    this->setStyleSheet("QDialog { border-image: url(:/ventana_triada.png) 0 0 0 0 stretch stretch; }");
}

// Destructor : libera memoria usada por la interfaz grafica
VentanaTriada::~VentanaTriada()
{
    delete ui;
}

// Slot que se ejecuta cuando se hace clic en el boton bosque
void VentanaTriada::on_botonBosque_clicked()
{
    int tema = 0;
    MainWindow *ventana = new MainWindow(filasTablero, columnasTablero, tema);
    ventana->show();
    this->close();
}

// Slot que se ejecuta cuando se hace clic en el boton campo
void VentanaTriada::on_botonCampo_clicked()
{
    int tema = 1;
    MainWindow *ventana = new MainWindow(filasTablero, columnasTablero, tema);
    ventana->show();
    this->close();
}