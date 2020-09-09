#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject {
    Q_OBJECT
public:
    explicit Settings(QObject *parent = nullptr);
    QString pathUC;
    QString pathCFG;
    int progressBarType;
    QString pathLastSource;
    void loadSettings();
    void updateSettings(QString pUC = "", QString pCFG = "", int pbType = 0, QString pLast = "");
signals:
public slots:
};

#endif // SETTINGS_H
