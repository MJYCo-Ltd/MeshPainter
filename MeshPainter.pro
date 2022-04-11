QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp


SDK_CONFIG *= OSG
include(SoftSDK.pri)

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h

TRANSLATIONS += \
    MeshPainter_zh_CN.ts
