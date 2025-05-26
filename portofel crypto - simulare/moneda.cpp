#include "moneda.h"

Moneda::Moneda(QString simbol, float cantitate)
    : simbol(simbol), cantitate(cantitate)
{
}

QString Moneda::getSimbol() const
{
    return simbol;
}

float Moneda::getCantitate() const
{
    return cantitate;
}

void Moneda::adaugaCantitate(float cantitate)
{
    this->cantitate += cantitate;
}
