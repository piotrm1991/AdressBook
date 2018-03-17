#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class File{
protected:
    string nameFile;
public:
    void creatFileIfNeeded();
};
