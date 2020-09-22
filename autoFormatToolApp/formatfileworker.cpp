#include "formatfileworker.h"

FormatFileWorker::FormatFileWorker(QObject *parent) : QThread(parent) {
}

FormatFileWorker::FormatFileWorker(int maxPB, QFileInfoList *fList, const QString &ucPath, const QString &cfgPath) {
    progresBarMax = maxPB;
    fileList = fList;
    uncrustifyPath = ucPath;
    configPath = cfgPath;
    progresBarStep = progresBarMax / fileList->count();
}

void FormatFileWorker::run() {
    double currentProgressBarValue = 0;
    emit step(static_cast<int>(currentProgressBarValue));
    while(fileList->count() > 0) {
        QString command("powershell.exe");
        QStringList params;
        QString pathToFile = fileList->takeFirst().filePath();
        QString param = "%1 -c %2 -f %3 -o %3 --no-backup";
        params.append(param.arg(uncrustifyPath).arg(configPath).arg(pathToFile));
        QProcess::execute(command, params);
        currentProgressBarValue += progresBarStep;
        emit step(static_cast<int>(currentProgressBarValue));
    }
    emit step(static_cast<int>(progresBarMax));
    emit completed();
}
