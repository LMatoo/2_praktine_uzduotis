#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int MAX_MOKINIAI = 100;
    const int MAX_PAZYMIAI = 10;

    string mokinioVardas[MAX_MOKINIAI];
    int mokinioPazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int esamasMokiniuSkaicius = 0;
    int pazymiuKiekis[MAX_MOKINIAI] = {0};

    int meniuPasirinkimas = 0;

    while (meniuPasirinkimas != 7) {
        cout << "\n=== MOKINIU PAZYMIU SISTEMA ===" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite veiksma (1-7): ";
        cin >> meniuPasirinkimas;

        if (meniuPasirinkimas == 7) {
            cout << "Programa baigia darba. Viso gero!" << endl;
            break;
        }
        if (meniuPasirinkimas < 1 || meniuPasirinkimas > 7) {
            cout << "KLAIDA: Nera tokio pasirinkimo!" << endl;
            continue;
        }
        //1 PUNKTAS: Ivesti mokini ir jo pazymius
        if (meniuPasirinkimas == 1) {
            if (esamasMokiniuSkaicius >= MAX_MOKINIAI) {
                cout << "KLAIDA: Pasiektas maksimalus mokiniu limitas (100)!" << endl;
                continue;
            }
            cout << "Iveskite mokinio varda:";
            cin >> mokinioVardas[esamasMokiniuSkaicius];

            int kiekIvesti = 0;
            while (true) {
                cout << "Kiek pazymiu norite ivesti siam mokiniui (0-10):";
                cin >> kiekIvesti;
                if (kiekIvesti >= 0 && kiekIvesti <= MAX_PAZYMIAI) {
                    break;
                }
                cout << "KLAIDA: Galima ivesti nuo 0 iki 10 pazymiu! Bandykite is naujo." << endl;
            }
            pazymiuKiekis[esamasMokiniuSkaicius] = kiekIvesti;
            for (int j = 0; j < kiekIvesti; j++) {
                while (true) {
                    cout << "Iveskite " << j + 1 << "-aji pazymi (1-10): ";
                    int pazymys;
                    cin >> pazymys;
                    if (pazymys >= 1 && pazymys <= 10) {
                        mokinioPazymiai[esamasMokiniuSkaicius][j] = pazymys;
                        break;
                    }
                    else {
                        cout << "KLAIDA: Pazymys turi buti nuo 1-10. Bandykite dar karta." << endl;
                    }
                }
            }
            cout << "Mokinys sekmingai pridetas!" << endl;
            esamasMokiniuSkaicius++;
        }

        //2 PUNKTAS: Perziureti visu mokiniu pazymius
        else if (meniuPasirinkimas == 2) {
            if (esamasMokiniuSkaicius == 0) {
                cout << "Sarase nera mokiniu." << endl;
                continue;
            }
            cout << "\n--- VISU MOKINIU PAZYMIAI ---" << endl;
            for (int i = 0; i < esamasMokiniuSkaicius; i++) {
                cout << i + 1 << ". " << mokinioVardas[i] << ": ";
                if (pazymiuKiekis[i] == 0) {
                    cout << "Pazymiu nera";
                }
                else  {
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << mokinioPazymiai[i][j] << "; ";
                    }
                }
                cout << endl;
            }
        }
        // 3 PUNKTAS: Perziureti konkretaus mokinio pazymius
        else if (meniuPasirinkimas == 3) {
            if (esamasMokiniuSkaicius == 0) {
                cout << "Sarase nera mokiniu." << endl;
                continue;
            }
            int mokinioNr;
            while (true) {
                cout << "Iveskite mokinio numeri (1-" << esamasMokiniuSkaicius << "): ";
                cin >> mokinioNr;
                if (mokinioNr >= 1 && mokinioNr <= esamasMokiniuSkaicius) {
                    break;
                }
                cout << "KLAIDA: Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki " << esamasMokiniuSkaicius << "." << endl;
            }
            int indeksas = mokinioNr - 1;
            cout << "\nMokinys: " << mokinioVardas[indeksas] << endl;
            cout << "Pazymiai: ";
            if (pazymiuKiekis[indeksas] == 0) {
                cout << "Pazymiu nera";
            }
            else {
                for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                    cout << mokinioPazymiai[indeksas][j] << " ";
                }
            }
            cout << endl;
        }
    }
        return 0;
    }
