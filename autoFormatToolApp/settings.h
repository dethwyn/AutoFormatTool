/*
 * \file settings.h
 * \brief Объявление класса Settings
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QFile>
#include <utility>
/*
 * \class Settings
 * \brief Класс загрузки и сохранения настроек
 */
class Settings {
public:
    explicit Settings(QObject *parent = nullptr);
    QString pathUC; // путь до uncrustify
    QString pathCFG; // путь до конфига
    int progressBarType; // тип прогрессбара
    QString pathLastSource; // последний путь до сорцов
    // функция загрузки настроек
    void loadSettings();
    // функция обновления настроек
    void updateSettings(const QString &pUC, const QString &pCFG, int pbType, const QString &pLast);
    // функция сохранения настроек
    void saveSettins();
};

#endif // SETTINGS_H
