// MainWindow implementation
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "api.h"
#include "utils.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->comboBoxMoneda->addItems({"bitcoin", "ethereum", "solana"});
    actualizeazaPret();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_comboBoxMoneda_currentIndexChanged(int) {
    actualizeazaPret();
}

void MainWindow::on_buttonCumpara_clicked() {
    QString sumaText = ui->lineEditSuma->text();
    if (!isValidSuma(sumaText)) {
        QMessageBox::warning(this, "Eroare", "Introduceți suma de cumpărat.");
        return;
    }

    QString simbol = ui->comboBoxMoneda->currentText();
    QString pretStr = API::getPret(simbol);

    if (pretStr.isEmpty()) {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut obține prețul pentru moneda selectată.");
        return;
    }

    double sumaRON = sumaText.toDouble();
    double pret = pretStr.toDouble();
    double cantitate = sumaRON / pret;

    portofoliu.adaugaMoneda(simbol, cantitate);

    QMessageBox::information(this,"Cumpărare reușită","Ai cumpărat cu succes " + simbol.toUpper() + " de " + sumaText + " RON.");

    ui->lineEditSuma->clear();
}

void MainWindow::actualizeazaPret() {
    QString simbol = ui->comboBoxMoneda->currentText();
    QString pretStr = API::getPret(simbol);

    if (!pretStr.isEmpty())
        ui->labelPretCurent->setText("Preț curent: " + pretStr + " RON");
    else
        ui->labelPretCurent->setText("Preț indisponibil");
}
