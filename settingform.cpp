#include "settingform.h"
#include "ui_settingform.h"

SettingForm::SettingForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::SettingForm){
    ui->setupUi(this);
}

SettingForm::~SettingForm(){
    delete ui;
}

void SettingForm::on_pushButton_clicked()
{

}

void SettingForm::on_pushButton_2_clicked()
{

}

void SettingForm::on_pushButton_4_clicked()
{
    this->close();
}

void SettingForm::on_pushButton_3_clicked()
{
    this->close();
}
