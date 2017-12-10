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
char zamienNaMalaJesliTrzeba (char znakDoKonwersji) {
    char znakPoKonwersji=znakDoKonwersji;
    if(not islower(znakDoKonwersji)) {
        znakPoKonwersji=tolower(znakDoKonwersji);
    }
    return znakPoKonwersji;
}
string intNaString (int liczbaZamienianaNaString) {
    ostringstream ss;
    ss<<liczbaZamienianaNaString;
    string str=ss.str();
    return str;
}
void zapiszZaleznoscNumerIdANumerPozadkowy (map<string,int>&nrId_nrPozadkowy, vector<string>znajomi) {
    nrId_nrPozadkowy.clear();
    int iloscZnajomych=znajomi.size();
    for (int i=0; i<iloscZnajomych; i++) {
        int j=0;
        string nrId;
        string znajomy=znajomi[i];
        while(znajomy[j]!='|') {
            nrId+=znajomy[j];
            j++;
        }
        nrId_nrPozadkowy[nrId]=i;
    }
}
void podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis) {
    char znakSeparujacy = '|';
    for(size_t p=0, q=0; p!=dzielonyNapis.npos; p=q) {
        podzielonyNapis.push_back(dzielonyNapis.substr(p+(p!=0), (q=dzielonyNapis.find(znakSeparujacy, p+1))-p-(p!=0)));
    }
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
    vector<string>znajomy;
    podzialWpisuNaCzlony(daneDoWypisania,znajomy);
    cout<<"Id: "<<znajomy[0]<<endl;
    cout<<"Imie: "<<znajomy[1]<<endl;
    cout<<"Nazwisko: "<<znajomy[2]<<endl;
    cout<<"Numer telefonu: "<<znajomy[3]<<endl;
    cout<<"Email: "<<znajomy[4]<<endl;
    cout<<"Adres zamieszkania: "<<znajomy[5]<<endl;
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
        cout<<"Nie ma adresata o takim imieniu w ksiazce adresowej."<<endl;
    } else {
        wypiszDaneZnajomego(znajomi[numerSzukanegoZnajomgo]);
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
        cout<<"Nie ma adresata o takim nawisku w ksiazce adresowej."<<endl;
    } else {
        wypiszDaneZnajomego(znajomi[numerSzukanegoZnajomgo]);
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
        wypiszDaneZnajomego(znajomi[i]);
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

        cout<<"Dane adresata zostaly zapisane."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: AdressBook.txt"<<endl;
        system("pause");
    }
}
void dodajZnajomego(vector<string>&znajomi, map<string,int>&nrId_nrPorzadkowy) {
    system("cls");
    int iloscZnajomych=znajomi.size();
    int idZnajomego;
    int nrPorzadkowy=iloscZnajomych+1;
    string imie, nazwisko, numerTelefonu, email, adresZamieszkania;
    string znajomy;
    cout<<"Dodawanie nowej adresu do ksiazki adresowej."<<endl;
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

    map<string,int>::iterator itr=nrId_nrPorzadkowy.end();
    itr--;
    idZnajomego=stringNaInt(itr->first)+1;

    system("cls");
    cout<<"ID: "<<idZnajomego<<endl;
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
    cout<<"Nr telefonu: "<<numerTelefonu<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Adres: "<<adresZamieszkania<<endl<<endl;

    znajomy+=intNaString(idZnajomego)+"|"+imie+"|"+nazwisko+"|"+numerTelefonu+"|"+email+"|"+adresZamieszkania+"|";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz zapisac ten adres w Ksiazce Adresowwj?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    char wprowadzonaOdpowiedz;
    while(true) {
        char wybor;
        cin>>wprowadzonaOdpowiedz;
        wybor=zamienNaMalaJesliTrzeba(wprowadzonaOdpowiedz);

        switch (wybor) {
        case't': {
            zapisNowegoZnajomego(znajomi, znajomy);
            nrId_nrPorzadkowy[intNaString(idZnajomego)]=nrPorzadkowy;
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
void odswiezZawartoscPliku (vector<string>znajomi) {
    fstream plik;
    plik.open("AdressBook.txt",ios::in|ios::out|ios::trunc);

    if (plik.good()==false) {
        exit(0);
    }
    if (plik.good()) {
        int iloscZnajomych=znajomi.size();
        for(int i=0; i<iloscZnajomych; i++) {
            plik<<znajomi[i]<<endl;
        }
    }
    plik.close();
}
void edytowanieDanychZnajomego(vector<string>&znajomi, map<string,int>nrId_NrPorzadkowy) {
    system("cls");
    vector<string>znajomy;
    cout<<"Podaj numer porzadkowy adresata: ";
    string nrId;
    cin>>nrId;
    int nrPorzadkowy;
    if (szukajWMapie(nrId_NrPorzadkowy, nrId, nrPorzadkowy)==false) {
        cout<<"Taki adresat nie istnieje."<<endl;
        Sleep(1000);
        cout<<"Powrot do glownego menu."<<endl;
        Sleep(2000);
        return;
    } else {
        string szukanyZnajomy=znajomi[nrPorzadkowy];
        podzialWpisuNaCzlony(szukanyZnajomy,znajomy);

        while(true) {
            system("cls");
            cout<<"Id: "<<znajomy[0]<<endl;
            cout<<"Imie: "<<znajomy[1]<<endl;
            cout<<"Nazwisko: "<<znajomy[2]<<endl;
            cout<<"Numer telefonu: "<<znajomy[3]<<endl;
            cout<<"Email: "<<znajomy[4]<<endl;
            cout<<"Adres zamieszkania: "<<znajomy[5]<<endl;
            cout<<endl<<"Co chcesz zmienic?"<<endl;

            cout<<"1. Imie."<<endl;
            cout<<"2. Nazwisko."<<endl;
            cout<<"3. Numer telefonu."<<endl;
            cout<<"4. Email."<<endl;
            cout<<"5. Adres zamieszkania."<<endl;
            cout<<"6. Zapisz zmiany."<<endl;
            cout<<"7. Nie chce nic zmieniac."<<endl;
            cout<<endl<<"Dokonaj wyboru podajac jego numer(1,2,3...):";
            char wybor;
            cin>>wybor;

            switch (wybor) {
            case '1': {
                string imie;
                cout<<"Podaj nowe imie: ";
                cin>>imie;
                znajomy[1]=imie;
            }
            break;
            case '2': {
                string nazwisko;
                cout<<"Podaj nowe nazwisko: ";
                cin>>nazwisko;
                znajomy[2]=nazwisko;
            }
            break;
            case '3': {
                string nrTelefonu;
                cout<<"Podaj nowy numer telefonu: ";
                cin>>nrTelefonu;
                znajomy[3]=nrTelefonu;
            }
            break;
            case '4': {
                string email;
                cout<<"Podaj nowy email: ";
                cin>>email;
                znajomy[4]=email;
            }
            break;
            case '5': {
                string adresZamieszkania;
                cout<<"Podaj nowy adres zamieszkania: ";
                cin>>adresZamieszkania;
                znajomy[5]=adresZamieszkania;
            }
            break;
            case '6': {
                string edytowanyZnajomy;
                edytowanyZnajomy+=nrId+"|"+znajomy[1]+"|"+znajomy[2]+"|"+znajomy[3]+"|"+znajomy[4]+"|"+znajomy[5]+"|";
                znajomi[nrPorzadkowy]=edytowanyZnajomy;
                odswiezZawartoscPliku(znajomi);
                return;
            }
            break;
            case '7': {
                return;
            }
            break;
            }
        }
    }
}
void usuwanieDanychOsoby(vector<string>&znajomi, map<string,int>&nrId_nrPorzadkowy) {
    system("cls");
    string nrId;
    cout<<"Podaj numer porzadkowy adresata, ktorego dane chcesz usunac: ";
    cin>>nrId;
    int nrPorzadkowy;
    if (szukajWMapie(nrId_nrPorzadkowy,nrId, nrPorzadkowy)==false) {
        cout<<"Taki adresat nie istnieje."<<endl;
        Sleep(1000);
        cout<<"Powrot do glownego menu."<<endl;
        Sleep(2000);
        return;
    } else {
        wypiszDaneZnajomego(znajomi[nrPorzadkowy]);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Czy na pewno chcesz usunac dane tego adresata?(t/n)"<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        char wprowadzonaOdpowiedz;
        while(true) {
            char wybor;
            cin>>wprowadzonaOdpowiedz;
            wybor=zamienNaMalaJesliTrzeba(wprowadzonaOdpowiedz);

            switch (wybor) {
            case 't': {
                znajomi.erase(znajomi.begin()+nrPorzadkowy);
                odswiezZawartoscPliku(znajomi);
                zapiszZaleznoscNumerIdANumerPozadkowy(nrId_nrPorzadkowy, znajomi);
                cout<<"Dane adresata zostaly usuniete."<<endl;
                Sleep(1000);
                return;
            }
            break;
            case 'n': {
                return;
            }
            break;
            }
        }
    }
}
int main() {
    vector<string> znajomi;
    map<string,int>numerId_numerPorzadkowy;
    wczytajZnajomychZPliku(znajomi);
    zapiszZaleznoscNumerIdANumerPozadkowy(numerId_numerPorzadkowy,znajomi);
    char wybor;

    while(true) {
        system("cls");
        sprawdzeniePliku();
        cout<<"1. Wprowadz nowy adres."<<endl;
        cout<<"2. Znajdz adresata o danym imieniu."<<endl;
        cout<<"3. Znajdz adresata o danym nazwisku."<<endl;
        cout<<"4. Wyswietl wszystkie adresy."<<endl;
        cout<<"5. Edytuj dane adresata."<<endl;
        cout<<"6. Usun dane adresata."<<endl;
        cout<<"9. Zakoncz program."<<endl;
        cin>>wybor;

        switch (wybor) {
        case'1': {
            dodajZnajomego(znajomi, numerId_numerPorzadkowy);
        }
        break;
        case'2': {
            znajdzImie(znajomi);
        }
        break;
        case'3': {
            znajdzNazwisko(znajomi);
        }
        break;
        case'4': {
            wyswietlWszystkichZnajomych(znajomi);
        }
        break;
        case'5': {
            edytowanieDanychZnajomego(znajomi, numerId_numerPorzadkowy);
        }
        break;
        case'6': {
            usuwanieDanychOsoby(znajomi,numerId_numerPorzadkowy);
        }
        break;
        case'9': {
            exit(0);
        }
        break;
        }
    }
    return 0;
}
