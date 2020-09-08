#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingform.h"
#include "nyancatprogressbar.h"

#include <QDebug>
#include <QMainWindow>
#include <QFileDialog>
#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMath>

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
    void on_menuExit_triggered();
    void on_menuSettings_triggered();
    void on_bPath_clicked();
    void on_bFormat_clicked();
    void on_bRefresh_clicked();
    void on_tbPath_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    SettingForm *setting;
    NyanCatProgressBar *nc;
    QPushButton *testBt;

protected:
    virtual void keyPressEvent(QKeyEvent *event);

public slots:
    void testPb();
};
#endif // MAINWINDOW_H
