#ifndef USERACTIONS_H
#define USERACTIONS_H

#include "settings.h"
#include "state.h"

#include <QObject>
#include <QFileDialog>

class UserActions : public QObject {
    Q_OBJECT
public:
    explicit UserActions(QObject *parent = nullptr);
    Settings userSettings;
    void menuSettings_triggered();
    void bPath_clicked(QString path);
    void bFormat_clicked();
    void bRefresh_clicked();
    void tbPath_textChanged(const QString &arg1);
    void deleteFile(int pos);
signals:
    void runRenderGUI();
public slots:
};

#endif // USERACTIONS_H
