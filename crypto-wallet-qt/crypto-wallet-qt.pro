QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crypto-wallet-qt
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    api.cpp \
    utils.cpp \
    moneda.cpp \
    portofoliu.cpp \
    tranzactie.cpp

HEADERS += \
    mainwindow.h \
    api.h \
    utils.h \
    moneda.h \
    portofoliu.h \
    tranzactie.h

FORMS += \
    mainwindow.ui

RESOURCES +=

# Dacă folosești fișiere de stil:
# include styles.qss dacă îl folosești din cod, nu aici