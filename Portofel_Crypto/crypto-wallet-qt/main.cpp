#include "moneda.h"


int main(){
    moneda Bitcoin("Bitcoin", "BTC", 6700);
    cout<<Bitcoin.afisare_nume()<<endl;
    cout<<Bitcoin.afisare_simbol()<<endl;
    cout<<Bitcoin.afisare_valoare();
}
