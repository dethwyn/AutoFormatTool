#include "nyancatprogressbar.h"

NyanCatProgressBar::NyanCatProgressBar(QWidget *parent) {
    if(parent != nullptr) {
        this->setParent(parent);
    }
    typeRay = 0;
}

void NyanCatProgressBar::setType(int type) {
    if(type >= 0 && type <= 1) {
        typeRay = type;
    } else {
        typeRay = 0;
    }
}

int NyanCatProgressBar::getTypeRay() {
    return typeRay;
}

void NyanCatProgressBar::paintEvent(QPaintEvent *) {
    auto val = value();
    auto pos = QStyle::sliderPositionFromValue(minimum(), maximum(), val, width());
    QPainter painter(this);
    auto pos_draw = 0;
    QImage src("1.png");
    auto dest = src.scaled(40, height());
    QColor colors[] = {k_red, k_orange, k_yellow, k_green, k_lightBlue, k_purple};
    if(typeRay == 1) {
        int hRect = height() / 6;
        if(val <= maximum() && val > 0) {
            int i = 0;
            for(auto &item : colors) {
                painter.setPen(item);
                painter.setBrush(item);
                painter.drawRect(pos_draw, i * hRect, pos, hRect);
                i++;
            }
            painter.drawImage(pos - dest.width() / 2, 0, dest);
        }
    } else {
        if(val <= maximum() && val > 0) {
            painter.setPen(QColor(127, 127, 127));
            auto *gradient = new QLinearGradient();
            gradient->setStart(0, 0);
            gradient->setFinalStop(pos, height());
            gradient->setColorAt(0.0, QColor(200, 255, 200));
            gradient->setColorAt(1.0, QColor(0, 255, 0));
            painter.setBrush(*gradient);
            painter.drawRect(pos_draw, -1, pos, height());
            delete gradient;
        }
    }
}
