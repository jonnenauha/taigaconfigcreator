#-------------------------------------------------
#
# Project created by QtCreator 2010-03-17T23:34:15
#
#-------------------------------------------------

QT       += core gui

TARGET = TaigaConfigCreator
TEMPLATE = app
DESTDIR = bin

SOURCES += main.cpp\
        MainWindow.cpp \
    UiHelper.cpp \
    TemplateReader.cpp \
    ConfigContent.cpp

HEADERS  += MainWindow.h \
    UiHelper.h \
    TemplateReader.h \
    ConfigContent.h

FORMS    += MainWindow.ui

RESOURCES += \
    resources.qrc
