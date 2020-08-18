#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QStringListModel>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>

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

        void on_pbPathToOptions_clicked();

    private:
        Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
