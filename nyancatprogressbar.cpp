#include "nyancatprogressbar.h"

NyanCatProgressBar::NyanCatProgressBar(QWidget *parent) {
}

void NyanCatProgressBar::paintEvent(QPaintEvent *) {
    int val = value();

    int pos = QStyle::sliderPositionFromValue(minimum(), maximum(), val, width());

    QPainter painter(this);
    int pos_draw = 0;

    QColor colors[] = {k_red, k_orange, k_yellow, k_green, k_lightBlue, k_purple};
    int hRect = height() / 6;
    for(int i = 0; i < 6; i++) {
        painter.setPen(colors[i]);
        painter.setBrush(QBrush(colors[i]));
        painter.drawRect(pos_draw, i * hRect, pos, hRect);
    }
}
