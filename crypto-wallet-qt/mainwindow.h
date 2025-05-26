#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "portofoliu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBoxMoneda_currentIndexChanged(int index);
    void on_buttonCumpara_clicked();

private:
    Ui::MainWindow *ui;
    void actualizeazaPret();
    Portofoliu portofoliu; // Instance of Portofoliu to manage wallet operations
};

#endif // MAINWINDOW_H
