QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crypto-wallet-qt
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    api.cpp \
    utils.cpp

HEADERS += \
    mainwindow.h \
    api.h \
    utils.h

FORMS += \
    mainwindow.ui

# Pentru fișiere suplimentare, adaugă-le aici