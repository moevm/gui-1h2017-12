#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T22:47:13
#
#-------------------------------------------------

QT       += core gui sql opengl
LIBS += -lglu32 -lopengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrainStorm
TEMPLATE = app


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mentalquest.cpp \
    colorquest.cpp \
    colorsett.cpp \
    mentalsett.cpp \
    inequalitysett.cpp \
    inequalityquest.cpp \
    statssqlhelper.cpp \
    helpwin.cpp \
    paintwidget.cpp \
    cardquest.cpp \
    cardsett.cpp

HEADERS  += mainwindow.h \
    mentalquest.h \
    colorquest.h \
    colorsett.h \
    mentalsett.h \
    inequalitysett.h \
    inequalityquest.h \
    statssqlhelper.h \
    helpwin.h \
    paintwidget.h \
    cardquest.h \
    cardsett.h

FORMS    += mainwindow.ui \
    mentalquest.ui \
    colorquest.ui \
    colorsett.ui \
    mentalsett.ui \
    inequalitysett.ui \
    inequalityquest.ui \
    statssqlhelper.ui \
    helpwin.ui \
    cardquest.ui \
    cardsett.ui

RESOURCES += \
    imgfiles.qrc \
    styles.qrc
