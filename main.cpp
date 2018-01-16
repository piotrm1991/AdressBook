#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct Znajomy {
    int idZnajomego;
    string imie, nazwisko, numerTelefonu,email,adresZamieszkania;
};
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
string zamienPierwszaNaDuza(string napis) {
    if(!napis.empty()) {
        transform(napis.begin(),napis.end(), napis.begin(),::tolower);
        napis[0]=toupper(napis[0]);
    }
    return napis;
}
string intNaString (int liczbaZamienianaNaString) {
    ostringstream ss;
    ss<<liczbaZamienianaNaString;
    string str=ss.str();
    return str;
}
void podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis) {
    char znakSeparujacy = '|';
    int dlugoscNapisy=dzielonyNapis.size();
    for(size_t p=0, q=0; p!=dzielonyNapis.npos; p=q) {
        if ((dlugoscNapisy-p)==1) {
            break;
        }
        podzielonyNapis.push_back(dzielonyNapis.substr(p+(p!=0), (q=dzielonyNapis.find(znakSeparujacy, p+1))-p-(p!=0)));
    }
}
Znajomy wczytajDaneJednegoZnajomego(string daneZnajomego) {
    Znajomy znajomy;
    vector<string>podzieloneDaneZnajomego;
    podzialWpisuNaCzlony(daneZnajomego,podzieloneDaneZnajomego);
    int iloscDanychAdresata=podzieloneDaneZnajomego.size();
    for (int numerPojedynczejDanejZnajomego=0; numerPojedynczejDanejZnajomego<iloscDanychAdresata; numerPojedynczejDanejZnajomego++) {
        switch(numerPojedynczejDanejZnajomego) {
        case 0:
            znajomy.idZnajomego=stringNaInt(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        case 1:
            znajomy.imie=podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego];
            break;
        case 2:
            znajomy.nazwisko=podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego];
            break;
        case 3:
            znajomy.numerTelefonu=podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego];
            break;
        case 4:
            znajomy.email=podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego];
            break;
        case 5:
            znajomy.adresZamieszkania=podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego];
            break;
        }
    }
    return znajomy;
}
void wczytajZnajomychZPliku(vector<Znajomy>&znajomi) {
    Znajomy znajomy;
    string linia="";

    fstream plik;
    plik.open("AdressBook.txt",ios::in);

    if (plik.good()==false) {
        exit(0);
    }

    while(getline(plik,linia)) {
        znajomy=wczytajDaneJednegoZnajomego(linia);
        znajomi.push_back(znajomy);
    }
    plik.close();
}
void wypiszDaneZnajomego (Znajomy znajomy) {
    cout<<"Id: "<<znajomy.idZnajomego<<endl;
    cout<<"Imie: "<<znajomy.imie<<endl;
    cout<<"Nazwisko: "<<znajomy.nazwisko<<endl;
    cout<<"Numer telefonu: "<<znajomy.numerTelefonu<<endl;
    cout<<"Email: "<<znajomy.email<<endl;
    cout<<"Adres zamieszkania: "<<znajomy.adresZamieszkania<<endl;
}
void znajdzImie(vector<Znajomy>znajomi) {
    system("cls");
    if (!znajomi.empty()) {
        int iloscZnalezionychZnajomych=0;
        string imieSzukanegoZnajomego;
        cout<<"Podaj imie szukanego adresata: ";
        cin>>imieSzukanegoZnajomego;
        imieSzukanegoZnajomego=zamienPierwszaNaDuza(imieSzukanegoZnajomego);
        int iloscZnajomych=znajomi.size();
        for(int i=0; i<iloscZnajomych; i++) {
            if(imieSzukanegoZnajomego==znajomi[i].imie) {
                wypiszDaneZnajomego(znajomi[i]);
                iloscZnalezionychZnajomych++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (iloscZnalezionychZnajomych==0) {
            cout<<endl<<"Nie ma adresatow o tym imieniu."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow z imieniem: '"<<imieSzukanegoZnajomego;
            cout<<"' w ksiazce adresowej wynosi: "<<iloscZnalezionychZnajomych<<endl<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
    }

    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void znajdzNazwisko(vector<Znajomy>znajomi) {
    system("cls");
    if (!znajomi.empty()) {
        int iloscZnalezionychZnajomych=0;
        string nazwiskoSzukanegoZnajomego;
        cout<<"Podaj nazwisko szukanego adresata: ";
        cin>>nazwiskoSzukanegoZnajomego;
        nazwiskoSzukanegoZnajomego=zamienPierwszaNaDuza(nazwiskoSzukanegoZnajomego);
        int iloscZnajomych=znajomi.size();
        for(int i=0; i<iloscZnajomych; i++) {
            if(nazwiskoSzukanegoZnajomego==znajomi[i].nazwisko) {
                wypiszDaneZnajomego(znajomi[i]);
                iloscZnalezionychZnajomych++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (iloscZnalezionychZnajomych==0) {
            cout<<endl<<"Nie ma adresatow o tym nazwisku."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow o nazwisku: '"<<nazwiskoSzukanegoZnajomego;
            cout<<"' w ksiazce adresowej wynosi: "<<iloscZnalezionychZnajomych<<endl<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
    }

    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void wyswietlWszystkichZnajomych(vector<Znajomy>znajomi) {
    system("cls");
    int iloscZnajomych=znajomi.size();
    if(!znajomi.empty()) {
        for (int i=0; i<iloscZnajomych; i++) {
            wypiszDaneZnajomego(znajomi[i]);
            cout<<endl<<"------------------------------------------------"<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
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
void zapisNowegoZnajomego(Znajomy znajomy) {
    fstream plik;
    plik.open("AdressBook.txt", ios::out|ios::app);
    if (plik.good()==true) {
        plik<<znajomy.idZnajomego<<'|';
        plik<<znajomy.imie<<'|';
        plik<<znajomy.nazwisko<<'|';
        plik<<znajomy.numerTelefonu<<'|';
        plik<<znajomy.email<<'|';
        plik<<znajomy.adresZamieszkania<<'|'<<endl;

        plik.close();

        cout<<"Dane adresata zostaly ZAPISANE."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: AdressBook.txt"<<endl;
        system("pause");
    }
}
void dodajZnajomego(vector<Znajomy>&znajomi) {
    system("cls");
    Znajomy znajomy;

    cout<<"Dodawanie nowego adresata do ksiazki adresowej."<<endl;
    cout<<"Podaj imie: ";
    cin>>znajomy.imie;
    cout<<"Podaj nazwisko: ";
    cin>>znajomy.nazwisko;
    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin, znajomy.numerTelefonu);
    cout<<"Podaj email: ";
    cin>>znajomy.email;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, znajomy.adresZamieszkania);

    if (znajomi.empty()==true) {
        znajomy.idZnajomego=1;
    } else {
        znajomy.idZnajomego=znajomi.back().idZnajomego+1;
    }

    system("cls");
    cout<<"ID: "<<znajomy.idZnajomego<<endl;
    cout<<"Imie: "<<znajomy.imie<<endl;
    cout<<"Nazwisko: "<<znajomy.nazwisko<<endl;
    cout<<"Nr telefonu: "<<znajomy.numerTelefonu<<endl;
    cout<<"Email: "<<znajomy.email<<endl;
    cout<<"Adres: "<<znajomy.adresZamieszkania<<endl<<endl;

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
            znajomi.push_back(znajomy);
            zapisNowegoZnajomego(znajomy);
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
void odswiezZawartoscPliku (vector<Znajomy>znajomi) {
    fstream plik;
    plik.open("AdressBook.txt",ios::in|ios::out|ios::trunc);

    if (plik.good()==false) {
        exit(0);
    }
    if (plik.good()) {
        int iloscZnajomych=znajomi.size();
        for(int i=0; i<iloscZnajomych; i++) {
            plik<<znajomi[i].idZnajomego<<'|';
            plik<<znajomi[i].imie<<'|';
            plik<<znajomi[i].nazwisko<<'|';
            plik<<znajomi[i].numerTelefonu<<'|';
            plik<<znajomi[i].email<<'|';
            plik<<znajomi[i].adresZamieszkania<<'|'<<endl;
        }
    }
    plik.close();
}
void edytowanieDanychZnajomego(vector<Znajomy>&znajomi) {
    system("cls");
    if(!znajomi.empty()) {
        bool czyAdresIstnieje=false;
        cout<<"Podaj numer ID adresata u ktorego chcesz zmienic dane: ";
        int idSzukanegoZnajomego=0;
        cin>>idSzukanegoZnajomego;
        if (cin.fail()) {
            cout<<endl<<"Podano niepoprawne dane. Powrot do menu glownego."<<endl<<endl;
            cin.clear();
            cin.sync();
        } else {
            for (vector<Znajomy>::iterator itr=znajomi.begin(); itr !=znajomi.end(); itr++) {
                if(itr->idZnajomego==idSzukanegoZnajomego) {
                    czyAdresIstnieje=true;
                    Znajomy znajomyPrzedZmiana;
                    Znajomy znajomyPoZmianie;


                    znajomyPrzedZmiana.idZnajomego=itr->idZnajomego;
                    znajomyPrzedZmiana.imie=itr->imie;
                    znajomyPrzedZmiana.nazwisko=itr->nazwisko;
                    znajomyPrzedZmiana.numerTelefonu=itr->numerTelefonu;
                    znajomyPrzedZmiana.email=itr->email;
                    znajomyPrzedZmiana.adresZamieszkania=itr->adresZamieszkania;

                    znajomyPoZmianie.idZnajomego=itr->idZnajomego;
                    znajomyPoZmianie.imie=itr->imie;
                    znajomyPoZmianie.nazwisko=itr->nazwisko;
                    znajomyPoZmianie.numerTelefonu=itr->numerTelefonu;
                    znajomyPoZmianie.email=itr->email;
                    znajomyPoZmianie.adresZamieszkania=itr->adresZamieszkania;

                    while(true) {
                        system("cls");
                        cout<<"Dane adresata przed zmiana:"<<endl<<endl;
                        wypiszDaneZnajomego(znajomyPrzedZmiana);
                        cout<<endl<<"------------------------------------"<<endl<<endl;
                        cout<<"Dane adresata po zmianie:"<<endl<<endl;
                        wypiszDaneZnajomego(znajomyPoZmianie);
                        cout<<endl<<"------------------------------------"<<endl<<endl;

                        cout<<"Co chcesz zmienic?"<<endl;

                        cout<<"1 - Imie."<<endl;
                        cout<<"2 - Nazwisko."<<endl;
                        cout<<"3 - Numer telefonu."<<endl;
                        cout<<"4 - Email."<<endl;
                        cout<<"5 - Adres zamieszkania."<<endl;
                        cout<<"6 - Zapisz zmiany."<<endl;
                        cout<<"7 - Nie chce nic zmieniac."<<endl;
                        cout<<endl<<"Wybierz 1-7:";
                        char wybor;
                        cin>>wybor;

                        switch (wybor) {
                        case '1': {
                            string imie;
                            cout<<"Podaj nowe imie: ";
                            cin>>imie;
                            zamienPierwszaNaDuza(imie);
                            znajomyPoZmianie.imie=imie;
                        }
                        break;
                        case '2': {
                            string nazwisko;
                            cout<<"Podaj nowe nazwisko: ";
                            cin>>nazwisko;
                            zamienPierwszaNaDuza(nazwisko);
                            znajomyPoZmianie.nazwisko=nazwisko;
                        }
                        break;
                        case '3': {
                            cout<<"Podaj nowy numer telefonu: ";
                            cin.sync();
                            getline(cin, znajomyPoZmianie.numerTelefonu);
                        }
                        break;
                        case '4': {
                            cout<<"Podaj nowy email: ";
                            cin>>znajomyPoZmianie.email;
                        }
                        break;
                        case '5': {
                            cout<<"Podaj nowy adres zamieszkania: ";
                            cin>>znajomyPoZmianie.adresZamieszkania;
                        }
                        break;
                        case '6': {
                            itr->imie=znajomyPoZmianie.imie;
                            itr->nazwisko=znajomyPoZmianie.nazwisko;
                            itr->numerTelefonu=znajomyPoZmianie.numerTelefonu;
                            itr->email=znajomyPoZmianie.email;
                            itr->adresZamieszkania=znajomyPoZmianie.adresZamieszkania;
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
            if (czyAdresIstnieje==false) {
                cout<<endl<<"Nie ma takiego adresata w ksiazce adresowej."<<endl<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                getch();
            }
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        getch();
    }
}
void usuwanieDanychOsoby(vector<Znajomy>&znajomi) {
    system("cls");
    if(!znajomi.empty()) {
        bool czyIstniejeAdres=false;
        int idUsuwanegoAdresata;
        cout<<"Podaj numer ID adresata, ktorego dane chcesz usunac: ";
        cin>>idUsuwanegoAdresata;
        if (cin.fail()) {
            cout<<endl<<"Wprowadzono niepoprawne dane. Powrot do menu glownego."<<endl;
            cin.clear();
            cin.sync();
        } else {
            int liczbaAdresow=znajomi.size();
            for (int i=0; i<liczbaAdresow; i++) {
                if (znajomi[i].idZnajomego==idUsuwanegoAdresata) {
                    czyIstniejeAdres=true;

                    wypiszDaneZnajomego(znajomi[i]);

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
                            znajomi.erase(znajomi.begin()+i);
                            odswiezZawartoscPliku(znajomi);
                            cout<<endl<<"Dane adresata zostaly USUNIETE."<<endl;
                            Sleep(1000);
                            return;
                        }
                        break;
                        case 'n': {
                            cout<<endl<<"Wybrany adresat NIE zostal usuniety."<<endl<<endl;
                            return;
                        }
                        break;
                        }
                    }
                }
            }
            if(czyIstniejeAdres==false) {
                cout<<endl<<"Nie ma takiego adresata w ksiazce adresowej."<<endl<<endl;
            }
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        getch();
    }
}
void zakonczProgram() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby zakonczyc program."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
    exit(0);
}
int main() {
    vector<Znajomy> znajomi;
    wczytajZnajomychZPliku(znajomi);
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
            dodajZnajomego(znajomi);
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
            edytowanieDanychZnajomego(znajomi);
        }
        break;
        case'6': {
            usuwanieDanychOsoby(znajomi);
        }
        break;
        case'9': {
            zakonczProgram();
        }
        break;
        }
    }
    return 0;
}
