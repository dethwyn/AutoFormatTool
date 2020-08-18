#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_btPath_clicked() {
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

void MainWindow::on_pbFormat_clicked() {
    QProcess proc;
    ui->listFiles->setCurrentRow(0);
    QStringList args;
    args.append("astyle --options=codeStyleAStyle " + ui->tbPath->text() + ui->listFiles->currentItem()->text());
    proc.execute("cmd.exe", args);
}
