#include <iostream>
#include "fileUsers.h"
#include <fstream>
#include <sstream>

using namespace std;

FileUsers::FileUsers(string nameFile) {
    this->nameFile=nameFile;
}
void FileUsers::refreshFileUsers(vector<User> users){
    fstream file;
    file.open(nameFile.c_str(),ios::in|ios::out|ios::trunc);

    if(file.good()==true) {
        for(vector<User>::iterator itr=users.begin(); itr!=users.end(); itr++) {
            file<<itr->getUserId()<<'|';
            file<<itr->getUserLogin()<<'|';
            file<<itr->getUserPassword()<<'|'<<endl;
        }
    }
    file.close();
}
void FileUsers::appendUser() {
    fstream file;
    file.open(nameFile.c_str(), ios::out|ios::app);

    if (file.good()==true) {
        file<<user.getUserId()<<'|';
        file<<user.getUserLogin()<<'|';
        file<<user.getUserPassword()<<'|'<<endl;

        file.close();

        cout<<"Konto zostalo ZALOZONE."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: "<<nameFile<<endl;
        system("pause");
    }
}
int FileUsers::stringToInt(string stringBefore) {
    int intAfter;
    istringstream iss(stringBefore);
    iss >> intAfter;
    return intAfter;
}
void FileUsers::separateString(string stringBefore, vector<string>&stringAfterSeparation) {
    char separationMarker = '|';
    int stringLength=stringBefore.size();

    for(size_t p=0, q=0; p!=stringBefore.npos; p=q) {
        if ((stringLength-p)==1) {
            break;
        }
        stringAfterSeparation.push_back(stringBefore.substr(p+(p!=0), (q=stringBefore.find(separationMarker, p+1))-p-(p!=0)));
    }
}
void FileUsers::loadOneUser(string userData){
    vector<string>userDataAfterSeparation;
    separateString(userData,userDataAfterSeparation);

    int numberOfSeparatedStrings=userDataAfterSeparation.size();

    for (int i=0; i<numberOfSeparatedStrings; i++) {
        switch(i) {
        case 0:
            user.setUserId(stringToInt(userDataAfterSeparation[i]));
        case 1:
            user.setUserLogin(userDataAfterSeparation[i]);
            break;
        case 2:
            user.setUserPassword(userDataAfterSeparation[i]);
            break;
        }
    }
}
vector<User> FileUsers::downloadUsers() {
    string line = "";
    fstream file;
    file.open(nameFile.c_str(),ios::in);

    while(getline(file,line)) {
        loadOneUser(line);
        usersDowloadedFromFile.push_back(user);
    }

    file.close();
    return usersDowloadedFromFile;
}
void FileUsers::clearVector(){
    usersDowloadedFromFile.clear();
}
