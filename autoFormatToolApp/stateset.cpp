#include "state.h"
// Cеттеры главного окна
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
void State::setButtonFormatText(const QString &text) {
    buttonFormatText = text;
}
void State::setProgressBarValue(int value) {
    progressBarValue = value;
}
void State::setProgressBarType(int type) {
    progressBarType = type;
}
void State::setProgressBarMax(int value) {
    progressBarMax = value;
}
void State::setMinWndWidth(int value) {
    wndMinWidth = value;
}
void State::setMinWndHeight(int value) {
    wndMinHeight = value;
}
// Cеттеры окна настроек
void State::setButtonBrowseUcText(const QString &text) {
    buttonBrowseUcText = text;
}
void State::setLinePathUcText(const QString &text) {
    linePathUcText = text;
}
void State::setLabelPathUcText(const QString &text) {
    labelPathUcText = text;
}
void State::setButtonBrowseCfgText(const QString &text) {
    buttonBrowseCfgText = text;
}
void State::setLabelPathCfgText(const QString &text) {
    labelPathCfgText = text;
}
void State::setLinePathCfgText(const QString &text) {
    linePathCfgText = text;
}
void State::setButtonSaveText(const QString &text) {
    buttonSaveText = text;
}
void State::setButtonCloseText(const QString &text) {
    buttonCloseText = text;
}
// Сеттеры разного
void State::setSecretCode(const QString &value) {
    secretCode = value;
}
void State::setListFileInfos(QFileInfoList *value) {
    listFileInfos = value;
}
void State::addItemListFileInfos(const QFileInfo &file) {
    listFileInfos->append(file);
}
void State::deleteItemListFileInfos(int pos) {
    listFileInfos->removeAt(pos);
}
