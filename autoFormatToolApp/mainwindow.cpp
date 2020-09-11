#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    configureUi();
    connectSlots();
    renderGUI();
}

MainWindow::~MainWindow() {
    delete userActions;
    delete progressBar;
    delete selectDirDialog;
    delete settingForm;
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
    progressBar->setValue(instance->getProgressBarValue());
    progressBar->setMaximum(instance->getProgressBarMax());
    progressBar->setType(instance->getProgressBarType());
    ui->listFiles->clear();
    foreach(auto item, *instance->getListFileInfos()) {
        ui->listFiles->addItem(item.fileName());
    }
}

void MainWindow::showMessageBox(QString message) {
    QMessageBox messageBox;
    messageBox.setText(message);
    messageBox.exec();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    if(key == Qt::Key_Delete) {
        userActions->deleteFile(ui->listFiles->currentRow());
    } else {
        userActions->inputSecretCode(event->text());
    }
}

void MainWindow::on_menuExit_triggered() {
    this->close();
}

void MainWindow::on_menuSettings_triggered() {
    settingForm = new SettingForm(userActions);
    settingForm->show();
}

void MainWindow::on_bPath_clicked() {
    if(selectDirDialog->exec()) {
        userActions->bPath_clicked(selectDirDialog->selectedFiles()[0]);
    }
}

void MainWindow::on_bFormat_clicked() {
    userActions->bFormat_clicked();
}

void MainWindow::on_bRefresh_clicked() {
    userActions->bRefresh_clicked();
}

void MainWindow::on_tbPath_textChanged(const QString &arg1) {
    userActions->tbPath_textChanged(arg1);
}

void MainWindow::connectSlots() {
    connect(userActions, &UserActions::runRenderGUI, this, &MainWindow::renderGUI);
    connect(userActions, &UserActions::showMessageBox, this, &MainWindow::showMessageBox);
}

void MainWindow::configureUi() {
    ui->setupUi(this);
    State *stateInstance = &State::getInstance();
    userActions = new UserActions();
    progressBar = new NyanCatProgressBar();
//    if(stateInstance->getProgressBarType() == 1) {
//        progressBar->setType(1);
//    } else {
//        progressBar->setType(0);
//    }
    ui->verticalLayout->addWidget(progressBar);
    selectDirDialog = new QFileDialog();
    selectDirDialog->setFileMode(QFileDialog::DirectoryOnly);
}
