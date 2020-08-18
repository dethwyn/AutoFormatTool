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
    if (ui->listFiles->count() != 0) {

        QString pathToOptions = "debug/data/formatCodeVNIIA.astylerc ";


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
        QMessageBox msgBox;
        msgBox.setText("Не выбран ни один файл с исходным кодом!");
        msgBox.exec();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if(key == Qt::Key_Delete) {
        ui->listFiles->currentItem()->~QListWidgetItem();
    }
}
