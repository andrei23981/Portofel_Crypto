#include "tranzactie.h"

Tranzactie::Tranzactie(QString simbol, float cantitate, float pret, QDateTime data)
    : simbol(simbol), cantitate(cantitate), pret(pret), data(data)
{
}

QString Tranzactie::getSimbol() const
{
    return simbol;
}

float Tranzactie::getCantitate() const
{
    return cantitate;
}

float Tranzactie::getPret() const
{
    return pret;
}

QDateTime Tranzactie::getData() const
{
    return data;
}

float Tranzactie::getValoare() const
{
    return cantitate * pret;
}
