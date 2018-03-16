#include <iostream>
#include "adresaci.h"
#include <conio.h>
#include <algorithm>

using namespace std;

void Adresaci::wczytajAdresy(int idZalogowanegoUzytkownika){
    adresy=plik02.pobierzAdresy(idZalogowanegoUzytkownika);
    plik02.wyczyscWektor();
}
void Adresaci::wypiszWszystkieAdresy(){
    system("cls");
    int iloscAdresow = udostepnijIloscAdresow();
    if(!adresy.empty()) {
        for (int i=0; i<iloscAdresow; i++) {
            adresy[i].wypiszDaneAdresata();
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
int Adresaci::udostepnijIloscAdresow(){
    int i = adresy.size();
    return i;
}
char Adresaci::zamienNaMalaJesliTrzeba (char znakDoKonwersji) {
    char znakPoKonwersji=znakDoKonwersji;
    if(not islower(znakDoKonwersji)) {
        znakPoKonwersji=tolower(znakDoKonwersji);
    }
    return znakPoKonwersji;
}
string Adresaci::zamienPierwszaNaDuza(string napis) {
    if(!napis.empty()) {
        transform(napis.begin(),napis.end(), napis.begin(),::tolower);
        napis[0]=toupper(napis[0]);
    }
    return napis;
}
void Adresaci::dodajNowyAdres(int idZalogowanegoUzytkownika){
    system("cls");
    Adresat nowyAdres;

    string imie, nazwisko, email, nrTelefonu, adresZamieszkania;
    cout<<"Dodawanie nowego adresata do ksiazki adresowej."<<endl;
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin, nrTelefonu);
    cout<<"Podaj email: ";
    cin>>email;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, adresZamieszkania);

    nowyAdres.set_idUzytkownika(idZalogowanegoUzytkownika);
    nowyAdres.set_idAdresata(plik02.podajIdOstatniegoAdresu()+1);
    nowyAdres.set_imie(zamienPierwszaNaDuza(imie));
    nowyAdres.set_nazwisko(zamienPierwszaNaDuza(nazwisko));
    nowyAdres.set_numerTelefonu(nrTelefonu);
    nowyAdres.set_email(email);
    nowyAdres.set_adresZamieszkania(adresZamieszkania);

    system("cls");
    nowyAdres.wypiszDaneAdresata();
    cout<<endl;

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
            adresy.push_back(nowyAdres);
            plik02.zapiszNowyAdres(nowyAdres);
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
void Adresaci::znajdzImie(){
    system("cls");
    if (!adresy.empty()) {
        int iloscZnalezionychZnajomych=0;
        string imieSzukanegoAdresata;
        cout<<"Podaj imie szukanego adresata: ";
        cin>>imieSzukanegoAdresata;
        imieSzukanegoAdresata=zamienPierwszaNaDuza(imieSzukanegoAdresata);
        int iloscZnajomych=adresy.size();
        for(int i=0; i<iloscZnajomych; i++) {
            if(imieSzukanegoAdresata==adresy[i].get_imie()) {
                adresy[i].wypiszDaneAdresata();
                iloscZnalezionychZnajomych++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (iloscZnalezionychZnajomych==0) {
            cout<<endl<<"Nie ma adresatow o tym imieniu."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow z imieniem: '"<<imieSzukanegoAdresata;
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
void Adresaci::znjadzNazwisko(){
    system("cls");
    if (!adresy.empty()) {
        int iloscZnalezionychZnajomych=0;
        string nazwiskoSzukanegoAdresata;
        cout<<"Podaj nazwisko szukanego adresata: ";
        cin>>nazwiskoSzukanegoAdresata;
        nazwiskoSzukanegoAdresata=zamienPierwszaNaDuza(nazwiskoSzukanegoAdresata);
        int iloscZnajomych=adresy.size();
        for(int i=0; i<iloscZnajomych; i++) {
            if(nazwiskoSzukanegoAdresata==adresy[i].get_nazwisko()) {
                adresy[i].wypiszDaneAdresata();
                iloscZnalezionychZnajomych++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (iloscZnalezionychZnajomych==0) {
            cout<<endl<<"Nie ma adresatow o tym nazwisku."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow o nazwisku: '"<<nazwiskoSzukanegoAdresata;
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
void Adresaci::edytowanieDanychAdresata(){
system("cls");
    if(!adresy.empty()) {
        bool czyAdresIstnieje=false;
        cout<<"Podaj numer ID adresata u ktorego chcesz zmienic dane: ";
        int idSzukanegoAdresu=0;
        cin>>idSzukanegoAdresu;
        if (cin.fail()) {
            cout<<endl<<"Podano niepoprawne dane. Powrot do menu glownego."<<endl<<endl;
            cin.clear();
            cin.sync();
        } else {
            for (vector<Adresat>::iterator itr=adresy.begin(); itr !=adresy.end(); itr++) {
                if(itr->get_idAdresata()==idSzukanegoAdresu) {
                    czyAdresIstnieje=true;
                    Adresat adresPrzedZmiana;
                    Adresat adresPoZmianie;


                    adresPrzedZmiana.set_idAdresata(itr->get_idAdresata());
                    adresPrzedZmiana.set_idUzytkownika(itr->get_idUzytkownika());
                    adresPrzedZmiana.set_imie(itr->get_imie());
                    adresPrzedZmiana.set_nazwisko(itr->get_nazwisko());
                    adresPrzedZmiana.set_numerTelefonu(itr->get_numerTelefonu());
                    adresPrzedZmiana.set_email(itr->get_email());
                    adresPrzedZmiana.set_adresZamieszkania(itr->get_adresZamieszkania());

                    adresPoZmianie.set_idAdresata(itr->get_idAdresata());
                    adresPoZmianie.set_idUzytkownika(itr->get_idUzytkownika());
                    adresPoZmianie.set_imie(itr->get_imie());
                    adresPoZmianie.set_nazwisko(itr->get_nazwisko());
                    adresPoZmianie.set_numerTelefonu(itr->get_numerTelefonu());
                    adresPoZmianie.set_email(itr->get_email());
                    adresPoZmianie.set_adresZamieszkania(itr->get_adresZamieszkania());

                    while(true) {
                        system("cls");
                        cout<<"Dane adresata przed zmiana:"<<endl<<endl;
                        adresPrzedZmiana.wypiszDaneAdresata();
                        cout<<endl<<"------------------------------------"<<endl<<endl;
                        cout<<"Dane adresata po zmianie:"<<endl<<endl;
                        adresPoZmianie.wypiszDaneAdresata();
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
                            adresPoZmianie.set_imie(zamienPierwszaNaDuza(imie));
                        }
                        break;
                        case '2': {
                            string nazwisko;
                            cout<<"Podaj nowe nazwisko: ";
                            cin>>nazwisko;
                            adresPoZmianie.set_nazwisko(zamienPierwszaNaDuza(nazwisko));
                        }
                        break;
                        case '3': {
                            cout<<"Podaj nowy numer telefonu: ";
                            string nrTelefonu;
                            cin.sync();
                            getline(cin, nrTelefonu);
                            adresPoZmianie.set_numerTelefonu(nrTelefonu);
                        }
                        break;
                        case '4': {
                            cout<<"Podaj nowy email: ";
                            string email;
                            cin>>email;
                            adresPoZmianie.set_email(email);
                        }
                        break;
                        case '5': {
                            cout<<"Podaj nowy adres zamieszkania: ";
                            string adresZamieszkania;
                            cin>>adresZamieszkania;
                            adresPoZmianie.set_adresZamieszkania(adresZamieszkania);
                        }
                        break;
                        case '6': {
                            itr->set_imie(adresPoZmianie.get_imie());
                            itr->set_nazwisko(adresPoZmianie.get_nazwisko());
                            itr->set_numerTelefonu(adresPoZmianie.get_numerTelefonu());
                            itr->set_email(adresPoZmianie.get_email());
                            itr->set_adresZamieszkania(adresPoZmianie.get_adresZamieszkania());
                            plik02.odswiezZawartoscPlikuPoEdytowaniu(adresPoZmianie, adresPoZmianie.get_idAdresata());
                            plik02.usunPlikiTymczasowe();
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
void Adresaci::usuwanieAdresata(){
    system("cls");
    if(!adresy.empty()) {
        bool czyIstniejeAdres=false;
        int idUsuwanegoAdresata;
        cout<<"Podaj numer ID adresata, ktorego dane chcesz usunac: ";
        cin>>idUsuwanegoAdresata;
        if (cin.fail()) {
            cout<<endl<<"Wprowadzono niepoprawne dane. Powrot do menu glownego."<<endl;
            cin.clear();
            cin.sync();
        } else {
            int liczbaAdresow=adresy.size();
            for (int i=0; i<liczbaAdresow; i++) {
                if (adresy[i].get_idAdresata()==idUsuwanegoAdresata) {
                    czyIstniejeAdres=true;

                    adresy[i].wypiszDaneAdresata();

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
                            plik02.odswiezZawartoscPlikuPoUsunieciu(adresy[i].get_idAdresata());
                            adresy.erase(adresy.begin()+i);
                            plik02.usunPlikiTymczasowe();
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
