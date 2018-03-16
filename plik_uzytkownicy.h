#include <iostream>
#include "plik.h"
#include "uzytkownik.h"
#include <vector>

using namespace std;

class PlikUzytkownicy :public Plik{
    vector<Uzytkownik> uzytkownicyPobraniZPliku;
public:
    Uzytkownik u;
    PlikUzytkownicy(string = "Uzytkownicy.txt");
    vector<Uzytkownik> pobierzUzytkownikow();
    void dopiszUzytkownika();
    void wyczyscWektor();
    void odswiezZawartoscPlikuUzytkownicy(vector<Uzytkownik>);
private:
    int stringNaInt(string napisZmienianyNaInt);
    void podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis);
    void wczytajDaneJednegoUzytkownika(string daneUzytkownika);
};
