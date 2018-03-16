#include <iostream>
#include "menu_glowne.h"
#include <windows.h>
#include "adresaci.h"

using namespace std;

Adresaci adresaci;

void MenuGlowne::wyswietlMenuGlowne(){
adresaci.plik02.utworzPlikJesliTrzeba();
adresaci.wczytajAdresy(get_idZalogowanegoUzytkownika());

    char wybor;
    while(true) {
        system("cls");
        cout<<"Jestes zalogowany jako: >>> "<<get_nazwaZalogowanegoUzytkownika()<<" <<<"<<endl;
        cout<<"W ksiazce adresowej sa >>> "<<adresaci.udostepnijIloscAdresow()<<" <<< adresy"<<endl<<endl;
        cout<<"1. Wprowadz nowy adres."<<endl;
        cout<<"2. Znajdz adresata o danym imieniu."<<endl;
        cout<<"3. Znajdz adresata o danym nazwisku."<<endl;
        cout<<"4. Wyswietl wszystkie adresy."<<endl;
        cout<<"5. Edytuj dane adresata."<<endl;
        cout<<"6. Usun dane adresata."<<endl;
        cout<<"7. Zmien haslo."<<endl;
        cout<<"9. Wyloguj sie."<<endl;
        cout<<endl<<"Wybierz 1-9: ";
        cin>>wybor;

        switch (wybor) {
        case'1': {
            dodajNowyAdres();
        }
        break;
        case'2': {
            znajdzAdresataImie();
        }
        break;
        case'3': {
            znajdzAdresataNazwisko();
        }
        break;
        case'4': {
            wyswietlWszystkieAdresy();
        }
        break;
        case'5': {
            edytujAdres();
        }
        break;
        case'6': {
            usunAdres();
        }
        break;
        case'7': {
            zmienHaslo();
            return;
        }
        break;
        case'9': {
            wyloguj();
            return;
        }
        break;
        }
    }

}
MenuGlowne::MenuGlowne(int i, string n, bool od){
    idZalogowanegoUzytkownika = i;
    nazwaZalogowanegoUzytkownika = n;
    odpowiedzHaslo = od;
}
void MenuGlowne::zmienHaslo(){
    set_odpowiedzTrue();
}
void MenuGlowne::wyloguj(){
    set_idZalogowanegoUzytkownika(0);
    set_nazwaZalogowanegoUzytkownika("");
}
void MenuGlowne::dodajNowyAdres(){
    adresaci.dodajNowyAdres(get_idZalogowanegoUzytkownika());
}
void MenuGlowne::wyswietlWszystkieAdresy(){
    adresaci.wypiszWszystkieAdresy();
}
void MenuGlowne::znajdzAdresataImie(){
    adresaci.znajdzImie();
}
void MenuGlowne::znajdzAdresataNazwisko(){
    adresaci.znjadzNazwisko();
}
void MenuGlowne::edytujAdres(){
    adresaci.edytowanieDanychAdresata();
}
void MenuGlowne::usunAdres(){
    adresaci.usuwanieAdresata();
}



//----
void MenuGlowne::set_odpowiedzTrue(bool od){
    odpowiedzHaslo = od;
}
void MenuGlowne::set_odpowiedzFalse(bool od){
    odpowiedzHaslo = od;
}
bool MenuGlowne::get_odpowiedz(){
    return odpowiedzHaslo;
}

void MenuGlowne::set_idZalogowanegoUzytkownika(int i){
    idZalogowanegoUzytkownika = i;
}
void MenuGlowne::set_nazwaZalogowanegoUzytkownika(string n){
    nazwaZalogowanegoUzytkownika = n;
}

int MenuGlowne::get_idZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
string MenuGlowne::get_nazwaZalogowanegoUzytkownika(){
    return nazwaZalogowanegoUzytkownika;
}
