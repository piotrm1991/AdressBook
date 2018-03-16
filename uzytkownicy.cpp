#include <iostream>
#include "uzytkownicy.h"

using namespace std;

char Uzytkownicy::zamienNaMalaJesliTrzeba (char znakDoKonwersji) {
    char znakPoKonwersji=znakDoKonwersji;
    if(not islower(znakDoKonwersji)) {
        znakPoKonwersji=tolower(znakDoKonwersji);
    }
    return znakPoKonwersji;
}
bool Uzytkownicy::sprawdzCzyNazwaIstnieje(string nazwa) {
    for(vector<Uzytkownik>::iterator itr=uzytkownicy.begin(); itr!=uzytkownicy.end(); itr++) {
        if(itr->nazwaUzytkownika==nazwa) {
            return false;
        }
    }
    return true;
}
void Uzytkownicy::zmienHaslo(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>ZMIANA HASLA<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<endl<<"Jestes zalogowany jako: >> "<<get_nazwaZalogowanegoUzytkownika()<<" <<"<<endl<<endl;
    string haslo;
    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    system("cls");
    cout<<"Stare haslo: >> "<<get_hasloZalogowanegoUzytkownika()<<" <<"<<endl;
    cout<<"Nowe haslo: >> "<<haslo<<" <<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy na pewno chcesz zmienic swoje haslo?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char wprowadzonaOdpowiedz;
    while(true) {
        char wybor;
        cin>>wprowadzonaOdpowiedz;
        wybor=zamienNaMalaJesliTrzeba(wprowadzonaOdpowiedz);

        switch (wybor) {
        case 't': {
            for(vector<Uzytkownik>::iterator itr=uzytkownicy.begin(); itr!=uzytkownicy.end(); itr++) {
                if(itr->idUzytkownika==get_idZalogowanegoUzytkownika()) {
                    itr->hasloUzytkownika=haslo;
                }
            }
            set_hasloZalogowanegoUzytkownika(haslo);
            plik01.odswiezZawartoscPlikuUzytkownicy(uzytkownicy);
            cout<<endl<<"Haslo ZOSTALO zmienione."<<endl;
            Sleep(1000);
            return;
        }
        break;
        case 'n': {
            cout<<endl<<"Haslo NIE zostalo zmienione."<<endl<<endl;
            return;
        }
        break;
        }
    }
}
void Uzytkownicy::dodajUzytkownika(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>REJESTRACJA NOWEGO UZYTKOWNIKA<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    string nazwa;
    cout<<"Podaj nazwe uzytkownika: ";
    cin>>nazwa;
    while (true) {
        if (sprawdzCzyNazwaIstnieje(nazwa)==false) {
            cout<<"Taki uzytykownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>nazwa;
        } else {
            break;
        }
    }
    string haslo;
    cout<<"Podaj haslo: ";
    cin>>haslo;
    system("cls");
    cout<<"Id uzytkownika: "<<plik01.u.get_id()+1<<endl;
    cout<<"Nazwa uzytkownika: "<<nazwa<<endl;
    cout<<"Haslo uzytkownika: "<<haslo<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz utworzyc takiego UZYTKOWNIKA?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char wprowadzonaOdpowiedz;
    while(true) {
        char wybor;
        cin>>wprowadzonaOdpowiedz;
        wybor=zamienNaMalaJesliTrzeba(wprowadzonaOdpowiedz);

        switch (wybor) {
        case't': {
            plik01.u.przydzielNrId();
            plik01.u.set_nazwa(nazwa);
            plik01.u.set_haslo(haslo);
            uzytkownicy.push_back(plik01.u);
            plik01.dopiszUzytkownika();
            return;
        }
        break;
        case'n': {
            return;
        }
        break;
        }
    }
}
void Uzytkownicy::wczytajUzytkownikow(){
    uzytkownicy=plik01.pobierzUzytkownikow();
    plik01.wyczyscWektor();
}
void Uzytkownicy::zalogujSie(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>LOGOWANIE<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    Uzytkownik uzytkownik;
    cout<<"Podaj nazwe uzytkownika: ";
    string nazwa;
    cin>>nazwa;
    for(vector<Uzytkownik>::iterator itr=uzytkownicy.begin(); itr!=uzytkownicy.end(); itr++) {
        if (itr->nazwaUzytkownika==nazwa) {
            for (int proby=0; proby<3; proby++) {
                cout<<"Podaj haslo. Pozostalo prob "<<3-proby<<": ";
                string haslo;
                cin>>haslo;
                if (itr->hasloUzytkownika==haslo) {
                    cout<<"Zalogowales sie. Wczytuje ksiazke adresowa..."<<endl;
                    set_idZalogowanegoUzytkownika(itr->idUzytkownika);
                    set_nazwaZalogowanegoUzytkownika(itr->nazwaUzytkownika);
                    set_hasloZalogowanegoUzytkownika(itr->hasloUzytkownika);
                    Sleep(1000);
                    return;
                }
            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
            Sleep(3000);
            return;
        }
    }
    cout<<"Nie ma uzytkownika z takim loginem."<<endl;
    Sleep(3000);
    return;
}
Uzytkownicy::Uzytkownicy(int i, string n, string h){
    idZalogowanegoUzytkownika=i;
    nazwaZalogowanegoUzytkownika=n;
    hasloZalogowanegoUzytkownika=h;
}
void Uzytkownicy::wylogujUzytkownika(int i, string n, string h){
    idZalogowanegoUzytkownika = i;
    nazwaZalogowanegoUzytkownika = n;
    hasloZalogowanegoUzytkownika = h;
}

//setter
void Uzytkownicy::set_idZalogowanegoUzytkownika(int i){
    idZalogowanegoUzytkownika=i;
}
void Uzytkownicy::set_nazwaZalogowanegoUzytkownika(string n){
    nazwaZalogowanegoUzytkownika=n;
}
void Uzytkownicy::set_hasloZalogowanegoUzytkownika(string n){
    hasloZalogowanegoUzytkownika=n;
}
//-----


//getter
int Uzytkownicy::get_idZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
string Uzytkownicy::get_nazwaZalogowanegoUzytkownika(){
    return nazwaZalogowanegoUzytkownika;
}
string Uzytkownicy::get_hasloZalogowanegoUzytkownika(){
    return hasloZalogowanegoUzytkownika;
}
//-----
