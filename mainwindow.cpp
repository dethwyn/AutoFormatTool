#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btPath_clicked()
{
    auto path = QFileDialog::getExistingDirectory();
    ui->tbPath->setText(path);
    QDir dir;
    dir.setPath(path);
    dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
    QStringList files = dir.entryList();
    foreach (auto item, files) {
        ui->listFiles->addItem(item);
    }
}

void MainWindow::on_pbFormat_clicked()
{
    if (ui->listFiles->count() != 0) {
        QString pathToOptions;
        if (ui->tbPathToOptions->text() != "") {
            pathToOptions = ui->tbPathToOptions->text() + " ";
        }
        else {
            pathToOptions = "debug/data/format.astylerc ";
        }

        for (int i = 0; i < ui->listFiles->count(); i++) {
            ui->listFiles->setCurrentRow(i);
            QString  command("powershell.exe");
            QString pathToFile(ui->tbPath->text() + "/" + ui->listFiles->currentItem()->text());
            QStringList params;
            params.append("astyle --options=" + pathToOptions + pathToFile);
            qDebug() << params;
            QProcess::startDetached(command, params);

        }
    }
    else {

    }

}

void MainWindow::on_pbPathToOptions_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this, NULL, NULL, tr("AStyle option file (*.astylerc)"));
    ui->tbPathToOptions->setText(fileName);
}
