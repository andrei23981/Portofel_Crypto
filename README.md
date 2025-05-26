# 💼 Crypto Wallet Qt

Aplicație C++ cu interfață grafică Qt pentru gestionarea unui portofoliu de criptomonede, folosind date în timp real de la CoinGecko API.

---

## 🧑‍💻 Autori

- **Andrei** – Interfață grafică + acces API CoinGecko
- **Mario** – Gestiune portofoliu, tranzacții, stocare date

---

## 🧰 Tehnologii folosite

| Componentă | Tehnologie |
|-----------|-------------|
| Limbaj | C++ |
| GUI | Qt 6 / Qt 5 |
| API prețuri | CoinGecko API |
| HTTP Requests | QtNetwork |
| JSON Parsing | QJsonDocument, QJsonObject |
| IDE recomandat | CLion + Qt Plugin / Qt Creator |

---

## 🔧 Ce face aplicația

- Selectare monedă cripto din listă (BTC, ETH, etc.)
- Afișare preț curent în RON (live)
- Introducere sumă RON pentru cumpărare
- Gestionare portofoliu (vizualizare, buget, monede)
- Export portofoliu în `.csv`
- Salvare automată locală

---

## 🔄 Împărțire sarcini

### 🎨 Andrei – GUI + API

- `mainwindow.ui` – interfața grafică Qt
- `mainwindow.cpp/h` – logica interfeței
- `api.cpp/h` – comunicare cu API CoinGecko
- `styles.qss` – stilizare interfață
- `utils.cpp/h` – validări input, formatare

#### Funcționalitate:
- Combobox cu monede disponibile
- Afișare preț curent
- Buton „Cumpără” cu feedback vizual
- Afișare erori API sau input invalid
- Legătura între interfață și Portofoliu

---

### 💰 Mario – Portofoliu + Date

- `portofoliu.cpp/h` – gestionare monede și buget
- `moneda.cpp/h` – clasa Moneda
- `tranzactie.cpp/h` – clasa Tranzactie
- `export.cpp/h` – export date în CSV
- `data.cpp/h` *(opțional)* – salvare fișier local

#### Funcționalitate:
- Inițializare buget
- Metoda `cumpara()` – update portofoliu
- Salvare/încărcare date
- Export portofoliu
- Operatori `<<`, `==` pentru debug/logare

---

