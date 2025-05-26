#ifndef TRANZACTIE_H
#define TRANZACTIE_H

#include <QString>
#include <QDateTime>

class Tranzactie
{
public:
    Tranzactie(QString simbol, float cantitate, float pret, QDateTime data);
    
    QString getSimbol() const;
    float getCantitate() const;
    float getPret() const;
    QDateTime getData() const;
    float getValoare() const;
    
private:
    QString simbol;
    float cantitate;
    float pret;
    QDateTime data;
};

#endif // TRANZACTIE_H
