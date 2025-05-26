#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Inițializare portofoliu și API
    portofoliu = new Portofoliu();
    api = new API();
    
    // Încărcare monede disponibile
    incarcaMonede();
    
    // Conectare semnale și sloturi
    connect(ui->comboBoxMonede, SIGNAL(currentIndexChanged(int)), 
            this, SLOT(on_comboBoxMonede_currentIndexChanged(int)));
    connect(ui->buttonCumpara, SIGNAL(clicked()), 
            this, SLOT(on_buttonCumpara_clicked()));
    connect(ui->buttonIstoric, SIGNAL(clicked()), 
            this, SLOT(on_buttonIstoric_clicked()));
    connect(ui->buttonExport, SIGNAL(clicked()), 
            this, SLOT(on_buttonExport_clicked()));
    
    // Actualizare interfață
    actualizeazaTabel();
    actualizeazaBuget();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete portofoliu;
    delete api;
}

void MainWindow::incarcaMonede()
{
    // Lista de monede disponibile
    listaMonede = {
        {"bitcoin", "BTC", "Bitcoin"},
        {"ethereum", "ETH", "Ethereum"},
        {"solana", "SOL", "Solana"},
        {"cardano", "ADA", "Cardano"},
        {"polkadot", "DOT", "Polkadot"},
        {"ripple", "XRP", "Ripple"}
    };
    
    // Populare combobox
    ui->comboBoxMonede->clear();
    for (const auto& moneda : listaMonede) {
        ui->comboBoxMonede->addItem(moneda.simbol + " - " + moneda.nume);
    }
}

void MainWindow::on_comboBoxMonede_currentIndexChanged(int index)
{
    if (index >= 0 && index < listaMonede.size()) {
        QString id = listaMonede[index].id;
        QString pret = api->getPret(id);
        ui->labelPret->setText(pret + " RON");
    }
}

void MainWindow::on_buttonCumpara_clicked()
{
    int index = ui->comboBoxMonede->currentIndex();
    if (index < 0) return;
    
    bool ok;
    float suma = ui->lineEditSuma->text().toFloat(&ok);
    
    if (!ok || suma <= 0) {
        QMessageBox::warning(this, "Eroare", "Introduceți o sumă validă!");
        return;
    }
    
    QString id = listaMonede[index].id;
    QString simbol = listaMonede[index].simbol;
    float pret = api->getPret(id).toFloat();
    
    try {
        portofoliu->cumpara(simbol, suma, pret);
        QMessageBox::information(this, "Succes", 
                                "Ai cumpărat " + QString::number(suma/pret, 'f', 8) + 
                                " " + simbol + " pentru " + QString::number(suma, 'f', 2) + " RON");
        
        actualizeazaTabel();
        actualizeazaBuget();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Eroare", e.what());
    }
}

void MainWindow::actualizeazaTabel()
{
    ui->tableWidgetPortofoliu->setRowCount(0);
    
    QMap<QString, float> monede = portofoliu->getMonede();
    QMapIterator<QString, float> i(monede);
    
    int row = 0;
    while (i.hasNext()) {
        i.next();
        QString simbol = i.key();
        float cantitate = i.value();
        
        // Găsește ID-ul monedei pentru a obține prețul
        QString id;
        for (const auto& moneda : listaMonede) {
            if (moneda.simbol == simbol) {
                id = moneda.id;
                break;
            }
        }
        
        float pretUnitar = api->getPret(id).toFloat();
        float valoareTotala = cantitate * pretUnitar;
        
        ui->tableWidgetPortofoliu->insertRow(row);
        ui->tableWidgetPortofoliu->setItem(row, 0, new QTableWidgetItem(simbol));
        ui->tableWidgetPortofoliu->setItem(row, 1, new QTableWidgetItem(QString::number(cantitate, 'f', 8)));
        ui->tableWidgetPortofoliu->setItem(row, 2, new QTableWidgetItem(QString::number(pretUnitar, 'f', 2) + " RON"));
        ui->tableWidgetPortofoliu->setItem(row, 3, new QTableWidgetItem(QString::number(valoareTotala, 'f', 2) + " RON"));
        
        row++;
    }
}

void MainWindow::actualizeazaBuget()
{
    ui->labelBuget->setText("Buget: " + QString::number(portofoliu->getBuget(), 'f', 2) + " RON");
}

void MainWindow::on_buttonIstoric_clicked()
{
    // Implementare pentru afișarea istoricului tranzacțiilor
    QMessageBox::information(this, "Istoric", "Funcționalitate în dezvoltare");
}

void MainWindow::on_buttonExport_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exportă portofoliu", 
                                                  "", "CSV Files (*.csv)");
    
    if (fileName.isEmpty()) return;
    
    if (!fileName.endsWith(".csv")) {
        fileName += ".csv";
    }
    
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        
        // Header
        stream << "Simbol,Cantitate,Preț Unitar (RON),Valoare Totală (RON)\n";
        
        // Date
        QMap<QString, float> monede = portofoliu->getMonede();
        QMapIterator<QString, float> i(monede);
        
        while (i.hasNext()) {
            i.next();
            QString simbol = i.key();
            float cantitate = i.value();
            
            // Găsește ID-ul monedei pentru a obține prețul
            QString id;
            for (const auto& moneda : listaMonede) {
                if (moneda.simbol == simbol) {
                    id = moneda.id;
                    break;
                }
            }
            
            float pretUnitar = api->getPret(id).toFloat();
            float valoareTotala = cantitate * pretUnitar;
            
            stream << simbol << "," 
                   << QString::number(cantitate, 'f', 8) << "," 
                   << QString::number(pretUnitar, 'f', 2) << "," 
                   << QString::number(valoareTotala, 'f', 2) << "\n";
        }
        
        file.close();
        QMessageBox::information(this, "Export", "Portofoliul a fost exportat cu succes!");
    } else {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide fișierul pentru scriere!");
    }
}
