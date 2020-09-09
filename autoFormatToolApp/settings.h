#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject {
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    static QString pathUC;
    static QString pathCFG;
    static int progressBarType;
    static QString pathLastSource;
    static void loadSettings();
    static void updateSettings(QString pUC = "", QString pCFG = "", int pbType = 0, QString pLast = "");
signals:
public slots:
};

#endif // SETTINGS_H
