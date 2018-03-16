#include <iostream>
#include <vector>
#include "plik_adresaci.h"

using namespace std;

class Adresaci{

public:
    PlikAdresaci plik02;
private:
    vector<Adresat> adresy;
    string zamienPierwszaNaDuza(string napis);
    char zamienNaMalaJesliTrzeba (char znakDoKonwersji);
public:
    void znajdzImie();
    void znjadzNazwisko();
    void edytowanieDanychAdresata();
    void usuwanieAdresata();
    void wczytajAdresy(int idZalogowanegoUzytkownika);
    void wypiszWszystkieAdresy();
    int udostepnijIloscAdresow();
    void dodajNowyAdres(int idZalogowanegoUzytkownika);
};
