#include "ventanainicial.h"
#include "ui_ventanainicial.h"
#include "ventanatriada.h"

// Constructor de la ventana inicial
VentanaInicial::VentanaInicial(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::VentanaInicial)
{
    ui->setupUi(this);
    // Estilo visual de la ventana
    this->setStyleSheet("QDialog { border-image: url(:/ventana_inicial.png) 0 0 0 0 stretch stretch; }");
}

// Destructor : libera la memoria usada por la interfaz
VentanaInicial::~VentanaInicial()
{
    delete ui;
}

// Slot que se ejecuta cuando se hace clic en el boton de 8x8
void VentanaInicial::on_boton8x8_clicked()
{
    VentanaTriada *ventana = new VentanaTriada(8,8);
    ventana->show();
    this->close();
}

// Slot que se ejecuta cuando se hace clic en el boton de 10x10

void VentanaInicial::on_boton10x10_clicked()
{
    VentanaTriada *ventana = new VentanaTriada(10,10);
    ventana->show();
    this->close();
}