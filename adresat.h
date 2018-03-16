#include <iostream>

using namespace std;

class Adresat{
    int idUzytkownika;
    int idAdresata;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adresZamieszkania;
public:
    void wypiszDaneAdresata();

    //setter
    void set_idUzytkownika(int i);
    void set_idAdresata(int i);
    void set_imie(string n);
    void set_nazwisko(string n);
    void set_numerTelefonu(string n);
    void set_email(string n);
    void set_adresZamieszkania(string n);
    //getter
    int get_idUzytkownika();
    int get_idAdresata();
    string get_imie();
    string get_nazwisko();
    string get_numerTelefonu();
    string get_email();
    string get_adresZamieszkania();
};
