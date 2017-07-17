#-------------------------------------------------
#
# Project created by QtCreator 2017-07-14T00:18:39
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankingSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    DataBaseManager.cpp \
    querywidget.cpp

HEADERS  += widget.h \
    DataBaseManager.h \
    querywidget.h

FORMS    += widget.ui
