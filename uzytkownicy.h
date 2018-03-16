#include <iostream>
#include <vector>
#include "plik_uzytkownicy.h"

using namespace std;

class Uzytkownicy {
    int idZalogowanegoUzytkownika;
    string nazwaZalogowanegoUzytkownika;
    string hasloZalogowanegoUzytkownika;
public:
    PlikUzytkownicy plik01;
private:
    vector<Uzytkownik> uzytkownicy;
public:
    Uzytkownicy (int = 0, string = "", string = "");
    void dodajUzytkownika();
    void zalogujSie();
    void wczytajUzytkownikow();
    void zmienHaslo();
    void wylogujUzytkownika(int = 0, string = "", string = "");

    void set_idZalogowanegoUzytkownika(int i);
    void set_nazwaZalogowanegoUzytkownika(string n);
    void set_hasloZalogowanegoUzytkownika(string n);

    int get_idZalogowanegoUzytkownika();
    string get_nazwaZalogowanegoUzytkownika();
    string get_hasloZalogowanegoUzytkownika();

private:
    char zamienNaMalaJesliTrzeba (char znakDoKonwersji);
    bool sprawdzCzyNazwaIstnieje (string nazwa);
};
