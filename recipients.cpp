#include <iostream>
#include "recipients.h"
#include <conio.h>
#include <algorithm>

using namespace std;

void Recipients::loadRecepients(int userIdLoggedIn){
    recipients=fileRecipients.downloadRecipients(userIdLoggedIn);
    fileRecipients.clearVector();
}
void Recipients::displayAllRecipients(){
    system("cls");
    int numberOfRecipients = getNumberRecipients();

    if(!recipients.empty()) {
        for (int i=0; i<numberOfRecipients; i++) {
            recipients[i].displayRecipient();
            cout<<endl<<"------------------------------------------------"<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
int Recipients::getNumberRecipients(){
    int numberOfRecipients = recipients.size();
    return numberOfRecipients;
}
char Recipients::changeToSmallWhenNeeded (char letterBefore) {
    char letterAfter=letterBefore;
    if(not islower(letterBefore)) {
        letterAfter=tolower(letterBefore);
    }
    return letterAfter;
}
string Recipients::changeFirstLetterCapital(string word) {
    if(!word.empty()) {
        transform(word.begin(),word.end(), word.begin(),::tolower);
        word[0]=toupper(word[0]);
    }
    return word;
}
void Recipients::addNewRecipient(int userIdLoggedIn){
    system("cls");
    Recipient newRecipient;

    string name, surname, email, phoneNumber, address;
    cout<<"Dodawanie nowego adresata do ksiazki adresowej."<<endl;
    cout<<"Podaj imie: ";
    cin>>name;

    cout<<"Podaj nazwisko: ";
    cin>>surname;

    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin, phoneNumber);

    cout<<"Podaj email: ";
    cin>>email;

    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, address);

    newRecipient.setUserId(userIdLoggedIn);
    newRecipient.setRecipientId(fileRecipients.getIdLastRecipient()+1);
    newRecipient.setName(changeFirstLetterCapital(name));
    newRecipient.setSurname(changeFirstLetterCapital(surname));
    newRecipient.setPhoneNumber(phoneNumber);
    newRecipient.setEmail(email);
    newRecipient.setAddress(address);

    system("cls");
    newRecipient.displayRecipient();
    cout<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Czy chcesz zapisac ten adres w Ksiazce Adresowwj?(t/n)"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    char answerChoice;
    while(true) {
        char userInput;
        cin>>answerChoice;
        userInput=changeToSmallWhenNeeded(answerChoice);

        switch (userInput) {
        case't': {
            recipients.push_back(newRecipient);
            fileRecipients.saveNewRecipient(newRecipient);
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
void Recipients::findName(){
    system("cls");

    if (!recipients.empty()) {
        int numberRecipientsFound=0;
        string nameRecipientSearchedFor;
        cout<<"Podaj imie szukanego adresata: ";
        cin>>nameRecipientSearchedFor;

        nameRecipientSearchedFor=changeFirstLetterCapital(nameRecipientSearchedFor);
        int numberRecipients=recipients.size();

        for(int i=0; i<numberRecipients; i++) {
            if(nameRecipientSearchedFor==recipients[i].getName()) {
                recipients[i].displayRecipient();
                numberRecipientsFound++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (numberRecipientsFound==0) {
            cout<<endl<<"Nie ma adresatow o tym imieniu."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow z imieniem: '"<<nameRecipientSearchedFor;
            cout<<"' w ksiazce adresowej wynosi: "<<numberRecipientsFound<<endl<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
    }

    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void Recipients::findSurname(){
    system("cls");

    if (!recipients.empty()) {
        int numberRecipientsFound=0;
        string surnameRecipientSearchedFor;
        cout<<"Podaj nazwisko szukanego adresata: ";
        cin>>surnameRecipientSearchedFor;

        surnameRecipientSearchedFor=changeFirstLetterCapital(surnameRecipientSearchedFor);
        int iloscZnajomych=recipients.size();

        for(int i=0; i<iloscZnajomych; i++) {
            if(surnameRecipientSearchedFor==recipients[i].getSurname()) {
                recipients[i].displayRecipient();
                numberRecipientsFound++;
                cout<<endl<<"------------------------------------------------"<<endl;
            }
        }
        if (numberRecipientsFound==0) {
            cout<<endl<<"Nie ma adresatow o tym nazwisku."<<endl;
        } else {
            cout<<endl<<"Ilosc adresatow o nazwisku: '"<<surnameRecipientSearchedFor;
            cout<<"' w ksiazce adresowej wynosi: "<<numberRecipientsFound<<endl<<endl;
        }
    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
    }

    cout<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    getch();
}
void Recipients::editAddress(){
system("cls");

    if(!recipients.empty()) {
        bool doesAddressExist=false;

        cout<<"Podaj numer ID adresata u ktorego chcesz zmienic dane: ";
        int idRecipientSearchedFor=0;
        cin>>idRecipientSearchedFor;

        if (cin.fail()) {
            cout<<endl<<"Podano niepoprawne dane. Powrot do menu glownego."<<endl<<endl;
            cin.clear();
            cin.sync();
        } else {

            for (vector<Recipient>::iterator itr=recipients.begin(); itr !=recipients.end(); itr++) {
                if(itr->getRecipientId()==idRecipientSearchedFor) {
                    doesAddressExist=true;
                    Recipient recipientBeforeEdit;
                    Recipient recipientAfterEdit;


                    recipientBeforeEdit.setRecipientId(itr->getRecipientId());
                    recipientBeforeEdit.setUserId(itr->getUserId());
                    recipientBeforeEdit.setName(itr->getName());
                    recipientBeforeEdit.setSurname(itr->getSurname());
                    recipientBeforeEdit.setPhoneNumber(itr->getPhoneNumber());
                    recipientBeforeEdit.setEmail(itr->getEmail());
                    recipientBeforeEdit.setAddress(itr->getAddress());

                    recipientAfterEdit.setRecipientId(itr->getRecipientId());
                    recipientAfterEdit.setUserId(itr->getUserId());
                    recipientAfterEdit.setName(itr->getName());
                    recipientAfterEdit.setSurname(itr->getSurname());
                    recipientAfterEdit.setPhoneNumber(itr->getPhoneNumber());
                    recipientAfterEdit.setEmail(itr->getEmail());
                    recipientAfterEdit.setAddress(itr->getAddress());

                    while(true) {
                        system("cls");
                        cout<<"Dane adresata przed zmiana:"<<endl<<endl;
                        recipientBeforeEdit.displayRecipient();
                        cout<<endl<<"------------------------------------"<<endl<<endl;
                        cout<<"Dane adresata po zmianie:"<<endl<<endl;
                        recipientAfterEdit.displayRecipient();
                        cout<<endl<<"------------------------------------"<<endl<<endl;

                        cout<<"Co chcesz zmienic?"<<endl;
                        cout<<"1 - Imie."<<endl;
                        cout<<"2 - Nazwisko."<<endl;
                        cout<<"3 - Numer telefonu."<<endl;
                        cout<<"4 - Email."<<endl;
                        cout<<"5 - Adres zamieszkania."<<endl;
                        cout<<"6 - Zapisz zmiany."<<endl;
                        cout<<"7 - Nie chce nic zmieniac."<<endl;
                        cout<<endl<<"Wybierz 1-7:";

                        char userInputChoice;
                        cin>>userInputChoice;

                        switch (userInputChoice) {
                        case '1': {
                            string name;
                            cout<<"Podaj nowe imie: ";
                            cin>>name;
                            recipientAfterEdit.setName(changeFirstLetterCapital(name));
                        }
                        break;
                        case '2': {
                            string surname;
                            cout<<"Podaj nowe nazwisko: ";
                            cin>>surname;
                            recipientAfterEdit.setSurname(changeFirstLetterCapital(surname));
                        }
                        break;
                        case '3': {
                            cout<<"Podaj nowy numer telefonu: ";
                            string phoneNumber;
                            cin.sync();
                            getline(cin, phoneNumber);
                            recipientAfterEdit.setPhoneNumber(phoneNumber);
                        }
                        break;
                        case '4': {
                            cout<<"Podaj nowy email: ";
                            string email;
                            cin>>email;
                            recipientAfterEdit.setEmail(email);
                        }
                        break;
                        case '5': {
                            cout<<"Podaj nowy adres zamieszkania: ";
                            string address;
                            cin>>address;
                            recipientAfterEdit.setAddress(address);
                        }
                        break;
                        case '6': {
                            itr->setName(recipientAfterEdit.getName());
                            itr->setSurname(recipientAfterEdit.getSurname());
                            itr->setPhoneNumber(recipientAfterEdit.getPhoneNumber());
                            itr->setEmail(recipientAfterEdit.getEmail());
                            itr->setAddress(recipientAfterEdit.getAddress());
                            fileRecipients.refreshFileAfterEdit(recipientAfterEdit, recipientAfterEdit.getRecipientId());
                            fileRecipients.deleteTemporaryFiles();
                            return;
                        }
                        break;
                        case '7': {
                            return;
                        }
                        break;
                        }
                    }
                }
            }

            if (doesAddressExist==false) {

                cout<<endl<<"Nie ma takiego adresata w ksiazce adresowej."<<endl<<endl;

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                getch();
            }
        }

    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        getch();
    }
}
void Recipients::deleteAddress(){
    system("cls");

    if(!recipients.empty()) {
        bool doesAddressExist=false;

        int idRecipientDelete;
        cout<<"Podaj numer ID adresata, ktorego dane chcesz usunac: ";
        cin>>idRecipientDelete;

        if (cin.fail()) {
            cout<<endl<<"Wprowadzono niepoprawne dane. Powrot do menu glownego."<<endl;
            cin.clear();
            cin.sync();
        } else {
            int numberOfRecipients=recipients.size();

            for (int i=0; i<numberOfRecipients; i++) {
                if (recipients[i].getRecipientId()==idRecipientDelete) {
                    doesAddressExist=true;

                    recipients[i].displayRecipient();

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                    cout<<"Czy na pewno chcesz usunac dane tego adresata?(t/n)"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    char userInput;
                    while(true) {
                        char answerChoice;
                        cin>>userInput;
                        answerChoice=changeToSmallWhenNeeded(userInput);

                        switch (answerChoice) {
                        case 't': {
                            fileRecipients.refreshFileAfterDelete(recipients[i].getRecipientId());
                            recipients.erase(recipients.begin()+i);
                            fileRecipients.deleteTemporaryFiles();
                            cout<<endl<<"Dane adresata zostaly USUNIETE."<<endl;
                            Sleep(1000);
                            return;
                        }
                        break;
                        case 'n': {
                            cout<<endl<<"Wybrany adresat NIE zostal usuniety."<<endl<<endl;
                            return;
                        }
                        break;
                        }
                    }
                }
            }

            if(doesAddressExist==false) {
                cout<<endl<<"Nie ma takiego adresata w ksiazce adresowej."<<endl<<endl;
            }
        }

    } else {
        cout<<"Ksiazka adresowa jest pusta."<<endl<<endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout<<"Wcisnij ENTER aby wrocic do glownego interfejsu."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        getch();
    }
}
