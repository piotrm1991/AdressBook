#include <iostream>
#include <windows.h>
#include <conio.h>
#include "logowanie.h"
#include "uzytkownicy.h"
#include "menu_glowne.h"

using namespace std;

Uzytkownicy uzytkownicy;
MenuGlowne m1;

Logowanie::Logowanie() {
    uzytkownicy.plik01.utworzPlikJesliTrzeba();
    uzytkownicy.wczytajUzytkownikow();

    char wybor;
    while(true) {
        system("cls");
        cout<<"1. Rejestracja"<<endl;
        cout<<"2. Logowanie"<<endl;
        cout<<"9. Zakoncz program"<<endl;
        cin>>wybor;

        switch(wybor) {
        case '1': {
            dodajNowegoUzytkownika();
        }
        break;
        case '2': {
            zalogujSie();
        }
        break;
        case '9': {
            zakonczProgram();
        }
        break;
        }
    }
}
void Logowanie::zalogujSie() {
    uzytkownicy.zalogujSie();
    if (uzytkownicy.get_idZalogowanegoUzytkownika()!=0) {
        m1.set_idZalogowanegoUzytkownika(uzytkownicy.get_idZalogowanegoUzytkownika());
        m1.set_nazwaZalogowanegoUzytkownika(uzytkownicy.get_nazwaZalogowanegoUzytkownika());
        while(m1.get_idZalogowanegoUzytkownika()!=0) {
            m1.wyswietlMenuGlowne();
            if(m1.get_odpowiedz()==true){
                uzytkownicy.zmienHaslo();
                m1.set_odpowiedzFalse();
            }
        }
        uzytkownicy.wylogujUzytkownika();
    }
}
void Logowanie::dodajNowegoUzytkownika() {
    uzytkownicy.dodajUzytkownika();
}
void Logowanie::zakonczProgram() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby zakonczyc program."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
    exit(0);
}
