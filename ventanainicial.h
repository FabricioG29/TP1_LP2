#ifndef VENTANAINICIAL_H
#define VENTANAINICIAL_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class VentanaInicial;
}
QT_END_NAMESPACE

// Definicion de la clase Ventana Inicial
class VentanaInicial : public QDialog
{
    Q_OBJECT

public:
    // Constructor: crea la ventana
    explicit VentanaInicial(QWidget *parent = nullptr);
    ~VentanaInicial();

private slots:
    void on_boton8x8_clicked(); // Slot que se ejecuta cuando se hace click en el boton8x8
    void on_boton10x10_clicked(); // Slot que se ejecuta cuando se hace click en el boton10x10

private:
    Ui::VentanaInicial *ui;
};

#endif // VENTANAINICIAL_H