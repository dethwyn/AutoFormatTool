#include "state.h"

QString State::getMenuFileText() {
    return menuFileText;
}

QString State::getMenuSettingText() {
    return menuSettingText;
}

QString State::getMenuExitText() {
    return menuExitText;
}

QString State::getButtonBrowseText() {
    return buttonBrowseText;
}

QString State::getLinePathText() {
    return linePathText;
}

QString State::getLabelPathText() {
    return labelPathText;
}

QString State::getButtonRefreshText() {
    return buttonRefreshText;
}

QStringList *State::getListFilesStringList() {
    return listFilesStringList;
}

QString State::getButtonFormatText() {
    return buttonFormatText;
}

int State::getProgressBarValue() {
    return progressBarValue;
}

int State::getProgressBarType() {
    return progressBarType;
}
