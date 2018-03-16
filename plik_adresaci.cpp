#include <iostream>
#include "plik_adresaci.h"
#include <vector>
#include <sstream>

using namespace std;
/*PlikAdresaci::PlikAdresaci(string nazwa1) {
    nazwaPliku = nazwa1;
}*/
PlikAdresaci::PlikAdresaci(string nazwa1, string nazwa2, string nazwa3) {
    nazwaPliku = nazwa1;
    nazwaPlikuTymczasowego01 = nazwa2;
    nazwaPlikuTymczasowego02 = nazwa3;
}
void PlikAdresaci::wyczyscWektor(){
    pobraneAdresy.clear();
}
int PlikAdresaci::stringNaInt(string napisZmienianyNaInt) {
    int i;
    istringstream iss(napisZmienianyNaInt);
    iss >> i;
    return i;
}
void PlikAdresaci::podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis) {
    char znakSeparujacy = '|';
    int dlugoscNapisy=dzielonyNapis.size();
    for(size_t p=0, q=0; p!=dzielonyNapis.npos; p=q) {
        if ((dlugoscNapisy-p)==1) {
            break;
        }
        podzielonyNapis.push_back(dzielonyNapis.substr(p+(p!=0), (q=dzielonyNapis.find(znakSeparujacy, p+1))-p-(p!=0)));
    }
}
void PlikAdresaci::wczytajJedenAdres(string adres) {
    vector<string>podzieloneDaneZnajomego;
    podzialWpisuNaCzlony(adres,podzieloneDaneZnajomego);
    int iloscDanychAdresata=podzieloneDaneZnajomego.size();
    for (int numerPojedynczejDanejZnajomego=0; numerPojedynczejDanejZnajomego<iloscDanychAdresata; numerPojedynczejDanejZnajomego++) {
        switch(numerPojedynczejDanejZnajomego) {
        case 0:
            a.set_idAdresata(stringNaInt(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]));
            break;
        case 1:
            a.set_idUzytkownika(stringNaInt(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]));
            break;
        case 2:
            a.set_imie(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        case 3:
            a.set_nazwisko(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        case 4:
            a.set_numerTelefonu(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        case 5:
            a.set_email(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        case 6:
            a.set_adresZamieszkania(podzieloneDaneZnajomego[numerPojedynczejDanejZnajomego]);
            break;
        }
    }
}
vector<Adresat> PlikAdresaci::pobierzAdresy(int idZalogowanegoUzytkownika) {
    string linia="";

    fstream plik;
    plik.open(nazwaPliku.c_str(),ios::in);

    while(getline(plik,linia)) {
        wczytajJedenAdres(linia);
        if(a.get_idUzytkownika()==idZalogowanegoUzytkownika) {
            pobraneAdresy.push_back(a);
        }
    }
    plik.close();
    return pobraneAdresy;
}
int PlikAdresaci::podajIdOstatniegoAdresu(){
int idOstatniegoAdresu = 0;
    string linia="";

    fstream plik;
    plik.open(nazwaPliku.c_str(),ios::in);

    while(getline(plik,linia)) {
        wczytajJedenAdres(linia);
        idOstatniegoAdresu=a.get_idAdresata();
    }
    plik.close();
return idOstatniegoAdresu;
}
void PlikAdresaci::zapiszNowyAdres(Adresat nowyAdresat){
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out|ios::app);
    if (plik.good()==true) {
        plik<<nowyAdresat.get_idAdresata()<<'|';
        plik<<nowyAdresat.get_idUzytkownika()<<'|';
        plik<<nowyAdresat.get_imie()<<'|';
        plik<<nowyAdresat.get_nazwisko()<<'|';
        plik<<nowyAdresat.get_numerTelefonu()<<'|';
        plik<<nowyAdresat.get_email()<<'|';
        plik<<nowyAdresat.get_adresZamieszkania()<<'|'<<endl;

        plik.close();

        cout<<"Dane adresata zostaly ZAPISANE."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: "<<nazwaPliku<<endl;
        system("pause");
    }
}

void PlikAdresaci::zapisDoPlikuTymczasowegoStarszychWpisow(int idEdytowanegoAdresata) {
    fstream plikStaly, plikTymczasowy;
    plikStaly.open(nazwaPliku.c_str(),ios::in);
    plikTymczasowy.open(nazwaPlikuTymczasowego01.c_str(),ios::out|ios::app);
    string linia="";
    if(plikTymczasowy.good()==true) {
        while(getline(plikStaly,linia)) {
            wczytajJedenAdres(linia);
            if(a.get_idAdresata()>=idEdytowanegoAdresata) {
                break;
            }
            plikTymczasowy<<linia<<endl;
        }
    }
    plikStaly.close();
    plikTymczasowy.close();
}

void PlikAdresaci::zapisDoPlikuTymczasowegoNowszychWpisow(int idEdytowanegoAdresata) {
    fstream plikStaly, plikTymczasowy;
    plikStaly.open(nazwaPliku.c_str(),ios::in);
    plikTymczasowy.open(nazwaPlikuTymczasowego02.c_str(),ios::out|ios::app);
    string linia="";
    if(plikTymczasowy.good()==true) {
        while(getline(plikStaly,linia)) {
            wczytajJedenAdres(linia);
            if(a.get_idAdresata()>idEdytowanegoAdresata) {
                plikTymczasowy<<linia<<endl;
            }
        }
    }
    plikStaly.close();
    plikTymczasowy.close();
}
void PlikAdresaci::zapisDoPlikuStalegoStarszychWpisow() {
    fstream plikStaly, plikTymczasowy;
    string linia="";
    plikStaly.open(nazwaPliku.c_str(),ios::in|ios::out|ios::trunc);
    plikTymczasowy.open(nazwaPlikuTymczasowego01.c_str(),ios::in);
    if(plikStaly.good()==true) {
        while(getline(plikTymczasowy,linia)) {
            plikStaly<<linia<<endl;
        }
    }
    plikStaly.close();
    plikTymczasowy.close();
}
void PlikAdresaci::zapisDoPlikuStalegoNowszychWpisow() {
    fstream plikStaly, plikTymczasowy;
    string linia="";
    plikStaly.open(nazwaPliku.c_str(),ios::out|ios::app);
    plikTymczasowy.open(nazwaPlikuTymczasowego02.c_str(),ios::in);
    if(plikStaly.good()==true) {
        while(getline(plikTymczasowy,linia)) {
            plikStaly<<linia<<endl;
        }
    }
    plikStaly.close();
    plikTymczasowy.close();
}
void PlikAdresaci::odswiezZawartoscPlikuPoEdytowaniu(Adresat nowyAdres, int idEdytowanegoAdresu) {
    zapisDoPlikuTymczasowegoStarszychWpisow(idEdytowanegoAdresu);
    zapisDoPlikuTymczasowegoNowszychWpisow(idEdytowanegoAdresu);
    zapisDoPlikuStalegoStarszychWpisow();
    zapiszNowyAdres(nowyAdres);
    zapisDoPlikuStalegoNowszychWpisow();
}
void PlikAdresaci::usunPlikiTymczasowe(){
    remove(nazwaPlikuTymczasowego01.c_str());
    remove(nazwaPlikuTymczasowego02.c_str());
}
void PlikAdresaci::odswiezZawartoscPlikuPoUsunieciu (int idUsunietegoZnajomego) {
    zapisDoPlikuTymczasowegoStarszychWpisow(idUsunietegoZnajomego);
    zapisDoPlikuTymczasowegoNowszychWpisow(idUsunietegoZnajomego);
    zapisDoPlikuStalegoStarszychWpisow();
    zapisDoPlikuStalegoNowszychWpisow();
}
