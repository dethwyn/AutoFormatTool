VPATH += $$PWD
INCLUDEPATH += $$PWD

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/settingform.cpp \
    $$PWD/nyancatprogressbar.cpp \
    $$PWD/state.cpp \
    $$PWD/useractions.cpp \
    $$PWD/settings.cpp \
    $$PWD/stateget.cpp \
    $$PWD/stateset.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/settingform.h \
    $$PWD/nyancatprogressbar.h \
    $$PWD/state.h \
    $$PWD/useractions.h \
    $$PWD/settings.h

FORMS += \
    $$PWD/mainwindow.ui \
    $$PWD/settingform.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += settings.ini
