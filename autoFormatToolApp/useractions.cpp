#include "useractions.h"

UserActions::UserActions(QObject *parent) : QObject(parent) {
    userSettings = new Settings();
}

void UserActions::menuSettings_triggered() {
    emit runRenderGUI();
}

void UserActions::bPath_clicked(QString path) {
    auto instance = &State::getInstance();
    instance->setLinePathText(path);
    emit runRenderGUI();
}

void UserActions::bFormat_clicked() {
    auto instance = &State::getInstance();
    if(instance->getListFilesStringList()->count() != 0) {
        QString uncrustifyPath = instance;
        QString uncrustifyConfigPath = settingForm->pathToCfg;
        QFile UC(uncrustifyPath);
        QFile UCcfg(uncrustifyConfigPath);
        if(!UC.exists()) {
            QMessageBox mbNotFoundUC;
            mbNotFoundUC.setText("Не найден файл uncrustify.exe, проверьте настройки");
            mbNotFoundUC.exec();
            settingForm->show();
            return;
        }
        if(!UCcfg.exists()) {
            QMessageBox mbNotFoundUC;
            mbNotFoundUC.setText("Не найден файл конфигурации, проверьте настройки");
            mbNotFoundUC.exec();
            settingForm->show();
            return;
        }
        QMessageBox final;
        final.setText("Форматирование завершено");
        double progresBarStep = round(100.0 / ui->listFiles->count());
        double currentProgressBarValue = 0;
        progressBar->setValue(static_cast<int>(currentProgressBarValue));
        // ui->progressBar->setValue();
        while(ui->listFiles->count() > 0) {
            QString command("powershell.exe");
            QString pathToFile(ui->tbPath->text() + "/" + ui->listFiles->takeItem(0)->text());
            QStringList params;
            QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
            params.append(param.arg(uncrustifyPath).arg(uncrustifyConfigPath).arg(pathToFile));
            int result = QProcess::execute(command, params);
            qDebug() << result;
            currentProgressBarValue += progresBarStep;
            progressBar->setValue(static_cast<int>(currentProgressBarValue));
            // ui->progressBar->setValue(static_cast<int>(currentProgressBarValue));
        }
        progressBar->setValue(100);
        // ui->progressBar->setValue(100);
        final.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Не выбран ни один файл с исходным кодом!");
        msgBox.exec();
    }
    emit runRenderGUI();
}

void UserActions::bRefresh_clicked() {
    auto instance = &State::getInstance();
    UserActions::tbPath_textChanged(instance->getLinePathText());
}

void UserActions::tbPath_textChanged(const QString &text) {
    auto instance = &State::getInstance();
    instance->setLinePathText(text);
    QDir dir;
    if(dir.exists(text)) {
        instance->getListFilesStringList()->clear();
        dir.setPath(text);
        dir.setNameFilters(QStringList() << "*.cpp" << "*.c" << "*.h" << "*.hpp");
        QStringList files = dir.entryList();
        foreach(auto item, files) {
            instance->addItemListFiles(item);
        }
    }
    emit runRenderGUI();
}

void UserActions::deleteFile(int pos) {
    auto instance = &State::getInstance();
    if(instance->getListFilesStringList()->count() > 0) {
        instance->deleteItemListFiles(pos);
    }
    emit runRenderGUI();
}
