#include "state.h"
// Геттеры главного окна
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
QString State::getButtonFormatText() {
    return buttonFormatText;
}
int State::getProgressBarValue() {
    return progressBarValue;
}
int State::getProgressBarType() {
    return progressBarType;
}
int State::getProgressBarMax() const {
    return progressBarMax;
}
int State::getMinWndHeight() const {
    return wndMinHeight;
}
int State::getMinWndWidth() const {
    return wndMinWidth;
}
// Геттеры окна настроек
QString State::getButtonBrowseUcText() {
    return buttonBrowseText;
}
QString State::getLinePathUcText() {
    return linePathUcText;
}
QString State::getLabelPathUcText() {
    return labelPathUcText;
}
QString State::getButtonBrowseCfgText() {
    return buttonBrowseCfgText;
}
QString State::getLabelPathCfgText() {
    return labelPathCfgText;
}
QString State::getLinePathCfgText() {
    return linePathCfgText;
}
QString State::getButtonSaveText() {
    return buttonSaveText;
}
QString State::getButtonCloseText() {
    return buttonCloseText;
}
// Геттеры разного
QString State::getSecretCode() const {
    return secretCode;
}
QFileInfoList *State::getListFileInfos() const {
    return listFileInfos;
}
