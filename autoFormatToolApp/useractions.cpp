#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
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
