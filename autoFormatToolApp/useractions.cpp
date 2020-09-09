#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
    userSettings = new Settings();
}

void UserActions::menuSettings_triggered() {
    emit runRenderGUI();
}

void UserActions::bPath_clicked(QString path) {
    auto instance = &State::getInstance();
    instance->setLinePathText(path);
    emit runRenderGUI();
}

void UserActions::bFormat_clicked() {
    auto instance = &State::getInstance();
    if(instance->getListFilesStringList()->count() != 0) {
        QString uncrustifyPath = instance->getLinePathUcText();
        QString uncrustifyConfigPath = instance->getLinePathCfgText();
        QFile UC(uncrustifyPath);
        QFile UCcfg(uncrustifyConfigPath);
        if(!UC.exists()) {
            emit showMessageBox("Не найден файл uncrustify.exe, проверьте настройки");
            emit runRenderGUI();
            return;
        }
        if(!UCcfg.exists()) {
            emit showMessageBox("Не найден файл конфигурации, проверьте настройки");
            emit runRenderGUI();
            return;
        }
        double progresBarStep = round(100.0 / instance->getListFilesStringList()->count());
        double currentProgressBarValue = 0;
        instance->setProgressBarValue(static_cast<int>(currentProgressBarValue));
        while(instance->getListFilesStringList()->count() > 0) {
            QString command("powershell.exe");
            QString path = instance->getLinePathText();
            QString fileName = instance->getListFilesStringList()->takeFirst();
            QString pathToFile(path + "/" + fileName);
            QStringList params;
            QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
            params.append(param.arg(uncrustifyPath).arg(uncrustifyConfigPath).arg(pathToFile));
            int result = QProcess::execute(command, params);
            qDebug() << result;
            currentProgressBarValue += progresBarStep;
            instance->setProgressBarValue(static_cast<int>(currentProgressBarValue));
            emit runRenderGUI();
        }
        instance->setProgressBarValue(100);
        emit showMessageBox("Форматирование завершено");
    } else {
        emit showMessageBox("Не выбран ни один файл с исходным кодом!");
    }
    emit runRenderGUI();
}

void UserActions::bRefresh_clicked() {
    auto instance = &State::getInstance();
    UserActions::tbPath_textChanged(instance->getLinePathText());
}

void UserActions::tbPath_textChanged(const QString &text) {
    auto instance = &State::getInstance();
    instance->setLinePathText(text);
    QDir dir;
    if(dir.exists(text)) {
        instance->getListFilesStringList()->clear();
        dir.setPath(text);
        dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
        QStringList files = dir.entryList();
        foreach(auto item, files) {
            instance->addItemListFiles(item);
        }
    }
    emit runRenderGUI();
}

void UserActions::deleteFile(int pos) {
    auto instance = &State::getInstance();
    if(instance->getListFilesStringList()->count() > 0) {
        instance->deleteItemListFiles(pos);
    }
    emit runRenderGUI();
}
