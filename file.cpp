#include <iostream>
#include "file.h"

using namespace std;

void File::creatFileIfNeeded() {
    fstream file;
    file.open(nameFile.c_str(), ios::out|ios::app);
    if (file.good()==true) {
        file.close();
    }
    else {
            exit(0);
    }
}
