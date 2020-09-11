#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(UserActions *ua, QWidget *parent) :
    QWidget(parent), ui(new Ui::SettingForm) {
    userActions = ua;
    createGUI();
    connectSlots();
    renderGUI();
}

SettingForm::~SettingForm() {
    delete ucFileDialog;
    delete cfgFileDialog;
    delete ui;
}

void SettingForm::renderGUI() {
    auto instance = &State::getInstance();
    ui->lbUC->setText(instance->getLabelPathUcText());
    ui->lbCFG->setText(instance->getLabelPathCfgText());
    ui->tbPathToUC->setText(instance->getLinePathUcText());
    ui->tbPathToCfgUC->setText(instance->getLinePathCfgText());
    ui->bOpenPathUC->setText(instance->getButtonBrowseUcText());
    ui->bOpenPathCfgUC->setText(instance->getButtonBrowseCfgText());
    ui->bSaveSettings->setText(instance->getButtonSaveText());
    ui->bCloseSettingsWindow->setText(instance->getButtonCloseText());
}

void SettingForm::on_tbPathToUC_textChanged(const QString &arg1) {
    userActions->tbPathToUC_textChanged(arg1);
}

void SettingForm::on_tbPathToCfgUC_textChanged(const QString &arg1) {
    userActions->tbPathToCfgUC_textChanged(arg1);
}

void SettingForm::on_bOpenPathUC_clicked() {
    if(ucFileDialog->exec()) {
        userActions->bOpenPathUC_clicked(ucFileDialog->selectedFiles()[0]);
    }
}

void SettingForm::on_bOpenPathCfgUC_clicked() {
    if(cfgFileDialog->exec()) {
        userActions->bOpenPathCfgUC_clicked(cfgFileDialog->selectedFiles()[0]);
    }
}

void SettingForm::on_bSaveSettings_clicked() {
    userActions->bSaveSettings_clicked();
    close();
    delete this;
}

void SettingForm::on_bCloseSettingsWindow_clicked() {
    close();
    delete this;
}

void SettingForm::connectSlots() {
    connect(userActions, &UserActions::runRenderGUI, this, &SettingForm::renderGUI);
}

void SettingForm::createGUI() {
    ui->setupUi(this);
    ucFileDialog = new QFileDialog();
    ucFileDialog->setNameFilter(tr("Uncrustify (*.exe)"));
    cfgFileDialog = new QFileDialog();
    cfgFileDialog->setNameFilter(tr("Uncrustify config (*.cfg)"));
}
