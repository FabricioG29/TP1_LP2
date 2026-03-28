/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_plantas;
    QLabel *label_herbivoros;
    QLabel *label_Carnivoros;
    QLabel *label_Ciclo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 519);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(100, 430, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 430, 100, 32));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(430, 430, 100, 32));
        label_plantas = new QLabel(centralwidget);
        label_plantas->setObjectName("label_plantas");
        label_plantas->setGeometry(QRect(120, 410, 101, 16));
        label_herbivoros = new QLabel(centralwidget);
        label_herbivoros->setObjectName("label_herbivoros");
        label_herbivoros->setGeometry(QRect(270, 410, 101, 16));
        label_Carnivoros = new QLabel(centralwidget);
        label_Carnivoros->setObjectName("label_Carnivoros");
        label_Carnivoros->setGeometry(QRect(450, 410, 101, 16));
        label_Ciclo = new QLabel(centralwidget);
        label_Ciclo->setObjectName("label_Ciclo");
        label_Ciclo->setGeometry(QRect(580, 410, 58, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Pausar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reiniciar", nullptr));
        label_plantas->setText(QCoreApplication::translate("MainWindow", "Plantas : 0", nullptr));
        label_herbivoros->setText(QCoreApplication::translate("MainWindow", "Herbivoros: 0", nullptr));
        label_Carnivoros->setText(QCoreApplication::translate("MainWindow", "Carnivoros: 0", nullptr));
        label_Ciclo->setText(QCoreApplication::translate("MainWindow", "Ciclo: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
