#include <iostream>
#include "plik.h"

using namespace std;

void Plik::utworzPlikJesliTrzeba() {
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out|ios::app);
    if (plik.good()==true) {
        plik.close();
    }
    else {
            exit(0);
    }
}
