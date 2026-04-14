#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ecosistema.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// Clase principal de la interfaz grafica
// Se encarga de mostrar la matriz, los contadores y conectar los botones con la logica del ecosistema
class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    // Se llama automaticamente cada vez que Qt necesita redibujar la ventana
    void paintEvent(QPaintEvent *event) override;

public:
    explicit MainWindow(int filas, int columnas, int tema, QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void onIniciar();    // Inicia la simulacion arrancando el timer
    void onPausar();     // Pausa la simulacion deteniendo el timer
    void onReiniciar();  // Reinicia el ecosistema al estado inicial
    void onTick();       // Se ejecuta en cada tick del timer (un ciclo de simulacion)

private slots:
    // Slots conectados automáticamente a los botones del diseñador visual
    void on_pushButton_clicked();    // Boton Iniciar
    void on_pushButton_2_clicked();  // Boton Pausar
    void on_pushButton_3_clicked();  // Boton Reiniciar

private:
    Ui::MainWindow *ui;       // Interfaz grafica generada por Qt
    Ecosistema ecosistema;    // Logica del ecosistema (separada de la interfaz)
    QTimer* timer;            // Timer que controla el avance automatico de ciclos

    int filasTablero;         // Cantidad de filas elegidas por el usuario
    int columnasTablero;      // Cantidad de columnas elegidas por el usuario
    int temaSeleccionado;     // 0 = Bosque, 1 = Pradera
};

#endif // MAINWINDOW_H