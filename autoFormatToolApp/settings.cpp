#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent) {
}

void Settings::loadSettings() {
}

void Settings::updateSettings(QString pUC, QString pCFG, int pbType, QString pLast) {
    Settings::pathUC = pUC;
    Settings::pathCFG = pCFG;
    Settings::progressBarType = pbType;
    Settings::pathLastSource = pLast;
}
