/*
 * \file formatfileworker.h
 * \brief Объявление класса FormatFileWorker
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef FORMATFILEWORKER_H
#define FORMATFILEWORKER_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QFileInfoList>
#include <QProcess>

/*
 * \class FormatFileWorker
 * \brief Класс, прогоняющий выбранные файлы через автоформатировщик в отдельном потоке
 */
class FormatFileWorker : public QThread {
    Q_OBJECT
public:
    // конструктор по умолчанию (qt)
    explicit FormatFileWorker(QObject *parent = nullptr);
    // основной конструктор
    explicit FormatFileWorker(int maxPB, QFileInfoList *fList, const QString &ucPath, const QString &cfgPath);
    // переопределение метода run() из родителя QThread (запускается при вызове метода start())
    void run() override;
private:
    int progresBarMax; // максимальное значение прогрессбара
    QFileInfoList *fileList; // список информации о файлах
    QString uncrustifyPath; // путь до uncrustify
    QString configPath; // путь до конфига
    int progresBarStep; // шаг изменения значения прогрессбара
signals:
    // сигнал окончания работы
    void completed(int);
    // сигнал прохождения очередного шага
    void step(int);
public slots:
};
#endif // FORMATFILEWORKER_H
