#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::SettingForm){
    ui->setupUi(this);
    QFile iniFile("settings.ini");
    QStringList settingStrings;
    if((iniFile.exists() && iniFile.open(QIODevice::ReadOnly))){
        while(!iniFile.atEnd()){
            settingStrings.append(iniFile.readLine());
        }
    }
    QList<QStringList> parse;
    for(int i = 0; i < settingStrings.count(); i++){
        settingStrings[i].remove('\r');
        settingStrings[i].remove('\n');
        parse.append(settingStrings[i].split(' '));
    }
    foreach(auto item, parse){
        if(item[0] == "path_to_uncrustify"){
            ui->tbPathToUC->setText(item[2]);
        }
        else if(item[0] == "path_to_config"){
            ui->tbPathToCfgUC->setText(item[2]);
        }
    }
    iniFile.close();
}

SettingForm::~SettingForm(){
    delete ui;
}

void SettingForm::on_pushButton_clicked(){
    auto pathToUC = QFileDialog::getOpenFileName(this, tr("Open Uncrustify.exe"), "*/", tr("Uncrustify (*.exe)"));
    if(pathToUC != ""){
        ui->tbPathToUC->setText(pathToUC);
    }
}

void SettingForm::on_pushButton_2_clicked(){
    auto pathToCfgUC =
            QFileDialog::getOpenFileName(this, tr("Open uncrustify config file"), "*/",
            tr("Uncrustify config (*.cfg)"));
    if(pathToCfgUC != ""){
        ui->tbPathToCfgUC->setText(pathToCfgUC);
    }
}

void SettingForm::on_pushButton_4_clicked(){
    QString pathToUC = ui->tbPathToUC->text();
    QString pathToCfg = ui->tbPathToCfgUC->text();
    QStringList config;
    config.append("path_to_uncrustify = " + pathToUC + "\n");
    config.append("path_to_config = " + pathToCfg);
    QFile iniFile("settings.ini");
    if(iniFile.open(QIODevice::WriteOnly)){
        foreach(auto item, config){
            iniFile.write(item.toUtf8());
        }
    }
    iniFile.close();
}

void SettingForm::on_pushButton_3_clicked(){
    on_pushButton_4_clicked();
    this->close();
}

void SettingForm::on_tbPathToUC_textChanged(const QString &arg1)
{
    pathToUC = arg1;
}

void SettingForm::on_tbPathToCfgUC_textChanged(const QString &arg1)
{
    pathToCfg = arg1;
}
