/*
 * \file useractions.h
 * \brief Объявление класса UserActions
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef USERACTIONS_H
#define USERACTIONS_H

#include "settings.h"
#include "state.h"
#include "formatfileworker.h"

#include <QObject>
#include <QFileDialog>
#include <QtMath>
#include <QProcess>
#include <QSettings>

class UserActions : public QObject {
    Q_OBJECT
public:
    explicit UserActions(QObject *parent = nullptr);
    ~UserActions();
    Settings *settings;
    // Методы основного окна
    // Обработка нажатия кнопки настроек в меню
    void menuSettings_triggered();
    // Обработка нажатия кнопки открытия папки с исходниками
    void bPath_clicked(const QString &path);
    // Обработка нажатия кнопки форматирования
    void bFormat_clicked();
    // Обработка нажатия кнопки обновления списка файлов
    void bRefresh_clicked();
    // Обработка ввода текста в строку пути
    void tbPath_textChanged(const QString &arg1);
    // Обработка удаления файла из списка
    void deleteFile(int pos);
    // Обработка ввода секретного кода
    void inputSecretCode(const QString &symbol);
    // Методы окна настроек
    // Обработка ввода текста в строку пути до UC
    void tbPathToUC_textChanged(const QString &arg1);
    // Обработка ввода текста в строку пути до конфига
    void tbPathToCfgUC_textChanged(const QString &arg1);
    // Обработка нажатия кнопки сохранения настроек
    void bSaveSettings_clicked();
    // Обработка нажатия кнопки выбора исполняемого файла
    void bOpenPathUC_clicked(const QString &path);
    // Обработка нажатия кнопки выбора файла конфигурации
    void bOpenPathCfgUC_clicked(const QString &path);
    // Обработка нажатия кнопки обновления списка файлов
    void bCloseSettingsWindow_clicked();
public slots:
    // Слот обработчик работы потока
    void threadHandler(int pbValue);
    // Слот обработки завершения работы потока
    void threadComplete(int problemCnt);
private:
    // Метод поиска файлов в подпапках
    void recourceFileFind(const QString &basePath);
    FormatFileWorker *ffw; //указатель на поток-обработчик файлов
signals:
    // сигнал для перерендера GUI
    void runRenderGUI();
    // сигнал для показа MessageBox
    void showMessageBox(QString);
};

#endif // USERACTIONS_H
