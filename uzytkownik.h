#include <iostream>

using namespace std;

class Uzytkownik{
    int idUzytkownika;
    string nazwaUzytkownika;
    string hasloUzytkownika;

public:
    Uzytkownik(int=0, string=" ", string=" ");
    friend class Uzytkownicy;
    //setter
    void set_id(int i);
    void set_nazwa(string n);
    void set_haslo(string h);
    //-----

    //getter
    const int get_id();
    const string get_nazwa();
    const string get_haslo();
    //-----
    void przydzielNrId();
};
