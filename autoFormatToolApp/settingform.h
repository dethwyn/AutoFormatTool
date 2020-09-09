#ifndef SETTINGFORM_H
#define SETTINGFORM_H



#include <QWidget>
#include <QFile>
#include <QFileDialog>

namespace Ui {
    class SettingForm;
}

class SettingForm : public QWidget {
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();
    QString pathToUC;
    QString pathToCfg;

private slots:
    void on_tbPathToUC_textChanged(const QString &arg1);
    void on_tbPathToCfgUC_textChanged(const QString &arg1);
    void on_bSaveSettings_clicked();
    void on_bOpenPathUC_clicked();
    void on_bOpenPathCfgUC_clicked();
    void on_bCloseSettingsWindow_clicked();

private:
    Ui::SettingForm *ui;
};

#endif // SETTINGFORM_H
