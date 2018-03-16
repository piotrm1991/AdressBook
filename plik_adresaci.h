#include <iostream>
#include "plik.h"
#include "adresat.h"
#include <vector>

using namespace std;
class PlikAdresaci :public Plik{
    vector<Adresat> pobraneAdresy;
    string nazwaPlikuTymczasowego01;
    string nazwaPlikuTymczasowego02;
public:
    Adresat a;
    PlikAdresaci(string = "Adresaci.txt", string = "PlikTymczasowy_01.txt", string = "PlikTymczasowy_02.txt");
    vector<Adresat> pobierzAdresy(int idZalogowanegoUzytkownika);
    int podajIdOstatniegoAdresu();
    void zapiszNowyAdres(Adresat nowyAdres);
    void odswiezZawartoscPlikuPoEdytowaniu(Adresat nowyAdres,  int idEdytowanegoAdresu);
    void odswiezZawartoscPlikuPoUsunieciu(int idUsuwanegoAdresu);
    void usunPlikiTymczasowe();
    void dopiszAdres();
    void wyczyscWektor();
private:
    void zapisDoPlikuTymczasowegoStarszychWpisow(int idEdytowanegoAdresu);
    void zapisDoPlikuTymczasowegoNowszychWpisow(int idEdytowanegoAdresu);
    void zapisDoPlikuStalegoStarszychWpisow();
    void zapisDoPlikuStalegoNowszychWpisow();
    int stringNaInt(string napisZmienianyNaInt);
    void podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis);
    void wczytajJedenAdres(string adres);
};
