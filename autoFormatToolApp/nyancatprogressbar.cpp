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
    auto pos = QStyle::sliderPositionFromValue(minimum(), maximum(), value(), width());
    QPainter painter(this);
    drawRectBorder(&painter);
    painter.drawRect(3, 3, width() - 7, height() - 7);
    if(typeRay == 1) {
        drawType1(&painter);
    } else {
        drawType2(&painter);
    }
}

void NyanCatProgressBar::drawRectBorder(QPainter *p) {
    auto gray = QColor::fromRgb(173, 173, 173);
    auto lightGray = QColor::fromRgb(240, 240, 240);
    p->setPen(gray);
    p->setBrush(gray);
    p->drawRect(0, 0, width(), height());
    p->setPen(lightGray);
    p->setBrush(lightGray);
    p->drawRect(1, 1, width() - 3, height() - 3);
}

void NyanCatProgressBar::drawType1(QPainter *p) {
    QColor colors[] = {k_red, k_orange, k_yellow, k_green, k_lightBlue, k_purple};
    int hRect = height() / 6;
    QImage src("1.png");
    auto pos = QStyle::sliderPositionFromValue(minimum(), maximum(), value(), width());
    auto dest = src.scaled(40, height());
    if(value() < maximum() && value() > 0) {
        int i = 0;
        drawRectBorder(p);
        for(auto &item : colors) {
            p->setPen(item);
            p->setBrush(item);
            p->drawRect(0, i * hRect + 1, pos, hRect);
            i++;
        }
        p->drawImage(pos - dest.width() / 2, 0, dest);
    } else if(value() == maximum()) {
        int i = 0;
        drawRectBorder(p);
        for(auto &item : colors) {
            p->setPen(item);
            p->setBrush(item);
            p->drawRect(0, i * hRect + 1, pos - dest.width() / 2, hRect);
            i++;
        }
        p->drawImage(pos - dest.width(), 0, dest);
    } else {
        drawRectBorder(p);
    }
}

void NyanCatProgressBar::drawType2(QPainter *p) {
    auto pos = QStyle::sliderPositionFromValue(minimum(), maximum(), value(), width());
    if(value() <= maximum() && value() > 0) {
        drawRectBorder(p);
        auto *gradient = new QLinearGradient();
        gradient->setStart(0, 0);
        gradient->setFinalStop(pos, height());
        gradient->setColorAt(0.0, QColor(200, 255, 200));
        gradient->setColorAt(1.0, QColor(0, 255, 0));
        p->setBrush(*gradient);
        p->drawRect(1, 1, pos - 3, height() - 3);
        delete gradient;
    }
}
