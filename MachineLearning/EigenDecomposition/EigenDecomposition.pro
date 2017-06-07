#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T16:26:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(D:\Program\OpenCV_tesseract.pri)

TARGET = EigenDecomposition
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    EigenDecomposition.cpp \
    Determinant.cpp

HEADERS += \
        mainwindow.h \
    EigenDecomposition.h \
    Determinant.h

FORMS += \
        mainwindow.ui
