#include <iostream>

using namespace std;

class Uzytkownik{

    int idUzytkownika;
    string nazwaUzytkownika;
    string haslo;

public:
    Uzytkownik(int=0, string=" ", string=" ");
    void wprowadzDaneNoewgoUzytkownika();
    void zmienHaslo();
};
