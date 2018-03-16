#include <iostream>
#include "plik_uzytkownicy.h"
#include <fstream>
#include <sstream>

using namespace std;

PlikUzytkownicy::PlikUzytkownicy(string nazwa) {
    nazwaPliku=nazwa;
}
void PlikUzytkownicy::odswiezZawartoscPlikuUzytkownicy(vector<Uzytkownik> uzytkownicy){
    fstream plik;
    plik.open(nazwaPliku.c_str(),ios::in|ios::out|ios::trunc);
    if(plik.good()==true) {
        for(vector<Uzytkownik>::iterator itr=uzytkownicy.begin(); itr!=uzytkownicy.end(); itr++) {
            plik<<itr->get_id()<<'|';
            plik<<itr->get_nazwa()<<'|';
            plik<<itr->get_haslo()<<'|'<<endl;
        }
    }
    plik.close();
}
void PlikUzytkownicy::dopiszUzytkownika() {
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out|ios::app);
    if (plik.good()==true) {
        plik<<u.get_id()<<'|';
        plik<<u.get_nazwa()<<'|';
        plik<<u.get_haslo()<<'|'<<endl;

        plik.close();

        cout<<"Konto zostalo ZALOZONE."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: "<<nazwaPliku<<endl;
        system("pause");
    }
}
int PlikUzytkownicy::stringNaInt(string napisZmienianyNaInt) {
    int i;
    istringstream iss(napisZmienianyNaInt);
    iss >> i;
    return i;
}
void PlikUzytkownicy::podzialWpisuNaCzlony(string dzielonyNapis, vector<string>&podzielonyNapis) {
    char znakSeparujacy = '|';
    int dlugoscNapisy=dzielonyNapis.size();
    for(size_t p=0, q=0; p!=dzielonyNapis.npos; p=q) {
        if ((dlugoscNapisy-p)==1) {
            break;
        }
        podzielonyNapis.push_back(dzielonyNapis.substr(p+(p!=0), (q=dzielonyNapis.find(znakSeparujacy, p+1))-p-(p!=0)));
    }
}
void PlikUzytkownicy::wczytajDaneJednegoUzytkownika(string daneUzytkownika){
    vector<string>podzieloneDaneUzytkownika;
    podzialWpisuNaCzlony(daneUzytkownika,podzieloneDaneUzytkownika);
    int iloscDanychAdresata=podzieloneDaneUzytkownika.size();
    for (int numerPojedynczejDanejUzytkownika=0; numerPojedynczejDanejUzytkownika<iloscDanychAdresata; numerPojedynczejDanejUzytkownika++) {
        switch(numerPojedynczejDanejUzytkownika) {
        case 0:
            u.set_id(stringNaInt(podzieloneDaneUzytkownika[numerPojedynczejDanejUzytkownika]));
        case 1:
            u.set_nazwa(podzieloneDaneUzytkownika[numerPojedynczejDanejUzytkownika]);
            break;
        case 2:
            u.set_haslo(podzieloneDaneUzytkownika[numerPojedynczejDanejUzytkownika]);
            break;
        }
    }
}
vector<Uzytkownik> PlikUzytkownicy::pobierzUzytkownikow() {
    string linia = "";
    fstream plik;
    plik.open(nazwaPliku.c_str(),ios::in);


    while(getline(plik,linia)) {
        wczytajDaneJednegoUzytkownika(linia);
        uzytkownicyPobraniZPliku.push_back(u);
    }
    plik.close();
    return uzytkownicyPobraniZPliku;
}
void PlikUzytkownicy::wyczyscWektor(){
    uzytkownicyPobraniZPliku.clear();
}
