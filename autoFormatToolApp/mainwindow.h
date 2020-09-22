/*
 * \file mainwindow.h
 * \brief Объявление класса MainWindow
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingform.h"
#include "nyancatprogressbar.h"
#include "useractions.h"
#include "state.h"

#include <QDebug>
#include <QMainWindow>
#include <QFileDialog>
#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE
/*
 * \class MainWindow
 * \brief Класс основного окна приложения
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // конструктор по умолчанию (qt)
    MainWindow(QWidget *parent = nullptr);
    // деструктор
    ~MainWindow() override;

public slots:
    // слот рендера GUI (извлекает данные из State и заносит в нужные поля виджетов)
    void renderGUI();
    // слот вызова окон сообщений
    void showMessageBox(const QString &message);

private slots:
    // слот для сигнала нажатия на кнопку выход в меню
    void on_menuExit_triggered();
    // слот для сигнала нажатия на кнопку настройки в меню
    void on_menuSettings_triggered();
    // слот для сигнала нажатия на кнопку обзор в меню
    void on_bPath_clicked();
    // слот для сигнала нажатия на кнопку форматировать в меню
    void on_bFormat_clicked();
    // слот для сигнала нажатия на кнопку обновить в меню
    void on_bRefresh_clicked();
    // слот для сигнала ввода текста в поле ввода
    void on_tbPath_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui; // графический интерфейс, получаемый из ui-файла
    NyanCatProgressBar *progressBar; // пользовательский прогрессбар
    UserActions *userActions; // обработчик действий пользователя
    QFileDialog *selectDirDialog; // файл-диалог выбор папки с исходниками
    // функция подключения слотов
    void connectSlots();
    // функция дополнительной настройки GUI
    void configureUi();

protected:
    // переоопределения обработчика события нажатия клавиши на клавиатуре
    virtual void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
