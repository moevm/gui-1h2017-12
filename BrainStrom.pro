
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrainStrom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mentalquest.cpp

HEADERS  += mainwindow.h \
    mentalquest.h \
    clock.h

FORMS    += mainwindow.ui \
    mentalquest.ui
