#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QFile>

class Settings {
public:
    explicit Settings(QObject *parent = nullptr);
    QString pathUC;
    QString pathCFG;
    int progressBarType;
    QString pathLastSource;
    void loadSettings();
    void updateSettings(QString pUC = "", QString pCFG = "", int pbType = 0, QString pLast = "");
    void saveSettins();
};

#endif // SETTINGS_H
