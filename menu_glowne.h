#include <iostream>

using namespace std;

class MenuGlowne{
    int idZalogowanegoUzytkownika;
    string nazwaZalogowanegoUzytkownika;
    bool odpowiedzHaslo;
public:
    MenuGlowne(int = 0, string = "", bool = false);
    void wyswietlMenuGlowne();
    void dodajNowyAdres();
    void wyswietlWszystkieAdresy();
    void znajdzAdresataImie();
    void znajdzAdresataNazwisko();
    void edytujAdres();
    void usunAdres();
    void zmienHaslo();
    void wyloguj();

    void set_odpowiedzFalse(bool = false);
    void set_odpowiedzTrue(bool = true);
    bool get_odpowiedz();

    void set_idZalogowanegoUzytkownika(int i);
    void set_nazwaZalogowanegoUzytkownika(string n);

    int get_idZalogowanegoUzytkownika();
    string get_nazwaZalogowanegoUzytkownika();
};
