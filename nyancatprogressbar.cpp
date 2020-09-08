#include "nyancatprogressbar.h"

NyanCatProgressBar::NyanCatProgressBar(QWidget *parent) {
    setAlignment(Qt::AlignLeft);
    setFormat("%p%");
}

void NyanCatProgressBar::paintEvent(QPaintEvent *) {
    int val = value();

    int pos = QStyle::sliderPositionFromValue(minimum(), maximum(), val, width());

    QPainter painter(this);
    int pos_draw = 0;
    QImage src("1.png");
    QImage dest = src.scaled(40, height());
    QColor colors[] = {k_red, k_orange, k_yellow, k_green, k_lightBlue, k_purple};
    int hRect = height() / 6;
    for(int i = 0; i < 6; i++) {
        if(val < 100) {
            painter.setPen(colors[i]);
            painter.setBrush(QBrush(colors[i]));
            painter.drawRect(pos_draw - 1, i * hRect, pos, hRect);
        } else {
            painter.setPen(colors[i]);
            painter.setBrush(QBrush(colors[i]));
            painter.drawRect(pos_draw - 1, i * hRect,
                    QStyle::sliderPositionFromValue(minimum(), maximum(), val - 5, width()), hRect);
        }
    }
    if(val < 100 && val > 0) {
        painter.drawImage(pos - 20, 0, dest);
    } else {
        painter.drawImage(pos - 40, 0, dest);
    }

    text();
}
