#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "portofoliu.h"
#include "api.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBoxMonede_currentIndexChanged(int index);
    void on_buttonCumpara_clicked();
    void on_buttonIstoric_clicked();
    void on_buttonExport_clicked();

private:
    Ui::MainWindow *ui;
    Portofoliu *portofoliu;
    API *api;
    
    void actualizeazaTabel();
    void actualizeazaBuget();
    void incarcaMonede();
    
    struct MonedaInfo {
        QString id;
        QString simbol;
        QString nume;
    };
    
    QList<MonedaInfo> listaMonede;
};
#endif // MAINWINDOW_H
