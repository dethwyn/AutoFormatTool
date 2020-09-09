#ifndef USERACTIONS_H
#define USERACTIONS_H

#include <QObject>

class UserActions : public QObject {
    Q_OBJECT
public:
    explicit UserActions(QObject *parent = nullptr);

signals:
public slots:
};

#endif // USERACTIONS_H
