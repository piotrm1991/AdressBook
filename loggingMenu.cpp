#include <iostream>
#include <windows.h>
#include <conio.h>
#include "loggingMenu.h"
#include "users.h"
#include "mainMenu.h"

using namespace std;

Users users;
MainMenu mainMenu;

Logging::Logging() {
    users.fileUsers.creatFileIfNeeded();
    users.loadUsers();

    char userIputChoice;
    while(true) {
        system("cls");
        cout<<"1. Rejestracja"<<endl;
        cout<<"2. Logowanie"<<endl;
        cout<<"9. Zakoncz program"<<endl;
        cin>>userIputChoice;

        switch(userIputChoice) {
        case '1': {
            registerNewUser();
        }
        break;
        case '2': {
            logIn();
        }
        break;
        case '9': {
            closeApplication();
        }
        break;
        }
    }
}
void Logging::logIn() {
    users.signIn();
    if (users.getUserIdLoggedIn()!=0) {
        mainMenu.setUserIdLoggedIn(users.getUserIdLoggedIn());
        mainMenu.setUserLoginLoggedIn(users.getUserLoginLoggedIn());

        while(mainMenu.getUserIdLoggedIn()!=0) {
            mainMenu.runMainMenu();
            if(mainMenu.getAnswerPasswordChange()==true){
                users.changePassword();
                mainMenu.setAnswerPasswordChangeFalse();
            }
        }

        users.logOut();
    }
}
void Logging::registerNewUser() {
    users.addNewUser();
}
void Logging::closeApplication() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby zakonczyc program."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();

    exit(0);
}
