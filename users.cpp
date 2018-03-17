#include <iostream>
#include "users.h"

using namespace std;

char Users::changeToSmallWhenNeeded (char letterBefore) {
    char letterAfter=letterBefore;
    if(not islower(letterBefore)) {
        letterAfter=tolower(letterBefore);
    }
    return letterAfter;
}
bool Users::checkIfExists(string login) {

    for(vector<User>::iterator itr=users.begin(); itr!=users.end(); itr++) {
        if(itr->getUserLogin()==login) {
            return false;
        }
    }

    return true;
}
void Users::changePassword(){
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>ZMIANA HASLA<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    cout<<endl<<"Jestes zalogowany jako: >> "<<getUserLoginLoggedIn()<<" <<"<<endl<<endl;
    string passwordNew;
    cout<<"Podaj nowe haslo: ";
    cin>>passwordNew;

    system("cls");
    cout<<"Stare haslo: >> "<<getUserPasswordLoggedIn()<<" <<"<<endl;
    cout<<"Nowe haslo: >> "<<passwordNew<<" <<"<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy na pewno chcesz zmienic swoje haslo?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char userInput;
    while(true) {
        char answerChoice;
        cin>>userInput;
        answerChoice=changeToSmallWhenNeeded(userInput);

        switch (answerChoice) {
        case 't': {
            for(vector<User>::iterator itr=users.begin(); itr!=users.end(); itr++) {
                if(itr->getUserId()==getUserIdLoggedIn()) {
                    itr->getUserPassword()=passwordNew;
                }
            }
            setUserPasswordLoggedIn(passwordNew);
            fileUsers.refreshFileUsers(users);
            cout<<endl<<"Haslo ZOSTALO zmienione."<<endl;
            Sleep(1000);
            return;
        }
        break;
        case 'n': {
            cout<<endl<<"Haslo NIE zostalo zmienione."<<endl<<endl;
            return;
        }
        break;
        }
    }
}
void Users::addNewUser(){
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>REJESTRACJA NOWEGO UZYTKOWNIKA<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    string loginNew;
    cout<<"Podaj nazwe uzytkownika: ";
    cin>>loginNew;

    while (true) {
        if (checkIfExists(loginNew)==false) {
            cout<<"Taki uzytykownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>loginNew;
        } else {
            break;
        }
    }

    string passwordNew;
    cout<<"Podaj haslo: ";
    cin>>passwordNew;

    system("cls");

    cout<<"Id uzytkownika: "<<fileUsers.user.getUserId()+1<<endl;
    cout<<"Nazwa uzytkownika: "<<loginNew<<endl;
    cout<<"Haslo uzytkownika: "<<passwordNew<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz utworzyc takiego UZYTKOWNIKA?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char userInput;
    while(true) {
        char answerChoice;
        cin>>userInput;
        answerChoice=changeToSmallWhenNeeded(userInput);

        switch (answerChoice) {
        case't': {
            fileUsers.user.assignUserId();
            fileUsers.user.setUserLogin(loginNew);
            fileUsers.user.setUserPassword(passwordNew);
            users.push_back(fileUsers.user);
            fileUsers.appendUser();
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
void Users::loadUsers(){
    users=fileUsers.downloadUsers();
    fileUsers.clearVector();
}
void Users::signIn(){
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<">>>LOGOWANIE<<<"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    cout<<"Podaj nazwe uzytkownika: ";
    string login;
    cin>>login;

    for(vector<User>::iterator itr=users.begin(); itr!=users.end(); itr++) {
        if (itr->getUserLogin()==login) {
            for (int proby=0; proby<3; proby++) {
                cout<<"Podaj haslo. Pozostalo prob "<<3-proby<<": ";
                string password;
                cin>>password;

                if (itr->getUserPassword()==password) {
                    cout<<"Zalogowales sie. Wczytuje ksiazke adresowa..."<<endl;
                    setUserIdLoggedIn(itr->getUserId());
                    setUserLoginLoggedIn(itr->getUserLogin());
                    setUserPasswordLoggedIn(itr->getUserPassword());
                    Sleep(1000);
                    return;
                }
            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
            Sleep(3000);
            return;
        }
    }

    cout<<"Nie ma uzytkownika z takim loginem."<<endl;
    Sleep(3000);
    return;
}
Users::Users(int userIdLoggedIn, string userLoginLoggedIn, string userPasswordLoggedIn){
    this->userIdLoggedIn=userIdLoggedIn;
    this->userLoginLoggedIn=userLoginLoggedIn;
    this->userPasswordLoggedIn=userPasswordLoggedIn;
}
void Users::logOut(int userIdLoggedIn, string userLoginLoggedIn, string userPasswordLoggedIn){
    this->userIdLoggedIn = userIdLoggedIn;
    this->userLoginLoggedIn = userLoginLoggedIn;
    this->userPasswordLoggedIn = userPasswordLoggedIn;
}

void Users::setUserIdLoggedIn(int userIdLoggedIn){
    this->userIdLoggedIn=userIdLoggedIn;
}
void Users::setUserLoginLoggedIn(string userLoginLoggedIn){
    this->userLoginLoggedIn=userLoginLoggedIn;
}
void Users::setUserPasswordLoggedIn(string userPasswordLoggedIn){
    this->userPasswordLoggedIn=userPasswordLoggedIn;
}

int Users::getUserIdLoggedIn(){
    return userIdLoggedIn;
}
string Users::getUserLoginLoggedIn(){
    return userLoginLoggedIn;
}
string Users::getUserPasswordLoggedIn(){
    return userPasswordLoggedIn;
}

