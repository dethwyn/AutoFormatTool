/*
 * \file main.cpp
 * \brief Точка входа в программу
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    auto *a = new QApplication(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
