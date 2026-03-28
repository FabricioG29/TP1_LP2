#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Planta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ecosistema(8, 8)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTick);
}


void MainWindow::onIniciar(){
    timer -> start(500);

}

void MainWindow::onPausar(){
    timer -> stop();
}

void MainWindow::onReiniciar(){
    timer->stop();
    ecosistema.reiniciar();
    update();
    ui->label_plantas->setText("Plantas: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("Herbívoros: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("Carnívoros: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("Ciclo: " + QString::number(ecosistema.getCiclo()));
}
void MainWindow::onTick(){
    ecosistema.flujo_tiempo();
    update();
    ui->label_plantas->setText("Plantas: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("Herbívoros: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("Carnívoros: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("Ciclo: " + QString::number(ecosistema.getCiclo()));
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    int tamCelda = 50; // tamaño de cada celda en pixels

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            // dibuja el borde de la celda
            painter.drawRect(j*tamCelda, i*tamCelda, tamCelda, tamCelda);

            EntidadViva* entidad = ecosistema.getCelda(i, j);
            if(dynamic_cast<Planta*>(entidad)){
                painter.fillRect(j*tamCelda+1, i*tamCelda+1, tamCelda-1, tamCelda-1, Qt::green);
            } else if(dynamic_cast<Herbivoro*>(entidad)){
                painter.fillRect(j*tamCelda+1, i*tamCelda+1, tamCelda-1, tamCelda-1, Qt::blue);
            } else if(dynamic_cast<Carnivoro*>(entidad)){
                painter.fillRect(j*tamCelda+1, i*tamCelda+1, tamCelda-1, tamCelda-1, Qt::red);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    onIniciar();
}


void MainWindow::on_pushButton_2_clicked()
{
    onPausar();
}


void MainWindow::on_pushButton_3_clicked()
{
    onReiniciar();
}

