#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QFile>
#include <utility>

class Settings {
public:
    explicit Settings(QObject *parent = nullptr);
    QString pathUC;
    QString pathCFG;
    int progressBarType;
    QString pathLastSource;
    void loadSettings();
    void updateSettings(const QString &pUC, const QString &pCFG, int pbType, const QString &pLast);
    void saveSettins();
};

#endif // SETTINGS_H
