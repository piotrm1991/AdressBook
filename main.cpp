#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>

using namespace std;

struct Znajomy {
    int idZnajomego;
    string imie, nazwisko, numerTelefonu, email, adresZamieszkania;
};
int stringNaInt(string napisZmienianyNaInt) {
    int i;
    istringstream iss(napisZmienianyNaInt);
    iss >> i;
    return i;
}
int wczytajZnajomychZPliku(Znajomy znajomi[]) {
    int nrLini=1;
    string linia;
    int iloscZnajomych=0;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in|ios::out|ios::app);

    if (plik.good()==false) {
        exit(0);
    }

    while(getline(plik,linia)) {
        switch(nrLini) {
        case 1:
            znajomi[iloscZnajomych].idZnajomego=stringNaInt(linia);
            break;
        case 2:
            znajomi[iloscZnajomych].imie=linia;
            break;
        case 3:
            znajomi[iloscZnajomych].nazwisko = linia;
            break;
        case 4:
            znajomi[iloscZnajomych].numerTelefonu = linia;
            break;
        case 5:
            znajomi[iloscZnajomych].email = linia;
            break;
        case 6:
            znajomi[iloscZnajomych].adresZamieszkania = linia;
            break;
        }

        if (nrLini==6) {
            nrLini=0;
            iloscZnajomych++;
        }
        nrLini++;

    }
    plik.close();
    return iloscZnajomych;
}
void znajdzImie(Znajomy znajomi[], int iloscZnajomych) {
    system("cls");
    string imie;
    cout<<"Podaj imie: ";
    cin>>imie;

    system("cls");
    for (int i=0; i<iloscZnajomych; i++) {
        if (imie==znajomi[i].imie) {
            cout<<"ID: "<<znajomi[i].idZnajomego<<endl;
            cout<<"Imie: "<<znajomi[i].imie<<endl;
            cout<<"Nazwisko: "<<znajomi[i].nazwisko<<endl;
            cout<<"Nr telefonu: "<<znajomi[i].numerTelefonu<<endl;
            cout<<"Email: "<<znajomi[i].email<<endl;
            cout<<"Adres: "<<znajomi[i].adresZamieszkania<<endl<<endl<<endl;
        }
    }
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void znajdzNazwisko(Znajomy znajomi[], int iloscZnajomych) {
    system("cls");
    string nazwisko;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;

    system("cls");
    for (int i=0; i<iloscZnajomych; i++) {
        if (nazwisko==znajomi[i].nazwisko) {
            cout<<"ID: "<<znajomi[i].idZnajomego<<endl;
            cout<<"Imie: "<<znajomi[i].imie<<endl;
            cout<<"Nazwisko: "<<znajomi[i].nazwisko<<endl;
            cout<<"Nr telefonu: "<<znajomi[i].numerTelefonu<<endl;
            cout<<"Email: "<<znajomi[i].email<<endl;
            cout<<"Adres: "<<znajomi[i].adresZamieszkania<<endl<<endl<<endl;
        }
    }
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void wyswietlWszystkichZnajomych(Znajomy znajomi[], int iloscZnajomych) {
    system("cls");
    for (int i=0; i<iloscZnajomych; i++) {
        cout<<"ID: "<<znajomi[i].idZnajomego<<endl;
        cout<<"Imie: "<<znajomi[i].imie<<endl;
        cout<<"Nazwisko: "<<znajomi[i].nazwisko<<endl;
        cout<<"Nr telefonu: "<<znajomi[i].numerTelefonu<<endl;
        cout<<"Email: "<<znajomi[i].email<<endl;
        cout<<"Adres: "<<znajomi[i].adresZamieszkania<<endl<<endl<<endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void sprawdzeniePliku() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"---------------------------"<<endl<<endl;
    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out|ios::app);

    if (plik.good()==false) {
        cout<<"Nie udalo sie otworzyc pliku!"<<endl<<endl;
    } else {
        cout<<"Ksiazka adresowa zostala wczytana do programu."<<endl<<endl;
    }
    plik.close();
    cout<<"---------------------------"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void zapisNowegoZnajomego(Znajomy znajomi[], int iloscZnajomych, Znajomy daneDoZapisu) {
    znajomi[iloscZnajomych].idZnajomego=daneDoZapisu.idZnajomego;
    znajomi[iloscZnajomych].imie=daneDoZapisu.imie;
    znajomi[iloscZnajomych].nazwisko=daneDoZapisu.nazwisko;
    znajomi[iloscZnajomych].numerTelefonu=daneDoZapisu.numerTelefonu;
    znajomi[iloscZnajomych].email=daneDoZapisu.email;
    znajomi[iloscZnajomych].adresZamieszkania=daneDoZapisu.adresZamieszkania;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out|ios::app);
    if (plik.good()) {
        plik<<daneDoZapisu.idZnajomego<<endl;
        plik<<daneDoZapisu.imie<<endl;
        plik<<daneDoZapisu.nazwisko<<endl;
        plik<<daneDoZapisu.numerTelefonu<<endl;
        plik<<daneDoZapisu.email<<endl;
        plik<<daneDoZapisu.adresZamieszkania<<endl;

        plik.close();

        cout<<"Dane osoby zostaly zapisane."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: KsiazkaAdresowa.txt"<<endl;
        system("pause");
    }
}
int dodajZnajomego(Znajomy znajomi[], int iloscZnajomych, Znajomy daneDoZapisu) {
    system("cls");
    cout<<"Dodawanie nowej osoby do ksiazki adresowej."<<endl;
    cout<<"Podaj imie: ";
    cin>>daneDoZapisu.imie;
    cout<<"Podaj nazwisko: ";
    cin>>daneDoZapisu.nazwisko;
    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin, daneDoZapisu.numerTelefonu);
    cout<<"Podaj email: ";
    cin>>daneDoZapisu.email;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, daneDoZapisu.adresZamieszkania);

    daneDoZapisu.idZnajomego=iloscZnajomych+1;

    system("cls");
    cout<<"ID: "<<daneDoZapisu.idZnajomego<<endl;
    cout<<"Imie: "<<daneDoZapisu.imie<<endl;
    cout<<"Nazwisko: "<<daneDoZapisu.nazwisko<<endl;
    cout<<"Nr telefonu: "<<daneDoZapisu.numerTelefonu<<endl;
    cout<<"Email: "<<daneDoZapisu.email<<endl;
    cout<<"Adres: "<<daneDoZapisu.adresZamieszkania<<endl<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz zapisac tego znajomego w Ksiazce Adresowwj?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char wybor;
    while(true) {
        cin>>wybor;
        if (wybor=='t') {
            zapisNowegoZnajomego(znajomi,iloscZnajomych, daneDoZapisu);
            iloscZnajomych++;
            return iloscZnajomych;
        } else if(wybor=='n') {
            return iloscZnajomych;
        }
    }
}
int main() {
    Znajomy znajomi[1000];
    Znajomy daneDoZapisu;
    int iloscZnajomych=wczytajZnajomychZPliku(znajomi);
    char wybor;

    while(true) {
        system("cls");
        sprawdzeniePliku();
        cout<<"1. Wprowadz dane nowej osoby."<<endl;
        cout<<"2. Znajdz osobe o danym imieniu."<<endl;
        cout<<"3. Znajdz osobe o danym nazwisku."<<endl;
        cout<<"4. Wyswietl wszystkie osoby."<<endl;
        cout<<"9. Zakoncz program."<<endl;
        cin>>wybor;

        if (wybor=='1') {
            iloscZnajomych=dodajZnajomego(znajomi, iloscZnajomych, daneDoZapisu);
        } else if (wybor=='2') {
            znajdzImie(znajomi, iloscZnajomych);
        } else if (wybor=='3') {
            znajdzNazwisko(znajomi, iloscZnajomych);
        } else if (wybor=='4') {
            wyswietlWszystkichZnajomych(znajomi, iloscZnajomych);
        } else if (wybor=='9') {
            exit(0);
        }
    }
    return 0;
}
