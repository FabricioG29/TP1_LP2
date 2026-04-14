#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Planta.h"
#include "Herbivoro.h"
#include "Carnivoro.h"
#include <QPainter>

// Constructor: inicializa la ventana con el tamaño y tema elegidos
MainWindow::MainWindow(int filas, int columnas, int tema, QWidget *parent)
    : QMainWindow(parent)              // Hereda de QMainWindow
    , ui(new Ui::MainWindow)          // Crea la interfaz
    , ecosistema(filas, columnas)    // Inicializa el ecosistema con tamaño
    , timer(nullptr)                // Inicializa el timer en null
    , filasTablero(filas)          //Guarda las filas del tablero
    , columnasTablero(columnas)   //Guarda las columnas del tablero
    , temaSeleccionado(tema)     // Guarda el tema elegido
{
    ui->setupUi(this);  //Inicializa todos los elementos visuales

    // Aplicamos imagen de fondo a la ventana
    this->setStyleSheet("QMainWindow { border-image: url(:/fondo_tablero.png) 0 0 0 0 stretch stretch; }");

    /*QString estiloNegro = "color: black; font-weight: bold; font-size: 14px;";
    ui->label_plantas->setStyleSheet(estiloNegro);
    ui->label_herbivoros->setStyleSheet(estiloNegro);
    ui->label_Carnivoros->setStyleSheet(estiloNegro);
    ui->label_Ciclo->setStyleSheet(estiloNegro);*/

    //Se crea el timer
    timer = new QTimer(this);

    // Cada vez que el timer haga tick, se llama a onTick()
    connect(timer, &QTimer::timeout, this, &MainWindow::onTick);

    // Inicializamos los textos de os labels
    ui->label_plantas->setText("PLANTAS: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("HERBIVOROS: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("CARNIVOROS: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("CICLO: " + QString::number(ecosistema.getCiclo()));
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

    //Actualiza los labels
    ui->label_plantas->setText("PLANTAS: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("HERBIVOROS: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("CARNIVOROS: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("CICLO: " + QString::number(ecosistema.getCiclo()));
}

// Se ejecuta en cada tick del timer: avanza un ciclo y actualiza la interfaz
void MainWindow::onTick(){
    ecosistema.flujo_tiempo();
    update();

    //Actualiza los datos en la pantalla
    ui->label_plantas->setText("PLANTAS: " + QString::number(ecosistema.getCantPlantas()));
    ui->label_herbivoros->setText("HERBIVOROS: " + QString::number(ecosistema.getCantHerbivoros()));
    ui->label_Carnivoros->setText("CARNIVOROS: " + QString::number(ecosistema.getCantCarnivoros()));
    ui->label_Ciclo->setText("CICLO: " + QString::number(ecosistema.getCiclo()));
}

// Dibuja la matriz en cada actualizacion visual
// Cada celda se colorea segun el tipo de entidad que contiene:
// Verde = Planta, Azul = Herbivoro, Rojo = Carnivoro
void MainWindow::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    QPainter painter(this);

    int tamCelda;

    // Ajustamos el tamaño de celda segun el tamaño del tablero
    if(filasTablero == 5)
        tamCelda = 70;
    else if(filasTablero == 8)
        tamCelda = 50;
    else
        tamCelda = 40;

    int filas = filasTablero;
    int columnas = columnasTablero;

    //Calcula el tamaño total del tablero
    int anchoTablero = columnas * tamCelda;
    int altoTablero = filas * tamCelda;

    // Tamaño y posicion del fondo celeste
    QRect cuadro(80, 80, 640, 510);

    // Calculo de la posicion inicial para centrar el tablero dentro del cuadro celeste
    int inicioX = cuadro.x() + (cuadro.width() - anchoTablero) / 2;
    int inicioY = cuadro.y() + (cuadro.height() - altoTablero) / 2;

    //Recorrer la matriz
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){

            int x = inicioX + j * tamCelda;
            int y = inicioY + i * tamCelda;

            // Dibujar celda
            painter.drawRect(x, y, tamCelda, tamCelda);

            // Obetenemos la entidad de esa celda
            EntidadViva* entidad = ecosistema.getCelda(i, j);

            // Plantas
            if(dynamic_cast<Planta*>(entidad)){
                QPixmap img;

                if(temaSeleccionado == 0)
                    img.load(":/bush.png");
                else
                    img.load(":/pasto.png");

                painter.drawPixmap(x, y, tamCelda, tamCelda, img);
            }

            // Herviboros
            else if(dynamic_cast<Herbivoro*>(entidad)){
                QPixmap img;

                if(temaSeleccionado == 0)
                    img.load(":/conejo.png");
                else
                    img.load(":/oveja.png");

                painter.drawPixmap(x, y, tamCelda, tamCelda, img);
            }

            // Carnivoros
            else if(dynamic_cast<Carnivoro*>(entidad)){
                QPixmap img;

                if(temaSeleccionado == 0)
                    img.load(":/zorro.png");
                else
                    img.load(":/lobo.png");

                painter.drawPixmap(x, y, tamCelda, tamCelda, img);
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