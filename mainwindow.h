#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingform.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QMenuBar>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btPath_clicked();
    void on_pbFormat_clicked();
    void on_pbRefresh_clicked();
    void on_action_3_triggered();
    void on_action_4_triggered();

private:
    Ui::MainWindow *ui;
    SettingForm *setting;

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
