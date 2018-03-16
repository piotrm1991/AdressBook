#include <iostream>
#include "uzytkownik.h"

using namespace std;

//setter
void Uzytkownik::set_id(int i){
    idUzytkownika = i;
}
void Uzytkownik::set_nazwa(string n){
    nazwaUzytkownika = n;
}
void Uzytkownik::set_haslo(string h){
    hasloUzytkownika = h;
}
//-------
//getter
const int Uzytkownik::get_id(){
    return idUzytkownika;
}
const string Uzytkownik::get_nazwa(){
    return nazwaUzytkownika;
}
const string Uzytkownik::get_haslo(){
    return hasloUzytkownika;
}
//-------

void Uzytkownik::przydzielNrId() {
    idUzytkownika++;
}
Uzytkownik::Uzytkownik(int id, string nazwa, string haslo) {
    idUzytkownika=id;
    nazwaUzytkownika=nazwa;
    hasloUzytkownika=haslo;
}
