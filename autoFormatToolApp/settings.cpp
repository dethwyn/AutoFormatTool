#include "settings.h"

Settings::Settings(QObject *parent) {
    loadSettings();
}

void Settings::loadSettings() {
    QFile iniFile("settings.ini");
    QStringList iniList;
    if(iniFile.exists() && iniFile.open(QIODevice::ReadOnly)) {
        while(!iniFile.atEnd()) {
            QString temp = iniFile.readLine();
            iniList << temp.remove('\r').remove('\n');
        }
        iniFile.close();
        QList<QStringList> iniParameters;
        foreach(auto item, iniList) {
            iniParameters << item.split('=');
        }
        foreach(auto command, iniParameters) {
            if(command[0] == "path_to_uncrustify") {
                pathUC = command[1];
            } else if(command[0] == "path_to_config") {
                pathCFG = command[1];
            } else if(command[0] == "last_open_path") {
                pathLastSource = command[1];
            } else if(command[0] == "progress_bar_type") {
                progressBarType = command[1].toInt();
            }
        }
    }
}

void Settings::updateSettings(QString pUC, QString pCFG, int pbType, QString pLast) {
    pathUC = pUC;
    pathCFG = pCFG;
    progressBarType = pbType;
    pathLastSource = pLast;
    saveSettins();
}

void Settings::saveSettins() {
    QString iniPathUC = "path_to_uncrustify=%1";
    QString iniPathCFG = "path_to_config=%1";
    QString iniPathLastSource = "last_open_path=%1";
    QString iniProgressBarType = "progress_bar_type=%1";
    QFile iniFile("settings.ini");
    if(iniFile.open(QIODevice::WriteOnly)) {
        iniFile.write(iniPathUC.arg(pathUC).toUtf8() + "\n");
        iniFile.write(iniPathCFG.arg(pathCFG).toUtf8() + "\n");
        iniFile.write(iniPathLastSource.arg(progressBarType).toUtf8() + "\n");
        iniFile.write(iniProgressBarType.arg(pathLastSource).toUtf8() + "\n");
    }
}
