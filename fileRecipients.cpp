#include <iostream>
#include "fileRecipients.h"
#include <vector>
#include <sstream>

using namespace std;

FileRecipients::FileRecipients(string nameFile, string nameFileTemporary01, string nameFileTemporary02) {
    this->nameFile = nameFile;
    this->nameFileTemporary01 = nameFileTemporary01;
    this->nameFileTemporary02 = nameFileTemporary02;
}
void FileRecipients::clearVector(){
    downloadedRecipients.clear();
}
int FileRecipients::stringToInt(string stringBefore) {
    int intAfter;
    istringstream iss(stringBefore);
    iss >> intAfter;
    return intAfter;
}
void FileRecipients::separateString(string stringBefore, vector<string>&stringAfterSeparation) {
    char separationMarker = '|';
    int stringLength=stringBefore.size();

    for(size_t p=0, q=0; p!=stringBefore.npos; p=q) {
        if ((stringLength-p)==1) {
            break;
        }
        stringAfterSeparation.push_back(stringBefore.substr(p+(p!=0), (q=stringBefore.find(separationMarker, p+1))-p-(p!=0)));
    }
}
void FileRecipients::loadOneUser(string recipientData) {
    vector<string>recipientDataAfterSeparation;
    separateString(recipientData,recipientDataAfterSeparation);
    int numberOfSeparatedStrings=recipientDataAfterSeparation.size();

    for (int i=0; i<numberOfSeparatedStrings; i++) {
        switch(i) {
        case 0:
            recipient.setRecipientId(stringToInt(recipientDataAfterSeparation[i]));
            break;
        case 1:
            recipient.setUserId(stringToInt(recipientDataAfterSeparation[i]));
            break;
        case 2:
            recipient.setName(recipientDataAfterSeparation[i]);
            break;
        case 3:
            recipient.setSurname(recipientDataAfterSeparation[i]);
            break;
        case 4:
            recipient.setPhoneNumber(recipientDataAfterSeparation[i]);
            break;
        case 5:
            recipient.setEmail(recipientDataAfterSeparation[i]);
            break;
        case 6:
            recipient.setAddress(recipientDataAfterSeparation[i]);
            break;
        }
    }
}
vector<Recipient> FileRecipients::downloadRecipients(int userIdLoggedIn) {
    string line="";

    fstream file;
    file.open(nameFile.c_str(),ios::in);

    while(getline(file,line)) {
        loadOneUser(line);
        if(recipient.getUserId()==userIdLoggedIn) {
            downloadedRecipients.push_back(recipient);
        }
    }
    file.close();
    return downloadedRecipients;
}
int FileRecipients::getIdLastRecipient(){
int idLastRecipient = 0;
    string line="";

    fstream file;
    file.open(nameFile.c_str(),ios::in);

    while(getline(file,line)) {
        loadOneUser(line);
        idLastRecipient=recipient.getRecipientId();
    }
    file.close();
return idLastRecipient;
}
void FileRecipients::saveNewRecipient(Recipient newRecipient){
    fstream file;
    file.open(nameFile.c_str(), ios::out|ios::app);

    if (file.good()==true) {
        file<<newRecipient.getRecipientId()<<'|';
        file<<newRecipient.getUserId()<<'|';
        file<<newRecipient.getName()<<'|';
        file<<newRecipient.getSurname()<<'|';
        file<<newRecipient.getPhoneNumber()<<'|';
        file<<newRecipient.getEmail()<<'|';
        file<<newRecipient.getAddress()<<'|'<<endl;

        file.close();

        cout<<"Dane adresata zostaly ZAPISANE."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: "<<nameFile<<endl;
        system("pause");
    }
}

void FileRecipients::saveToTemporaryOlderRecipients(int idEditedRecipent) {
    fstream mainFile, temporaryFile;
    mainFile.open(nameFile.c_str(),ios::in);
    temporaryFile.open(nameFileTemporary01.c_str(),ios::out|ios::app);

    string line="";
    if(temporaryFile.good()==true) {
        while(getline(mainFile,line)) {
            loadOneUser(line);
            if(recipient.getRecipientId()>=idEditedRecipent) {
                break;
            }
            temporaryFile<<line<<endl;
        }
    }
    mainFile.close();
    temporaryFile.close();
}

void FileRecipients::saveToTemporaryNewerRecipients(int idEditedRecipent) {
    fstream mainFile, temporaryFile;
    mainFile.open(nameFile.c_str(),ios::in);
    temporaryFile.open(nameFileTemporary02.c_str(),ios::out|ios::app);

    string line="";
    if(temporaryFile.good()==true) {
        while(getline(mainFile,line)) {
            loadOneUser(line);
            if(recipient.getRecipientId()>idEditedRecipent) {
                temporaryFile<<line<<endl;
            }
        }
    }
    mainFile.close();
    temporaryFile.close();
}
void FileRecipients::saveToMainFileOlderRecipients() {
    fstream mainFile, temporaryFile;
    string line="";
    mainFile.open(nameFile.c_str(),ios::in|ios::out|ios::trunc);
    temporaryFile.open(nameFileTemporary01.c_str(),ios::in);

    if(mainFile.good()==true) {
        while(getline(temporaryFile,line)) {
            mainFile<<line<<endl;
        }
    }
    mainFile.close();
    temporaryFile.close();
}
void FileRecipients::saveToMainFileNewerRecipients() {
    fstream mainFile, temporaryFile;
    string line="";
    mainFile.open(nameFile.c_str(),ios::out|ios::app);
    temporaryFile.open(nameFileTemporary02.c_str(),ios::in);

    if(mainFile.good()==true) {
        while(getline(temporaryFile,line)) {
            mainFile<<line<<endl;
        }
    }
    mainFile.close();
    temporaryFile.close();
}
void FileRecipients::refreshFileAfterEdit(Recipient newRecipient, int idEditedRecipent) {
    saveToTemporaryOlderRecipients(idEditedRecipent);
    saveToTemporaryNewerRecipients(idEditedRecipent);
    saveToMainFileOlderRecipients();
    saveNewRecipient(newRecipient);
    saveToMainFileNewerRecipients();
}
void FileRecipients::deleteTemporaryFiles(){
    remove(nameFileTemporary01.c_str());
    remove(nameFileTemporary02.c_str());
}
void FileRecipients::refreshFileAfterDelete (int idDeletedRecipent) {
    saveToTemporaryOlderRecipients(idDeletedRecipent);
    saveToTemporaryNewerRecipients(idDeletedRecipent);
    saveToMainFileOlderRecipients();
    saveToMainFileNewerRecipients();
}
