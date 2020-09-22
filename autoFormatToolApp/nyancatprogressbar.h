/*
 * \file nyancatprogressbar.h
 * \brief Объявление класса NyanCatProgressBar
 * \author Сницарук Д. Г.
 * \date 09.20
 */
#ifndef NYANCATPROGRESSBAR_H
#define NYANCATPROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QStyle>
#include <QPen>
#include <QColor>
/*
 * \class NyanCatProgressBar
 * \brief Переопределенный прогресс-бар, логика отрисовки зависит от поля typeRay
 */
class NyanCatProgressBar : public QProgressBar {
public:
    // конструктор по умолчанию (qt)
    explicit NyanCatProgressBar(QWidget *parent = nullptr);
    // геттер поля typeRay
    void setType(int typeRay);
    // сеттер поля typeRay
    int getTypeRay();
protected:
    // переопределение метода-обработчика события отрисовки виджета
    void paintEvent(QPaintEvent *) override;
    int typeRay; // тип отрисовки
    // метод отрисовки границы
    void drawRectBorder(QPainter *p);
    // метод отрисовки прогрессбара первого типа
    void drawType1(QPainter *p);
    // метод отрисовки прогрессбара второго типа
    void drawType2(QPainter *p);
private:
    // константные цвета для прогрессбара первого типа
    const QColor k_red = QColor::fromRgb(255, 0, 0);
    const QColor k_orange = QColor::fromRgb(255, 160, 0);
    const QColor k_yellow = QColor::fromRgb(255, 255, 0);
    const QColor k_green = QColor::fromRgb(0, 255, 0);
    const QColor k_lightBlue = QColor::fromRgb(0, 176, 255);
    const QColor k_purple = QColor::fromRgb(100, 50, 255);
};
#endif // NYANCATPROGRESSBAR_H
