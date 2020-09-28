/*
 * \file formatfileworker.cpp
 * \brief Реализация класса FormatFileWorker
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#include "formatfileworker.h"

FormatFileWorker::FormatFileWorker(QObject *parent) : QThread(parent) {
    progresBarMax = 100;
    fileList = new QFileInfoList();
    uncrustifyPath = "ucPath";
    configPath = "cfgPath";
    progresBarStep = progresBarMax / fileList->count();
}
/*!
 * @brief Реализация класса FormatFileWorker
 * @param maxPB
 */
FormatFileWorker::FormatFileWorker(int maxPB, QFileInfoList *fList, const QString &ucPath, const QString &cfgPath) {
    progresBarMax = maxPB;
    fileList = fList;
    uncrustifyPath = ucPath;
    configPath = cfgPath;
    progresBarStep = progresBarMax / fileList->count();
    FormatFileWorker f(2, fileList, "ww", "ww");
}

void FormatFileWorker::run() {
    double currentProgressBarValue = 0;
    QFileInfoList problemFiles;
    emit step(static_cast<int>(currentProgressBarValue));
    while(fileList->count() > 0) {
        QString command("powershell.exe");
        QStringList params;
        auto item = fileList->takeFirst();
        QString pathToFile = item.filePath();
        QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
        params.append(param.arg(uncrustifyPath).arg(configPath).arg(pathToFile));
        auto res = QProcess::execute(command, params);
        if(res == 1){
            problemFiles.append(item);
        }
        currentProgressBarValue += progresBarStep;
        emit step(static_cast<int>(currentProgressBarValue));
    }
    foreach(auto item, problemFiles){
        fileList->append(item);
    }
    emit step(static_cast<int>(progresBarMax));
    emit completed(problemFiles.count());
}
