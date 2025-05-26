#ifndef MONEDA_H
#define MONEDA_H

#include <QString>

class Moneda
{
public:
    Moneda(QString simbol, float cantitate);
    
    QString getSimbol() const;
    float getCantitate() const;
    void adaugaCantitate(float cantitate);
    
private:
    QString simbol;
    float cantitate;
};

#endif // MONEDA_H
