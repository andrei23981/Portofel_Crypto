#include <QApplication>
#include "mainwindow.h"

// Main entry point for the crypto wallet application
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
