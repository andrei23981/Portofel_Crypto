# Proiect C++: Crypto Wallet CLI

Acest proiect C++ constă în două aplicații separate care simulează un portofel de criptomonede. Nu există interacțiune directă cu utilizatorul prin tastatură; toate comenzile sunt date exclusiv prin linia de comandă. Datele sunt stocate local, folosind fișiere text sau CSV. Codul este simplu, modular, scris cu `using namespace std`.

---

## 📁 Structura proiectului

```
/CryptoWallet/
├── app1.cpp                // aplicația pentru Student 1 (gestiune monede)
├── app2.cpp                // aplicația pentru Student 2 (portofel & tranzacții)
├── monede.txt              // simboluri de monede permise
├── monede_live.csv         // export CSV cu prețuri curente
├── portofel.txt            // conține simbol + cantitate
├── tranzactii.txt          // istoric tranzacții
├── portofel.csv            // export portofel CSV
├── Makefile / CMakeLists.txt (opțional)
```

---

## 🧱 Clase principale

### Moneda

* Reprezintă o criptomonedă prin simbol (ex: BTC, ETH)

### Api (simulat)

* Metodă statică `getPrice(simbol)`
* Generează un preț determinist pentru fiecare simbol (fără cereri HTTP)

### Tranzactie

* Reprezintă o achiziție: simbol, cantitate, preț la cumpărare

### Portofoliu

* Metode statice pentru:

  * încărcare/salvare din fișiere
  * vizualizare portofel & export CSV
  * salvare tranzacții

---

## 🧑‍💼 Aplicația 1: Gestiune monede (`app1.cpp`)

### Comenzi linie de comandă:

* `./app1 adaugare <simbol>`

  * Adaugă un simbol de monedă în `monede.txt`
* `./app1 stergere <simbol>`

  * Șterge simbolul din `monede.txt`
* `./app1 vizualizare`

  * Afișează toate monedele + prețuri simulate
* `./app1 export`

  * Exportă lista în `monede_live.csv`

### Exemple:

```
$ ./app1 adaugare BTC
$ ./app1 stergere ETH
$ ./app1 vizualizare
$ ./app1 export
```
RULARE: g++ app1.cpp Moneda.cpp Api.cpp -o app1.exe -lcurl -ljsoncpp

### Format `monede.txt`

```
BTC
ETH
ADA
```

### Format `monede_live.csv`

```
Simbol,PretRON
BTC,21800
ETH,22600
```

---

## 👨‍💻 Aplicația 2: Portofel & Tranzacții (`app2.cpp`)

### Comenzi linie de comandă:

* `./app2 cumparare <simbol> <sumaRON>`

  * Calculează cantitatea cumpărată & actualizează portofelul
* `./app2 vizualizare_portofel`

  * Afișează simboluri, cantități, valoare curentă
* `./app2 vizualizare_tranzactii`

  * Afișează istoricul tranzacțiilor
* `./app2 export`

  * Exportă portofelul în `portofel.csv`

### Exemple:

```
$ ./app2 cumparare BTC 1000
$ ./app2 vizualizare_portofel
$ ./app2 vizualizare_tranzactii
$ ./app2 export
```

### Format `portofel.txt`

```
BTC 0.045
ETH 1.23
```

### Format `tranzactii.txt`

```
BTC 0.045 22000
ETH 1.23 7200
```

### Format `portofel.csv`

```
Simbol,Cantitate,PretCurentRON,ValoareRON
BTC,0.045,22000,990
ETH,1.23,7200,8856
```

---

## ✅ Observații

* Nu se folosește `std::`, se utilizează `using namespace std`
* Prețurile sunt simulate, dar codul poate fi adaptat pentru a folosi CoinGecko API
* Fiecare fișier este simplu și ușor de verificat cu `cat` sau un editor
* Nu este permisă citirea de la tastatură (`cin`)

---

## 🔧 Posibilități de extindere

* Integrarea efectivă cu API CoinGecko prin libcurl
* Adăugarea unui istoric al valorii portofoliului
* Vânzare monedă / simulare pierderi / profit
* Interfață grafică cu Qt sau o versiune Web cu C++ backend

---

Proiect dezvoltat de: **Andrei & Mario**

Facultatea: **Informatică**
Limbaj: **C++ Standard (C++11 sau mai nou)**
