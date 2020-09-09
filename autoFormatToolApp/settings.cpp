#include "settings.h"

Settings::Settings(QObject *parent) {
    loadSettings();
}

void Settings::loadSettings() {
    QFile file("settings.ini");
    QStringList strings;
    file.open(QFile::ReadOnly);
    while(file.atEnd()){
        strings.append(file.readLine());
    }

}

void Settings::updateSettings(QString pUC, QString pCFG, int pbType, QString pLast) {
    pathUC = pUC;
    pathCFG = pCFG;
    progressBarType = pbType;
    pathLastSource = pLast;
}
