# Proiect C++: Crypto Wallet

Acest proiect C++ constă în două aplicații separate care simulează un portofel de criptomonede. Nu există interacțiune directă cu utilizatorul prin tastatură; toate comenzile sunt date exclusiv prin linia de comandă. Datele sunt stocate local, folosind fișiere text sau CSV.

---

## 📁 Structura proiectului

```
/CryptoWallet/
├── shared/                 # Cod și resurse comune între aplicații
│   ├── classes/            # Clasele C++ organizate pe fișiere
│   │   ├── Moneda.cpp      # Implementare clasa Moneda
│   │   ├── Moneda.h        # Declarație clasa Moneda
│   │   ├── Api.cpp         # Implementare clasa Api (interfață spre API real CoinGecko)
│   │   ├── Api.h           # Declarație clasa Api
│   │   ├── Tranzactie.cpp  # Implementare clasa Tranzactie
│   │   ├── Tranzactie.h    # Declarație clasa Tranzactie
│   │   ├── Portofoliu.cpp  # Implementare clasa Portofoliu
│   │   ├── Portofoliu.h    # Declarație clasa Portofoliu
│   │   ├── Utils.cpp / Utils.h         # Funcții auxiliare (ex: creare Market)
│   ├── files/              # Fișiere de date partajate (monede, portofel, tranzacții)
│       ├── monede.txt          # Lista monede permise
│       ├── monede_live.csv     # Export prețuri monede live (CSV)
│       ├── portofel.txt        # Portofel - simboluri și cantități
│       ├── tranzactii.txt      # Istoric tranzacții
│       ├── portofel.csv        # Export portofel CSV
│       ├── fonduri.txt         # Fonduri disponibile
├── app1.cpp                # Executabil 1 - gestiune monede (folosește Moneda, Api)
├── app2.cpp                # Executabil 2 - portofel & tranzacții (folosește Tranzactie, Portofoliu, Moneda, Api)
├── README.md               # Documentația generală a proiectului

```

---

## 🧱 Clase principale

### Market (abstractă)
* Clasă de bază pentru orice activ tranzacționabil (criptomonede sau materiale)

### Moneda și Material

* Reprezintă o criptomonedă prin simbol (ex: BTC, ETH)

### Api (live)

* Clasa Api oferă metode statice pentru obținerea prețurilor
* getPriceFromApi(simbol, fiat = "ron") – prețul unei monede cripto
* getMetalPrice(simbol) – prețul unui metal prețios
* Trimite cerere HTTP reală către CoinGecko API
* Parsează răspunsul JSON pentru a obține prețul curent în RON
* Necesită: `libcurl` și `jsoncpp`

### Tranzactie

* Reprezintă o achiziție: simbol, cantitate, preț la cumpărare

### Portofoliu

* Gestionarea activelor, fondurilor disponibile și istoricul tranzacțiilor
* Include stocare în fișiere și export CSV

### Utils
* Funcția createMarketFromSimbol() pentru a distinge între monedă și material
* Functia template generică load_items<T> care încarcă elemente de tipul T dintr-un fișier text într-un vector
---

## 🧑‍💼 Aplicația 1: Gestiune monede & materiale (`app1.cpp`)

### Comenzi linie de comandă:

#### 🔸 Pentru monede:

* `./app1 adaugare_moneda <simbol>`  
  * Adaugă un simbol de criptomonedă în `monede.txt`

* `./app1 stergere_moneda <simbol>` 
  * Șterge simbolul criptomonedei din `monede.txt`

#### 🔸 Pentru materiale:

* `./app1 adaugare_material <simbol>`  
  * Adaugă un material prețios (ex: aur, argint) în `monede.txt`

* `./app1 stergere_material <simbol>`  
  * Șterge materialul din `monede.txt`

#### 🔸 Alte comenzi:

* `./app1 init`  
  * Reseteaza lista de monede si materiale

* `./app1 vizualizare`  
  * Afișează toate monedele și materialele + prețurile actuale (live)

* `./app1 export`  
  * Exportă lista activelor în `monede_live.csv`

### Exemple:

```
$ ./app1 init
$ ./app1 adaugare_moneda bitcoin
$ ./app1 adaugare_material aur
$ ./app1 stergere_material argint
$ ./app1 vizualizare
$ ./app1 export
```
```RULARE:   g++ -std=c++17 app1.cpp shared/classes/Moneda.cpp shared/classes/Api.cpp shared/classes/Market.cpp shared/classes/Materiale.cpp -o app1.exe -lcurl -ljsoncpp```

### Format `monede.txt`

```
bitcoin
ethereum
cardano
binancecoin
ripple
solana
polkadot
litecoin
```

### Format `monede_live.csv`

```
Simbol,PretRON
bitcoin,21800
ethereum,22600
aur,300

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
* `./app2 init <suma>`

  * Reteaza portofelul si tranzactiile si fondurile cu suma initiata
### Exemple:

```
$ ./app2 init 10000
$ ./app2 cumparare bitcoin 1500
$ ./app2 cumparare aur 700
$ ./app2 vizualizare_portofel
$ ./app2 vizualizare_tranzactii
$ ./app2 export
```
```RULARE: g++ app2.cpp shared/classes/Tranzactie.cpp shared/classes/Portofoliu.cpp shared/classes/Moneda.cpp shared/classes/Api.cpp shared/classes/Market.cpp shared/classes/Materiale.cpp shared/classes/Utils.cpp -o app2.exe -lcurl -ljsoncpp```

### Format `materiale.txt`

```
aur
argint
cupru
uraniu
fier
```

### Format `portofel.txt`

```
bitcoin 0.045
ethereum 1.23
```

### Format `tranzactii.txt`

```
bitcoin 0.045 22000
ethereum 1.23 7200
```

### Format `portofel.csv`

```
Simbol,Cantitate,PretCurentRON,ValoareRON
bitcoin,0.045,22000,990
ethereum,1.23,7200,8856
```

---

## ✅ Observații

* Prețurile sunt live (CoinGecko), cereri HTTP prin libcurl, JSON parsing prin jsoncpp

---

---

Proiect dezvoltat de: **Andrei Chindriș & Mario Bălan**

Facultatea: **Informatică**
Limbaj: **C++ Standard**
