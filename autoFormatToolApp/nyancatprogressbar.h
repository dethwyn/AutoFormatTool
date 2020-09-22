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
#include <QDebug>

const auto k_red = QColor::fromRgb(255, 0, 0);
const auto k_orange = QColor::fromRgb(255, 160, 0);
const auto k_yellow = QColor::fromRgb(255, 255, 0);
const auto k_green = QColor::fromRgb(0, 255, 0);
const auto k_lightBlue = QColor::fromRgb(0, 176, 255);
const auto k_purple = QColor::fromRgb(100, 50, 255);

const auto k_red_l = QColor::fromRgb(255, 100, 100);
const auto k_orange_l = QColor::fromRgb(255, 160, 100);
const auto k_yellow_l = QColor::fromRgb(255, 255, 100);
const auto k_green_l = QColor::fromRgb(100, 255, 100);
const auto k_lightBlue_l = QColor::fromRgb(100, 176, 255);
const auto k_purple_l = QColor::fromRgb(200, 150, 255);

class NyanCatProgressBar : public QProgressBar {
public:
    explicit NyanCatProgressBar(QWidget *parent = nullptr);
    void setType(int typeRay);
    int getTypeRay();
protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
    int typeRay;
    void drawRectBorder(QPainter *p);
};

#endif // NYANCATPROGRESSBAR_H
