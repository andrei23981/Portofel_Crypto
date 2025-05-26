#ifndef PORTOFOLIU_H
#define PORTOFOLIU_H

#include <QString>
#include <QMap>
#include <QList>
#include "tranzactie.h"
#include <stdexcept>

class Portofoliu
{
public:
    Portofoliu(float bugetInitial = 10000.0);
    ~Portofoliu();
    
    void cumpara(QString simbol, float ron, float pret);
    QMap<QString, float> getMonede() const;
    float getBuget() const;
    QList<Tranzactie> getIstoricTranzactii() const;
    bool exportCSV(QString filePath) const;
    
private:
    float buget;
    QMap<QString, float> monedeDetinute; // simbol -> cantitate
    QList<Tranzactie> istoricTranzactii;
    
    void salveazaDate() const;
    void incarcaDate();
};

#endif // PORTOFOLIU_H
