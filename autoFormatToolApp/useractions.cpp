#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
    auto instance = &State::getInstance();
    settings = new Settings();
    instance->setLinePathUcText(settings->pathUC);
    instance->setLinePathCfgText(settings->pathCFG);
    instance->setLinePathText(settings->pathLastSource);
    instance->setProgressBarType(settings->progressBarType);
    emit runRenderGUI();
}

void UserActions::menuSettings_triggered() {
    emit runRenderGUI();
}

void UserActions::bPath_clicked(const QString &path) {
    auto instance = &State::getInstance();
    instance->setLinePathText(path);
    auto pathUc = instance->getLinePathUcText();
    auto pathCfg = instance->getLinePathCfgText();
    auto lastPath = path;
    auto pbType = instance->getProgressBarType();
    settings->updateSettings(pathUc, pathCfg, pbType, lastPath);
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
    tbPath_textChanged(instance->getLinePathText());
}

void UserActions::tbPath_textChanged(const QString &text) {
    auto instance = &State::getInstance();
    instance->setLinePathText(text);
    QDir dir(text);
    if(dir.exists(text)) {
        instance->getListFilesStringList()->clear();
        dir.setPath(text);
        dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
        QStringList files = dir.entryList();
        foreach(auto item, files) {
            instance->addItemListFiles(item);
        }
    } else {
        instance->getListFilesStringList()->clear();
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

void UserActions::tbPathToUC_textChanged(const QString &arg1) {
    auto instance = &State::getInstance();
    instance->setLinePathUcText(arg1);
    emit runRenderGUI();
}

void UserActions::tbPathToCfgUC_textChanged(const QString &arg1) {
    auto instance = &State::getInstance();
    instance->setLinePathCfgText(arg1);
    emit runRenderGUI();
}

void UserActions::bSaveSettings_clicked() {
    auto instance = &State::getInstance();
    auto pathUc = instance->getLinePathUcText();
    auto pathCfg = instance->getLinePathCfgText();
    auto lastPath = "";
    auto pbType = instance->getProgressBarType();
    settings->updateSettings(pathUc, pathCfg, pbType, lastPath);
    emit runRenderGUI();
}

void UserActions::bOpenPathUC_clicked(const QString &path) {
    auto instance = &State::getInstance();
    if(path != "") {
        instance->setLinePathUcText(path);
    }
    emit runRenderGUI();
}

void UserActions::bOpenPathCfgUC_clicked(const QString &path) {
    auto instance = &State::getInstance();
    if(path != "") {
        instance->setLinePathCfgText(path);
    }
    emit runRenderGUI();
}

void UserActions::bCloseSettingsWindow_clicked() {
    // auto instance = &State::getInstance();

    emit runRenderGUI();
}
