#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};

#endif // MAINWINDOW_H
