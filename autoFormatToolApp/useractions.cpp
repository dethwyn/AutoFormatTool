/*
 * \file useractions.cpp
 * \brief Реализация класса UserActions
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
    auto instance = &State::getInstance();
    settings = new Settings();
    instance->setLinePathUcText(settings->pathUC);
    instance->setLinePathCfgText(settings->pathCFG);
    instance->setLinePathText(settings->pathLastSource);
    instance->setProgressBarType(settings->progressBarType);
    ffw = new FormatFileWorker();
    emit runRenderGUI();
}

UserActions::~UserActions() {
    delete settings;
}

void UserActions::menuSettings_triggered() {
    emit runRenderGUI();
}

void UserActions::bPath_clicked(const QString &path) {
    auto instance = &State::getInstance();
    instance->setLinePathText(path);

    emit runRenderGUI();
}

void UserActions::bFormat_clicked() {
    auto instance = &State::getInstance();
    instance->setProgressBarValue(0);
    if(instance->getListFileInfos()->count() != 0) {
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
        ffw->start();
    } else {
        emit showMessageBox("Не выбран ни один файл с исходным кодом!");
    }
    emit runRenderGUI();
}

void UserActions::bRefresh_clicked() {
    auto instance = &State::getInstance();
    instance->setProgressBarValue(0);
    tbPath_textChanged(instance->getLinePathText());
}

void UserActions::tbPath_textChanged(const QString &text) {
    auto instance = &State::getInstance();
    instance->setLinePathText(text);
    auto pathUc = instance->getLinePathUcText();
    auto pathCfg = instance->getLinePathCfgText();
    auto pbType = instance->getProgressBarType();
    settings->updateSettings(pathUc, pathCfg, pbType, text);
    instance->getListFileInfos()->clear();
    if(text != "") {
        QDir dir(text);
        if(dir.exists(text)) {
            recourceFileFind(text);
        } else {
            instance->getListFileInfos()->clear();
        }
    }
    emit runRenderGUI();
}

void UserActions::deleteFile(int pos) {
    auto instance = &State::getInstance();
    if(instance->getListFileInfos()->count() > 0) {
        instance->deleteItemListFileInfos(pos);
    }
    emit runRenderGUI();
}

void UserActions::inputSecretCode(const QString &symbol) {
    auto instance = &State::getInstance();
    instance->setSecretCode(instance->getSecretCode() + symbol);
    if(instance->getSecretCode() == "nyancat") {
        instance->setProgressBarValue(0);
        instance->setSecretCode("");
        instance->setProgressBarType(1);
    }  else if(instance->getSecretCode() == "default") {
        instance->setProgressBarValue(0);
        instance->setSecretCode("");
        instance->setProgressBarType(0);
    } else if(instance->getSecretCode().count() >= 7) {
        instance->setSecretCode("");
        instance->setProgressBarType(0);
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
    emit runRenderGUI();
}

void UserActions::threadHandler(int pbValue) {
    auto instance = &State::getInstance();
    instance->setProgressBarValue(static_cast<int>(pbValue));
    emit runRenderGUI();
}

void UserActions::threadComplete(int problemCnt) {
    QString result = "Форматирование завершено\nС ошибкой - %1";
    emit showMessageBox(result.arg(problemCnt));
}

void UserActions::recourceFileFind(const QString &basePath) {
    auto instance = &State::getInstance();
    QDir dir(basePath);
    dir.setFilter(QDir::Dirs);
    auto cleanDir = dir.entryList();
    cleanDir.removeAll("..");
    cleanDir.removeAll(".");
    if(cleanDir.count() > 0) {
        for(int i = 0; i < cleanDir.count(); i++) {
            recourceFileFind(basePath + "/" + cleanDir[i]);
        }
    } else {
        dir.setFilter(QDir::Files);
        dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
        QFileInfoList fileInfos = dir.entryInfoList();
        foreach(auto item, fileInfos) {
            instance->addItemListFileInfos(item);
        }
    }
    auto ucPath = settings->pathUC;
    auto cfgPath = settings->pathCFG;
    auto fList = instance->getListFileInfos();
    auto maxPB = instance->getProgressBarMax();
    ffw = new FormatFileWorker(maxPB, fList, ucPath, cfgPath);
    connect(ffw, &FormatFileWorker::step, this, &UserActions::threadHandler);
    connect(ffw, &FormatFileWorker::completed, this, &UserActions::threadComplete);
}
