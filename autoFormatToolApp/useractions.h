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
    void menuSettings_triggered();
    void bPath_clicked(const QString &path);
    void bFormat_clicked();
    void bRefresh_clicked();
    void tbPath_textChanged(const QString &arg1);
    void deleteFile(int pos);
    void inputSecretCode(const QString &symbol);
    // Методы окна настроек
    void tbPathToUC_textChanged(const QString &arg1);
    void tbPathToCfgUC_textChanged(const QString &arg1);
    void bSaveSettings_clicked();
    void bOpenPathUC_clicked(const QString &path);
    void bOpenPathCfgUC_clicked(const QString &path);
    void bCloseSettingsWindow_clicked();
public slots:
    void threadHandler(int pbValue);
    void threadComplete(int problemCnt);
private:
    void recourceFileFind(const QString &basePath);
    FormatFileWorker *ffw;
signals:
    void runRenderGUI();
    void showMessageBox(QString);
};

#endif // USERACTIONS_H
