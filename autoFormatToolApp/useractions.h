#ifndef USERACTIONS_H
#define USERACTIONS_H

#include "settings.h"
#include "state.h"

#include <QObject>
#include <QFileDialog>
#include <QtMath>
#include <QProcess>

class UserActions : public QObject {
    Q_OBJECT
public:
    explicit UserActions(QObject *parent = nullptr);
    // Методы основного окна
    void menuSettings_triggered();
    void bPath_clicked(QString path);
    void bFormat_clicked();
    void bRefresh_clicked();
    void tbPath_textChanged(const QString &arg1);
    void deleteFile(int pos);
    // Методы окна настроек
    void tbPathToUC_textChanged(const QString &arg1);
    void tbPathToCfgUC_textChanged(const QString &arg1);
    void bSaveSettings_clicked();
    void bOpenPathUC_clicked(const QString &path);
    void bOpenPathCfgUC_clicked(const QString &path);
    void bCloseSettingsWindow_clicked();
signals:
    void runRenderGUI();
    void showMessageBox(QString);
public slots:
};

#endif // USERACTIONS_H
