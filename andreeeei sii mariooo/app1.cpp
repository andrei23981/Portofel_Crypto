#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Clasa Moneda: reprezentare a unei monede prin simbol
class Moneda {
private:
    string simbol;
public:
    Moneda(string s) : simbol(s) {}
    string getSimbol() const { return simbol; }
};

// Clasa Api (simulată): returnează prețul unei monede în RON
class Api {
public:
    static double getPrice(const string& simbol) {
        // Simulează prețul pe baza simbolului (valoare deterministă simplă)
        double price = 0.0;
        for (char c : simbol) price += (int)c;
        // Ajustăm pentru a obține valori utile
        price = fmod(price * 100, 100000) + 100; // între 100 și 100100 RON
        return price;
    }
};

// Afișează în consolă monedele din monede.txt și prețurile lor
void view_coins() {
    ifstream infile("monede.txt");
    if (!infile) {
        cout << "Fisierul monede.txt nu exista sau nu poate fi deschis.\n";
        return;
    }
    cout << "Simbol - Pret (RON)\n";
    string simbol;
    while (infile >> simbol) {
        double price = Api::getPrice(simbol);
        cout << simbol << " - " << price << "\n";
    }
    infile.close();
}

// Adaugă un simbol de monedă în monede.txt (dacă nu există deja)
void add_coin(const string& simbol) {
    // Verificăm duplicat
    ifstream infile("monede.txt");
    string line;
    while (getline(infile, line)) {
        if (line == simbol) {
            cout << "Moneda " << simbol << " exista deja.\n";
            return;
        }
    }
    infile.close();
    // Adăugăm simbolul la sfârșit
    ofstream outfile("monede.txt", ios::app);
    if (!outfile) {
        cout << "Eroare la scrierea in fisierul monede.txt\n";
        return;
    }
    outfile << simbol << "\n";
    outfile.close();
    cout << "Moneda " << simbol << " adaugata.\n";
}

// Șterge un simbol de monedă din monede.txt
void remove_coin(const string& simbol) {
    ifstream infile("monede.txt");
    if (!infile) { 
        cout << "Fisierul monede.txt nu exista.\n"; 
        return; 
    }
    vector<string> all;
    string line;
    bool found = false;
    while (getline(infile, line)) {
        if (line == simbol) {
            found = true;
        } else {
            all.push_back(line);
        }
    }
    infile.close();
    if (!found) {
        cout << "Moneda " << simbol << " nu a fost gasita.\n";
        return;
    }
    ofstream outfile("monede.txt");
    for (auto &s : all) {
        outfile << s << "\n";
    }
    outfile.close();
    cout << "Moneda " << simbol << " stearsa.\n";
}

// Exportă lista de monede și prețuri în monede_live.csv
void export_coins() {
    ifstream infile("monede.txt");
    if (!infile) {
        cout << "Fisierul monede.txt nu exista.\n";
        return;
    }
    ofstream csv("monede_live.csv");
    if (!csv) {
        cout << "Eroare la crearea fisierului monede_live.csv\n";
        return;
    }
    csv << "Simbol,PretRON\n";
    string simbol;
    while (infile >> simbol) {
        double price = Api::getPrice(simbol);
        csv << simbol << "," << price << "\n";
    }
    infile.close();
    csv.close();
    cout << "Lista monede exportata in monede_live.csv.\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Comanda invalida. Comenzi posibile: adaugare, stergere, vizualizare, export\n";
        return 1;
    }
    string cmd = argv[1];
    if (cmd == "adaugare") {
        if (argc != 3) {
            cout << "Utilizare: adaugare <simbol>\n";
            return 1;
        }
        add_coin(argv[2]);
    } else if (cmd == "stergere") {
        if (argc != 3) {
            cout << "Utilizare: stergere <simbol>\n";
            return 1;
        }
        remove_coin(argv[2]);
    } else if (cmd == "vizualizare") {
        view_coins();
    } else if (cmd == "export") {
        export_coins();
    } else {
        cout << "Comanda necunoscuta.\n";
        return 1;
    }
    return 0;
}
