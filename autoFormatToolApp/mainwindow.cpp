#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    configureUi();
    connectSlots();
    renderGUI();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::renderGUI() {
    auto instance = &State::getInstance();
    ui->menuSettings->setText(instance->getMenuSettingText());
    ui->menuExit->setText(instance->getMenuExitText());
    ui->menu->setTitle(instance->getMenuFileText());
    ui->bPath->setText(instance->getButtonBrowseText());
    ui->bFormat->setText(instance->getButtonFormatText());
    ui->bRefresh->setText(instance->getButtonRefreshText());
    ui->tbPath->setText(instance->getLinePathText());
    ui->lbPathSource->setText(instance->getLabelPathText());
    ui->listFiles->clear();
    foreach(auto item, *instance->getListFilesStringList()) {
        ui->listFiles->addItem(item);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if(key == Qt::Key_Delete) {
        userActions->deleteFile(ui->listFiles->currentRow());
    }
}

void MainWindow::on_menuExit_triggered() {
    this->close();
}

void MainWindow::on_menuSettings_triggered() {
    settingForm->show();
}

void MainWindow::on_bPath_clicked() {
    if(selectDirDialog->exec()) {
        userActions->bPath_clicked(selectDirDialog->selectedFiles()[0]);
    }
}

void MainWindow::on_bFormat_clicked() {
    userActions->bFormat_clicked();
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
    userActions->bRefresh_clicked();
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
    userActions->tbPath_textChanged(arg1);
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
    connect(userActions, &UserActions::runRenderGUI, this, &MainWindow::renderGUI);
}

void MainWindow::configureUi() {
    ui->setupUi(this);
    settingForm = new SettingForm();
    State *stateInstance = &State::getInstance();
    userActions = new UserActions();
    if(stateInstance->getProgressBarType() == 1) {
        progressBar = new NyanCatProgressBar();
    } else {
        progressBar = new QProgressBar();
    }
    ui->verticalLayout->addWidget(progressBar);
    selectDirDialog = new QFileDialog();
    selectDirDialog->setFileMode(QFileDialog::DirectoryOnly);
}
