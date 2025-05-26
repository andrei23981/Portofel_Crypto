#ifndef _MONEDA_H_
#define _MONEDA_H_
#include <iostream>
#include <string>
#include <QString>

using namespace std;            

class moneda{
private:
    string nume;
    string simbol;
    float valoare;

public:
    moneda(string n, string s, float v){
    nume = n;
    simbol = s;
    valoare = v;
}
    float afisare_valoare(){
        return valoare;
    }

    string afisare_nume(){
        return nume;
    }

    string afisare_simbol(){
        return simbol;
    }
};

#endif