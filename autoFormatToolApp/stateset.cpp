#include "state.h"

void State::setMenuFileText(const QString &text) {
    menuFileText = text;
}

void State::setMenuSettingText(const QString &text) {
    menuSettingText = text;
}

void State::setMenuExitText(const QString &text) {
    menuExitText = text;
}

void State::setButtonBrowseText(const QString &text) {
    buttonBrowseText = text;
}

void State::setLinePathText(const QString &text) {
    linePathText = text;
}

void State::setLabelPathText(const QString &text) {
    labelPathText = text;
}

void State::setButtonRefreshText(const QString &text) {
    buttonRefreshText = text;
}

void State::setListFilesStringList(QStringList *list) {
    listFilesStringList = list;
}

void State::addItemListFiles(const QString &item) {
    listFilesStringList->append(item);
}

void State::deleteItemListFiles(int pos) {
    listFilesStringList->removeAt(pos);
}

void State::setButtonFormatText(const QString &text) {
    buttonFormatText = text;
}

void State::setProgressBarValue(int value) {
    progressBarValue = value;
}

void State::setProgressBarType(int type) {
    progressBarType = type;
}
