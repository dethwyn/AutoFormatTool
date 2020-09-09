#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
}

void UserActions::menuSettings_triggered() {
    emit runRenderGUI();
}

void UserActions::bPath_clicked() {
    emit runRenderGUI();
}

void UserActions::bFormat_clicked() {
    emit runRenderGUI();
}

void UserActions::bRefresh_clicked() {
    emit runRenderGUI();
}

void UserActions::tbPath_textChanged(const QString &arg1) {
    emit runRenderGUI();
}

void UserActions::deleteFile(int pos) {
    emit runRenderGUI();
}
