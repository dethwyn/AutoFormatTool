#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    settingForm = new SettingForm();
    State *stateInstance = &State::getInstance();
    if(stateInstance->probressBarType == 1) {
        progressBar = new NyanCatProgressBar();
    } else {
        progressBar = new QProgressBar();
    }
    ui->verticalLayout->addWidget(progressBar);
    renderGUI();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::renderGUI() {
    State *stateInstance = &State::getInstance();
    ui->menuSettings->setText(stateInstance->menuSettingText);
    ui->menuExit->setText(stateInstance->menuExitText);
    ui->menu->setTitle(stateInstance->menuFileText);
    ui->bPath->setText(stateInstance->buttonBrowseText);
    ui->bFormat->setText(stateInstance->buttonFormatText);
    ui->bRefresh->setText(stateInstance->buttonRefreshText);
    ui->tbPath->setText(stateInstance->linePathText);
    ui->lbPathSource->setText(stateInstance->labelPathText); \

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if(key == Qt::Key_Delete /* && (ui->listFiles->count() > 0)*/) {
        // ui->listFiles->currentItem()->~QListWidgetItem();
        userActions.deleteFile(ui->listFiles->currentRow());
    }
}

void MainWindow::on_menuExit_triggered() {
    this->close();
}

void MainWindow::on_menuSettings_triggered() {
    settingForm->show();
}

void MainWindow::on_bPath_clicked() {
//    ui->listFiles->clear();
//    auto path = QFileDialog::getExistingDirectory();
//    ui->tbPath->setText(path);
    userActions.bPath_clicked();
}

void MainWindow::on_bFormat_clicked() {
    userActions.bFormat_clicked();
//    if(ui->listFiles->count() != 0) {
//        QString uncrustifyPath = settingForm->pathToUC;
//        QString uncrustifyConfigPath = settingForm->pathToCfg;
//        QFile UC(uncrustifyPath);
//        QFile UCcfg(uncrustifyConfigPath);
//        if(!UC.exists()) {
//            QMessageBox mbNotFoundUC;
//            mbNotFoundUC.setText("Не найден файл uncrustify.exe, проверьте настройки");
//            mbNotFoundUC.exec();
//            settingForm->show();
//            return;
//        }
//        if(!UCcfg.exists()) {
//            QMessageBox mbNotFoundUC;
//            mbNotFoundUC.setText("Не найден файл конфигурации, проверьте настройки");
//            mbNotFoundUC.exec();
//            settingForm->show();
//            return;
//        }
//        QMessageBox final;
//        final.setText("Форматирование завершено");
//        double progresBarStep = round(100.0 / ui->listFiles->count());
//        double currentProgressBarValue = 0;
//        progressBar->setValue(static_cast<int>(currentProgressBarValue));
//        // ui->progressBar->setValue();
//        while(ui->listFiles->count() > 0) {
//            QString command("powershell.exe");
//            QString pathToFile(ui->tbPath->text() + "/" + ui->listFiles->takeItem(0)->text());
//            QStringList params;
//            QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
//            params.append(param.arg(uncrustifyPath).arg(uncrustifyConfigPath).arg(pathToFile));
//            int result = QProcess::execute(command, params);
//            qDebug() << result;
//            currentProgressBarValue += progresBarStep;
//            progressBar->setValue(static_cast<int>(currentProgressBarValue));
//            // ui->progressBar->setValue(static_cast<int>(currentProgressBarValue));
//        }
//        progressBar->setValue(100);
//        // ui->progressBar->setValue(100);
//        final.exec();
//    } else {
//        QMessageBox msgBox;
//        msgBox.setText("Не выбран ни один файл с исходным кодом!");
//        msgBox.exec();
//    }
}

void MainWindow::on_bRefresh_clicked() {
    userActions.bRefresh_clicked();
//    ui->listFiles->clear();
//    QDir dir;
//    dir.setPath(ui->tbPath->text());
//    dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
//    QStringList files = dir.entryList();
//    foreach(auto item, files) {
//        ui->listFiles->addItem(item);
//    }
}

void MainWindow::on_tbPath_textChanged(const QString &arg1) {
    userActions.tbPath_textChanged(arg1);
//    QDir dir;
//    if(dir.exists(arg1)) {
//        ui->listFiles->clear();
//        dir.setPath(arg1);
//        dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
//        QStringList files = dir.entryList();
//        foreach(auto item, files) {
//            ui->listFiles->addItem(item);
//        }
//    }
}

void MainWindow::connectSlots() {
}
