#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Clasa Moneda: simbolul monedei
class Moneda {
private:
    string simbol;
public:
    Moneda(string s) : simbol(s) {}
    string getSimbol() const { return simbol; }
};

// Clasa Tranzactie: detaliile unei tranzacții (simbol, cantitate, preț)
class Tranzactie {
private:
    string simbol;
    double cantitate;
    double pret;
public:
    Tranzactie(string s, double c, double p) : simbol(s), cantitate(c), pret(p) {}
    string getSimbol() const { return simbol; }
    double getCantitate() const { return cantitate; }
    double getPret() const { return pret; }
};

// Clasa Api: obține prețul curent (simulat) al unei monede
class Api {
public:
    static double getPrice(const string& simbol) {
        double price = 0.0;
        for(char c : simbol) price += (int)c;
        price = fmod(price * 100, 100000) + 100;
        return price;
    }
};

// Clasa Portofoliu: gestiunea portofelului și a tranzacțiilor
class Portofoliu {
public:
    // Încarcă portofelul din fișier (simbol - cantitate)
    static vector<pair<string,double>> load() {
        vector<pair<string,double>> wallet;
        ifstream infile("portofel.txt");
        if (!infile) return wallet;
        string simbol;
        double cant;
        while(infile >> simbol >> cant) {
            wallet.push_back({simbol, cant});
        }
        infile.close();
        return wallet;
    }
    // Salvează portofelul în fișier (suprascrie conținutul)
    static void save(const vector<pair<string,double>>& wallet) {
        ofstream outfile("portofel.txt");
        for (auto &p : wallet) {
            outfile << p.first << " " << p.second << "\n";
        }
        outfile.close();
    }
    // Adaugă o tranzacție în fișierul tranzactii.txt
    static void appendTranzactie(const Tranzactie& t) {
        ofstream outfile("tranzactii.txt", ios::app);
        if (!outfile) return;
        outfile << t.getSimbol() << " " << t.getCantitate() << " " << t.getPret() << "\n";
        outfile.close();
    }
    // Afișează portofoliul în consolă (simbol, cantitate, valoare curentă)
    static void view() {
        auto wallet = load();
        if (wallet.empty()) {
            cout << "Portofel gol.\n";
            return;
        }
        double total = 0;
        cout << "Portofoliu:\nSimbol - Cantitate - ValoareCurenta(RON)\n";
        for (auto &p : wallet) {
            double price = Api::getPrice(p.first);
            double value = p.second * price;
            total += value;
            cout << p.first << " - " << p.second << " - " << value << "\n";
        }
        cout << "Valoare totala portofoliu: " << total << " RON\n";
    }
    // Exportă portofoliul în fișier CSV
    static void exportCSV() {
        auto wallet = load();
        if (wallet.empty()) {
            cout << "Portofel gol, nimic de exportat.\n";
            return;
        }
        ofstream csv("portofel.csv");
        if (!csv) {
            cout << "Eroare la crearea fisierului portofel.csv\n";
            return;
        }
        csv << "Simbol,Cantitate,PretCurentRON,ValoareRON\n";
        for (auto &p : wallet) {
            double price = Api::getPrice(p.first);
            double value = p.second * price;
            csv << p.first << "," << p.second << "," << price << "," << value << "\n";
        }
        csv.close();
        cout << "Portofel exportat in portofel.csv\n";
    }
};

// Funcție care realizează cumpărarea unei monede
void buy_coin(const string& simbol, double sumaRON) {
    // Verificăm existența monedei în lista de monede admise
    ifstream infile("monede.txt");
    bool found = false;
    string line;
    while (infile >> line) {
        if (line == simbol) { found = true; break; }
    }
    infile.close();
    if (!found) {
        cout << "Moneda " << simbol << " nu exista in lista.\n";
        return;
    }
    // Calculăm cantitatea de monedă cumpărată
    double price = Api::getPrice(simbol);
    double qty = sumaRON / price;
    if (qty <= 0) {
        cout << "Suma invalida.\n";
        return;
    }
    // Încarcăm portofelul existent
    auto wallet = Portofoliu::load();
    bool exists = false;
    // Actualizăm cantitatea pentru simbolul achiziționat
    for (auto &p : wallet) {
        if (p.first == simbol) {
            p.second += qty;
            exists = true;
            break;
        }
    }
    if (!exists) {
        wallet.push_back({simbol, qty});
    }
    // Salvăm portofelul actualizat și tranzacția
    Portofoliu::save(wallet);
    Tranzactie t(simbol, qty, price);
    Portofoliu::appendTranzactie(t);
    cout << "Cumparat " << qty << " " << simbol 
         << " cu " << sumaRON << " RON (pret " << price << " RON)\n";
}

// Afișează tranzacțiile realizate (din fișier)
void view_tranzactii() {
    ifstream infile("tranzactii.txt");
    if (!infile) {
        cout << "Nu exista tranzactii.\n";
        return;
    }
    cout << "Tranzactii:\nSimbol - Cantitate - Pret(RON)\n";
    string simbol;
    double cant, pret;
    while (infile >> simbol >> cant >> pret) {
        cout << simbol << " - " << cant << " - " << pret << "\n";
    }
    infile.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Comanda invalida. Comenzi posibile: cumparare, vizualizare_portofel, vizualizare_tranzactii, export\n";
        return 1;
    }
    string cmd = argv[1];
    if (cmd == "cumparare") {
        if (argc != 4) {
            cout << "Utilizare: cumparare <simbol> <sumaRON>\n";
            return 1;
        }
        string simbol = argv[2];
        double sumaRON = atof(argv[3]);
        buy_coin(simbol, sumaRON);
    } else if (cmd == "vizualizare_portofel") {
        Portofoliu::view();
    } else if (cmd == "vizualizare_tranzactii") {
        view_tranzactii();
    } else if (cmd == "export") {
        Portofoliu::exportCSV();
    } else {
        cout << "Comanda necunoscuta.\n";
        return 1;
    }
    return 0;
}
