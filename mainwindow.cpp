#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setting = new SettingForm();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if(key == Qt::Key_Delete) {
        ui->listFiles->currentItem()->~QListWidgetItem();
    }
}

void MainWindow::on_menuExit_triggered() {
    this->close();
}

void MainWindow::on_menuSettings_triggered() {
    setting->show();
}

void MainWindow::on_bPath_clicked() {
    ui->listFiles->clear();
    auto path = QFileDialog::getExistingDirectory();
    ui->tbPath->setText(path);
    QDir dir;
    dir.setPath(path);
    dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
    QStringList files = dir.entryList();
    foreach(auto item, files) {
        ui->listFiles->addItem(item);
    }
}

void MainWindow::on_bFormat_clicked() {
    if(ui->listFiles->count() != 0) {
        QString uncrustifyPath = setting->pathToUC;
        QString uncrustifyConfigPath = setting->pathToCfg;
        QFile UC(uncrustifyPath);
        QFile UCcfg(uncrustifyConfigPath);
        if(!UC.exists()) {
            QMessageBox mbNotFoundUC;
            mbNotFoundUC.setText("Не найден файл uncrustify.exe, проверьте настройки");
            mbNotFoundUC.exec();
            setting->show();
            return;
        }
        if(!UCcfg.exists()) {
            QMessageBox mbNotFoundUC;
            mbNotFoundUC.setText("Не найден файл конфигурации, проверьте настройки");
            mbNotFoundUC.exec();
            setting->show();
            return;
        }
        QMessageBox final;
        final.setText("Форматирование завершено");
        double progresBarStep = 100 / ui->listFiles->count();
        double currentProgressBarValue = 0;
        ui->progressBar->setValue(currentProgressBarValue);
        for(int i = 0; i < ui->listFiles->count(); i++) {
            ui->listFiles->setCurrentRow(i);
            QString command("powershell.exe");
            QString pathToFile(ui->tbPath->text() + "/" + ui->listFiles->currentItem()->text());
            QStringList params;
            QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
            params.append(param.arg(uncrustifyPath).arg(uncrustifyConfigPath).arg(pathToFile));
            QProcess::execute(command, params);
            currentProgressBarValue += progresBarStep;
            ui->progressBar->setValue(currentProgressBarValue);
        }
        final.exec();
    } else   {
        QMessageBox msgBox;
        msgBox.setText("Не выбран ни один файл с исходным кодом!");
        msgBox.exec();
    }
}

void MainWindow::on_bRefresh_clicked() {
    ui->listFiles->clear();
    QDir dir;
    dir.setPath(ui->tbPath->text());
    dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
    QStringList files = dir.entryList();
    foreach(auto item, files) {
        ui->listFiles->addItem(item);
    }
}
