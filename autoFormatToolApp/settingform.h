/*
 * \file settingform.h
 * \brief Объявление класса SettingForm
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include "useractions.h"

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
    class SettingForm;
}
/*
 * \class SettingForm
 * \brief Класс окна настроек
 */
class SettingForm : public QWidget {
    Q_OBJECT

public:
    // конструктор по умолчанию (qt)
    explicit SettingForm(UserActions *ua, QWidget *parent = nullptr);
    // деструктор
    ~SettingForm();
    QString pathToUC;
    QString pathToCfg;

public slots:
    // слот рендера GUI (извлекает данные из State и заносит в нужные поля виджетов)
    void renderGUI();

private slots:
    // слот для сигнала нажатия кнопки обзор для пути до UC
    void on_tbPathToUC_textChanged(const QString &arg1);
    // слот для сигнала нажатия кнопки обзор для пути до конфига
    void on_tbPathToCfgUC_textChanged(const QString &arg1);
    // слот для сигнала нажатия кнопки сохранить
    void on_bSaveSettings_clicked();
    // слот для сигнала нажатия кнопки обзор для пути до UC
    void on_bOpenPathUC_clicked();
    // слот для сигнала нажатия кнопки обзор для пути до конфига
    void on_bOpenPathCfgUC_clicked();
    // слот для сигнала нажатия кнопки закрыть
    void on_bCloseSettingsWindow_clicked();

private:
    Ui::SettingForm *ui; // пользовательский интерфейс, получаемый из ui файла
    UserActions *userActions; // обработчик действий пользователя (берем из конструктора)
    // функция подключения слотов
    void connectSlots();
    // функция дополнительной настройки GUI
    void createGUI();
    QFileDialog *ucFileDialog; // диалог поиска uncrustify.exe
    QFileDialog *cfgFileDialog; // диалог поиска конфига
};
#endif // SETTINGFORM_H
