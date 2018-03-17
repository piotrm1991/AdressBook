#include <iostream>
#include "mainMenu.h"
#include <windows.h>
#include "recipients.h"

using namespace std;

Recipients recipients;

void MainMenu::runMainMenu(){
recipients.fileRecipients.creatFileIfNeeded();
recipients.loadRecepients(getUserIdLoggedIn());

    char userInputChoice;
    while(true) {
        system("cls");
        cout<<"Jestes zalogowany jako: >>> "<<getUserLoginLoggedIn()<<" <<<"<<endl;
        cout<<"W ksiazce adresowej sa >>> "<<recipients.getNumberRecipients()<<" <<< adresy"<<endl<<endl;
        cout<<"1. Wprowadz nowy adres."<<endl;
        cout<<"2. Znajdz adresata o danym imieniu."<<endl;
        cout<<"3. Znajdz adresata o danym nazwisku."<<endl;
        cout<<"4. Wyswietl wszystkie adresy."<<endl;
        cout<<"5. Edytuj dane adresata."<<endl;
        cout<<"6. Usun dane adresata."<<endl;
        cout<<"7. Zmien haslo."<<endl;
        cout<<"9. Wyloguj sie."<<endl;
        cout<<endl<<"Wybierz 1-9: ";
        cin>>userInputChoice;

        switch (userInputChoice) {
        case'1': {
            addNewRecipient();
        }
        break;
        case'2': {
            findRecipientName();
        }
        break;
        case'3': {
            findRecipientSurname();
        }
        break;
        case'4': {
            displayAllRecipients();
        }
        break;
        case'5': {
            editAddress();
        }
        break;
        case'6': {
            deleteAddress();
        }
        break;
        case'7': {
            changePassword();
            return;
        }
        break;
        case'9': {
            logOut();
            return;
        }
        break;
        }
    }

}
MainMenu::MainMenu(int userIdLoggedIn, string userLoginLoggedIn, bool answerPasswordChange){
    this->userIdLoggedIn = userIdLoggedIn;
    this->userLoginLoggedIn = userLoginLoggedIn;
    this->answerPasswordChange = answerPasswordChange;
}

void MainMenu::changePassword(){
    setAnswerPasswordChangeTrue();
}
void MainMenu::logOut(){
    setUserIdLoggedIn(0);
    setUserLoginLoggedIn("");
}
void MainMenu::addNewRecipient(){
    recipients.addNewRecipient(getUserIdLoggedIn());
}
void MainMenu::displayAllRecipients(){
    recipients.displayAllRecipients();
}
void MainMenu::findRecipientName(){
    recipients.findName();
}
void MainMenu::findRecipientSurname(){
    recipients.findSurname();
}
void MainMenu::editAddress(){
    recipients.editAddress();
}
void MainMenu::deleteAddress(){
    recipients.deleteAddress();
}

void MainMenu::setAnswerPasswordChangeTrue(bool answerPasswordChange){
    this->answerPasswordChange = answerPasswordChange;
}
void MainMenu::setAnswerPasswordChangeFalse(bool answerPasswordChange){
    this->answerPasswordChange = answerPasswordChange;
}
bool MainMenu::getAnswerPasswordChange(){
    return answerPasswordChange;
}

void MainMenu::setUserIdLoggedIn(int userIdLoggedIn){
    this->userIdLoggedIn = userIdLoggedIn;
}
void MainMenu::setUserLoginLoggedIn(string userLoginLoggedIn){
    this->userLoginLoggedIn = userLoginLoggedIn;
}

int MainMenu::getUserIdLoggedIn(){
    return userIdLoggedIn;
}
string MainMenu::getUserLoginLoggedIn(){
    return userLoginLoggedIn;
}
