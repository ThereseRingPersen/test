#-------------------------------------------------
#
# Project created by QtCreator 2017-03-22T18:23:48
#
#-------------------------------------------------

QT       += core gui \
            multimedia
CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tester
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
    snakewindow.cpp \
    highscore.cpp \
    gameover.cpp \
    bodyofsnake.cpp \
    snake.cpp \
    Consumable.cpp \
    wall_brick.cpp \
    map.cpp \
    scoreuser.cpp \
    overloads.cpp \
    green_powerup.cpp \
    red_powerup.cpp \
    blue_powerup.cpp

HEADERS  += \
    snakewindow.h \
    highscore.h \
    gameover.h \
    bodyofsnake.h \
    snake.h \
    Consumable.h \
    wall_brick.h \
    map.h \
    scoreuser.h \
    overloads.h \
    green_powerup.h \
    red_powerup.h \
    blue_powerup.h

FORMS    += \
    snakewindow.ui \
    highscore.ui \
    gameover.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    save.txt
