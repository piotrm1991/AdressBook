#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <vector>
#include <map>

using namespace std;

int stringNaInt(string napisZmienianyNaInt) {
    int i;
    istringstream iss(napisZmienianyNaInt);
    iss >> i;
    return i;
}
string intNaString (int liczbaZamienianaNaString) {
    ostringstream ss;
    ss<<liczbaZamienianaNaString;
    string str=ss.str();
    return str;
}
void wczytajZnajomychZPliku(vector<string>&znajomi) {
    int nrLini=1;
    string linia;

    fstream plik;
    plik.open("AdressBook.txt",ios::in|ios::out|ios::app);

    if (plik.good()==false) {
        exit(0);
    }

    while(getline(plik,linia)) {
        switch(nrLini) {
        case 1:
            znajomi.push_back(linia);
            break;
        }

        if (nrLini==1) {
            nrLini=0;
        }
        nrLini++;
    }
    plik.close();
}
void wypiszDaneZnajomego (string daneDoWypisania) {
    int j=0;
    cout<<"ID: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    j++;
    cout<<endl<<"Imie: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    j++;
    cout<<endl<<"Nazwisko: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    j++;
    cout<<endl<<"Nr telefonu: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    j++;
    cout<<endl<<"Email: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    j++;
    cout<<endl<<"Adres zamieszkania: ";
    while(daneDoWypisania[j]!='|') {
        cout<<daneDoWypisania[j];
        j++;
    }
    cout<<endl;
}
void zapisywanieImionWMapie(vector<string>znajomi, map<string,int>&imieOrazNumer) {
    int iloscZnajomych=znajomi.size();
    for (int i=0; i<iloscZnajomych; i++) {
        int indeks=0;
        string liczba;
        string imie;
        string znajomy=znajomi[i];
        int j=0;
        while (znajomy[j]!='|') {
            liczba+=znajomy[j];
            j++;
        }
        j++;
        while (znajomy[j]!='|') {
            imie+=znajomy[j];
            j++;
        }
        indeks=stringNaInt(liczba)-1;
        imieOrazNumer[imie]=indeks;
    }
}
void zapisywanieNazwiskWMapie(vector<string>znajomi, map<string,int>&nazwiskoOrazNumer) {
    int iloscZnajomych=znajomi.size();
    for (int i=0; i<iloscZnajomych; i++) {
        int indeks=0;
        string liczba;
        string nazwisko;
        string znajomy=znajomi[i];
        int j=0;
        while (znajomy[j]!='|') {
            liczba+=znajomy[j];
            j++;
        }
        j++;
        while (znajomy[j]!='|') {
            j++;
        }
        j++;
        while (znajomy[j]!='|') {
            nazwisko+=znajomy[j];
            j++;
        }
        indeks=stringNaInt(liczba)-1;
        nazwiskoOrazNumer[nazwisko]=indeks;
    }
}
bool szukajWMapie(map<string,int>przeszukiwanaMapa, string szukanyWyraz, int& numerSzukanegoWyrazu) {
    map<string,int>::iterator itr=przeszukiwanaMapa.find(szukanyWyraz);
    if(itr!=przeszukiwanaMapa.end()) {
        numerSzukanegoWyrazu=itr->second;
        return true;
    }
    return false;
}
void znajdzImie(vector<string>znajomi) {
    system("cls");
    map<string,int>imieOrazNumer;
    zapisywanieImionWMapie(znajomi,imieOrazNumer);
    string imie;
    cout<<"Podaj imie: ";
    cin>>imie;
    int numerSzukanegoZnajomgo;
    if ((szukajWMapie(imieOrazNumer,imie,numerSzukanegoZnajomgo)==false)) {
        cout<<"Nie ma znajomego o takim imieniu w ksiazce adresowej."<<endl;
    } else {
        string znajomy=znajomi[numerSzukanegoZnajomgo];
        wypiszDaneZnajomego(znajomy);
    }
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void znajdzNazwisko(vector<string>znajomi) {
    system("cls");
    map<string,int>nazwiskoOrazNumer;
    zapisywanieNazwiskWMapie(znajomi,nazwiskoOrazNumer);
    string nazwisko;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    int numerSzukanegoZnajomgo;
    if ((szukajWMapie(nazwiskoOrazNumer,nazwisko,numerSzukanegoZnajomgo)==false)) {
        cout<<"Nie ma znajomego o takim nawisku w ksiazce adresowej."<<endl;
    } else {
        string znajomy=znajomi[numerSzukanegoZnajomgo];
        wypiszDaneZnajomego(znajomy);
    }
    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();

}
void wyswietlWszystkichZnajomych(vector<string>znajomi) {
    system("cls");
    int iloscZnajomych=znajomi.size();
    for (int i=0; i<iloscZnajomych; i++) {
        string znajomy=znajomi[i];
        wypiszDaneZnajomego(znajomy);
        cout<<"------------------------------------------------"<<endl;
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
    plik.open("AdressBook.txt",ios::out|ios::app);

    if (plik.good()==false) {
        cout<<"Nie udalo sie otworzyc pliku!"<<endl<<endl;
    } else {
        cout<<"Ksiazka adresowa zostala wczytana do programu."<<endl<<endl;
    }
    plik.close();
    cout<<"---------------------------"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void zapisNowegoZnajomego(vector<string>& znajomi, string znajomy) {
    znajomi.push_back(znajomy);

    fstream plik;
    plik.open("AdressBook.txt", ios::out|ios::app);
    if (plik.good()) {
        plik<<znajomy<<endl;

        plik.close();

        cout<<"Dane osoby zostaly zapisane."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: AdressBook.txt"<<endl;
        system("pause");
    }
}
void dodajZnajomego(vector<string>&znajomi) {
    system("cls");
    int iloscZnajomych=znajomi.size();
    int idZnajomego;
    string imie, nazwisko, numerTelefonu, email, adresZamieszkania;
    string znajomy;
    cout<<"Dodawanie nowej osoby do ksiazki adresowej."<<endl;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin, numerTelefonu);
    cout<<"Podaj email: ";
    cin>>email;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, adresZamieszkania);

    idZnajomego=iloscZnajomych+1;

    system("cls");
    cout<<"ID: "<<idZnajomego<<endl;
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
    cout<<"Nr telefonu: "<<numerTelefonu<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Adres: "<<adresZamieszkania<<endl<<endl;

    znajomy+=intNaString(idZnajomego)+"|"+imie+"|"+nazwisko+"|"+numerTelefonu+"|"+email+"|"+adresZamieszkania+"|";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz zapisac tego znajomego w Ksiazce Adresowwj?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char wybor;
    while(true) {
        cin>>wybor;
        if (wybor=='t') {
            zapisNowegoZnajomego(znajomi, znajomy);
            return;
        } else if(wybor=='n') {
            return;
        }
    }
}
int main() {
    vector<string> znajomi;
    wczytajZnajomychZPliku(znajomi);
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
            dodajZnajomego(znajomi);
        } else if (wybor=='2') {
            znajdzImie(znajomi);
        } else if (wybor=='3') {
            znajdzNazwisko(znajomi);
        } else if (wybor=='4') {
            wyswietlWszystkichZnajomych(znajomi);
        } else if (wybor=='9') {
            exit(0);
        }
    }
    return 0;
}
