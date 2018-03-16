#include <iostream>
#include "adresat.h"

using namespace std;

void Adresat::wypiszDaneAdresata(){
    cout<<"Id: "<<get_idAdresata()<<endl;
    cout<<"Imie: "<<get_imie()<<endl;
    cout<<"Nazwisko: "<<get_nazwisko()<<endl;
    cout<<"Numer telefonu: "<<get_numerTelefonu()<<endl;
    cout<<"Email: "<<get_email()<<endl;
    cout<<"Adres zamieszkania: "<<get_adresZamieszkania()<<endl;
}


//setter
void Adresat::set_idUzytkownika(int i){
    idUzytkownika = i;
}
void Adresat::set_idAdresata(int i){
    idAdresata = i;
}
void Adresat::set_imie(string n){
    imie = n;
}
void Adresat::set_nazwisko(string n){
    nazwisko = n;
}
void Adresat::set_numerTelefonu(string n){
    numerTelefonu = n;
}
void Adresat::set_email(string n){
    email = n;
}
void Adresat::set_adresZamieszkania(string n){
    adresZamieszkania = n;
}
//---

//getter
int Adresat::get_idUzytkownika(){
    return idUzytkownika;
}
int Adresat::get_idAdresata(){
    return idAdresata;
}
string Adresat::get_imie(){
    return imie;
}
string Adresat::get_nazwisko(){
    return nazwisko;
}
string Adresat::get_numerTelefonu(){
    return numerTelefonu;
}
string Adresat::get_email(){
    return email;
}
string Adresat::get_adresZamieszkania(){
    return adresZamieszkania;
}
//-----
