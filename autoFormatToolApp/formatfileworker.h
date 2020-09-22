#ifndef FORMATFILEWORKER_H
#define FORMATFILEWORKER_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QFileInfoList>
#include <QProcess>

class FormatFileWorker : public QThread {
    Q_OBJECT
public:
    explicit FormatFileWorker(QObject *parent = nullptr);
    explicit FormatFileWorker(int maxPB, QFileInfoList *fList, const QString &ucPath, const QString &cfgPath);
    void run();
private:
    int progresBarMax;
    QFileInfoList *fileList;
    QString uncrustifyPath;
    QString configPath;
    int progresBarStep;
signals:
    void completed();
    void step(int);
public slots:
};

#endif // FORMATFILEWORKER_H
