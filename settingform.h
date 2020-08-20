#ifndef SETTINGFORM_H
#define SETTINGFORM_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class SettingForm;
}

class SettingForm : public QWidget
{
    Q_OBJECT

public:
    explicit SettingForm(QWidget *parent = nullptr);
    ~SettingForm();
    QString pathToUC;
    QString pathToCfg;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

    void on_tbPathToUC_textChanged(const QString &arg1);

    void on_tbPathToCfgUC_textChanged(const QString &arg1);

private:
    Ui::SettingForm *ui;
};

#endif // SETTINGFORM_H
