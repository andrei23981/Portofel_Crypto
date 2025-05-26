#include "portofoliu.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextStream>
#include <QDateTime>

Portofoliu::Portofoliu(float bugetInitial)
    : buget(bugetInitial)
{
    incarcaDate();
}

Portofoliu::~Portofoliu()
{
    salveazaDate();
}

void Portofoliu::cumpara(QString simbol, float ron, float pret)
{
    if (ron <= 0) {
        throw std::invalid_argument("Suma trebuie să fie pozitivă");
    }
    
    if (ron > buget) {
        throw std::runtime_error("Fonduri insuficiente");
    }
    
    if (pret <= 0) {
        throw std::invalid_argument("Prețul trebuie să fie pozitiv");
    }
    
    float cantitate = ron / pret;
    
    // Actualizare portofoliu
    if (monedeDetinute.contains(simbol)) {
        monedeDetinute[simbol] += cantitate;
    } else {
        monedeDetinute[simbol] = cantitate;
    }
    
    // Actualizare buget
    buget -= ron;
    
    // Adăugare tranzacție în istoric
    Tranzactie tranzactie(simbol, cantitate, pret, QDateTime::currentDateTime());
    istoricTranzactii.append(tranzactie);
    
    // Salvare date
    salveazaDate();
}

QMap<QString, float> Portofoliu::getMonede() const
{
    return monedeDetinute;
}

float Portofoliu::getBuget() const
{
    return buget;
}

QList<Tranzactie> Portofoliu::getIstoricTranzactii() const
{
    return istoricTranzactii;
}

bool Portofoliu::exportCSV(QString filePath) const
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream out(&file);
    
    // Header
    out << "Simbol,Cantitate\n";
    
    // Date
    QMapIterator<QString, float> i(monedeDetinute);
    while (i.hasNext()) {
        i.next();
        out << i.key() << "," << QString::number(i.value(), 'f', 8) << "\n";
    }
    
    file.close();
    return true;
}

void Portofoliu::salveazaDate() const
{
    QJsonObject root;
    
    // Salvare buget
    root["buget"] = buget;
    
    // Salvare monede deținute
    QJsonObject monede;
    QMapIterator<QString, float> i(monedeDetinute);
    while (i.hasNext()) {
        i.next();
        monede[i.key()] = i.value();
    }
    root["monede"] = monede;
    
    // Salvare istoric tranzacții
    QJsonArray tranzactii;
    for (const Tranzactie& t : istoricTranzactii) {
        QJsonObject tranzactie;
        tranzactie["simbol"] = t.getSimbol();
        tranzactie["cantitate"] = t.getCantitate();
        tranzactie["pret"] = t.getPret();
        tranzactie["data"] = t.getData().toString(Qt::ISODate);
        tranzactii.append(tranzactie);
    }
    root["tranzactii"] = tranzactii;
    
    // Scriere în fișier
    QJsonDocument doc(root);
    QFile file("portofoliu.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}

void Portofoliu::incarcaDate()
{
    QFile file("portofoliu.json");
    if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
        return;
    }
    
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject root = doc.object();
    
    // Încărcare buget
    if (root.contains("buget")) {
        buget = root["buget"].toDouble();
    }
    
    // Încărcare monede deținute
    if (root.contains("monede")) {
        QJsonObject monede = root["monede"].toObject();
        for (auto it = monede.begin(); it != monede.end(); ++it) {
            monedeDetinute[it.key()] = it.value().toDouble();
        }
    }
    
    // Încărcare istoric tranzacții
    if (root.contains("tranzactii")) {
        QJsonArray tranzactii = root["tranzactii"].toArray();
        for (const QJsonValue& val : tranzactii) {
            QJsonObject obj = val.toObject();
            QString simbol = obj["simbol"].toString();
            float cantitate = obj["cantitate"].toDouble();
            float pret = obj["pret"].toDouble();
            QDateTime data = QDateTime::fromString(obj["data"].toString(), Qt::ISODate);
            
            Tranzactie t(simbol, cantitate, pret, data);
            istoricTranzactii.append(t);
        }
    }
    
    file.close();
}
