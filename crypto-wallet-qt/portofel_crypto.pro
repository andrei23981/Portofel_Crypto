QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000 


SOURCES += \
    api.cpp \
    main.cpp \
    mainwindow.cpp \
    moneda.cpp \
    portofoliu.cpp \
    tranzactie.cpp \
    utils.cpp

HEADERS += \
    api.h \
    mainwindow.h \
    moneda.h \
    portofoliu.h \
    tranzactie.h \
    utils.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target