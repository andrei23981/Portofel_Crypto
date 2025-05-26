#include "moneda.h"
#include <iostream>

moneda::moneda(string n, string s, float v){
    nume = n;
    simbol = s;
    valoare = v;
}

float moneda::afisare_valoare(){
    return valoare;
}
string moneda::afisare_nume(){
    return nume;
}
string moneda::afisare_simbol(){
    return simbol;
}
