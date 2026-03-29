#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Planta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include <QPainter>

// Constructor: inicializa la ventana, el ecosistema y conecta el timer al slot onTick
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ecosistema(8, 8)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    // Cada vez que el timer haga tick, se llama a onTick()
    connect(timer, &QTimer::timeout, this, &MainWindow::onTick);
}

// Inicia la simulacion: el timer dispara cada 500ms
void MainWindow::onIniciar(){
    timer->start(500);
}

// Pausa la simulacion: detiene el timer sin perder el estado actual
void MainWindow::onPausar(){
    timer->stop();
}

// Reinicia la simulacion: detiene el timer, resetea el ecosistema y actualiza la interfaz
void MainWindow::onReiniciar(){
    timer->stop();
    ecosistema.reiniciar();
    update();
    ui->label_plantas->setText("Plantas: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("Herbívoros: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("Carnívoros: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("Ciclo: " + QString::number(ecosistema.getCiclo()));
}

// Se ejecuta en cada tick del timer: avanza un ciclo y actualiza la interfaz
void MainWindow::onTick(){
    ecosistema.flujo_tiempo();
    update(); // redibuja la grilla
    ui->label_plantas->setText("Plantas: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("Herbívoros: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("Carnívoros: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("Ciclo: " + QString::number(ecosistema.getCiclo()));
}

// Dibuja la matriz en cada actualizacion visual
// Cada celda se colorea segun el tipo de entidad que contiene:
// Verde = Planta, Azul = Herbivoro, Rojo = Carnivoro
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int tamCelda = 50;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            painter.drawRect(j*tamCelda, i*tamCelda, tamCelda, tamCelda);

            EntidadViva* entidad = ecosistema.getCelda(i, j);
            if(dynamic_cast<Planta*>(entidad)){
                QPixmap img(":/bush.png");
                painter.drawPixmap(j*tamCelda, i*tamCelda, tamCelda, tamCelda, img);
            }
            else if(dynamic_cast<Herbivoro*>(entidad)){
                QPixmap img(":/conejo.png");
                painter.drawPixmap(j*tamCelda, i*tamCelda, tamCelda, tamCelda, img);
            }

            else if(dynamic_cast<Carnivoro*>(entidad)){
                QPixmap img(":/lobo.png");
                painter.drawPixmap(j*tamCelda, i*tamCelda, tamCelda, tamCelda, img);
            }
        }
    }
}

// Destructor: libera la memoria de la interfaz grafica
MainWindow::~MainWindow()
{
    delete ui;
}

// Boton Iniciar
void MainWindow::on_pushButton_clicked(){
    onIniciar();
}

// Boton Pausar
void MainWindow::on_pushButton_2_clicked(){
    onPausar();
}

// Boton Reiniciar
void MainWindow::on_pushButton_3_clicked(){
    onReiniciar();
}