#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include "useractions.h"

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
    class SettingForm;
}

class SettingForm : public QWidget {
    Q_OBJECT

public:
    explicit SettingForm(UserActions *ua, QWidget *parent = nullptr);
    ~SettingForm();
    QString pathToUC;
    QString pathToCfg;

public slots:
    void renderGUI();

private slots:
    void on_tbPathToUC_textChanged(const QString &arg1);
    void on_tbPathToCfgUC_textChanged(const QString &arg1);
    void on_bSaveSettings_clicked();
    void on_bOpenPathUC_clicked();
    void on_bOpenPathCfgUC_clicked();
    void on_bCloseSettingsWindow_clicked();

private:
    Ui::SettingForm *ui;
    UserActions *userActions;
    void connectSlots();
    void createGUI();
    QFileDialog *ucFileDialog;
    QFileDialog *cfgFileDialog;
};

#endif // SETTINGFORM_H
