#include <iostream>
#include "recipient.h"

using namespace std;

void Recipient::displayRecipient(){
    cout<<"Id: "<<getRecipientId()<<endl;
    cout<<"Imie: "<<getName()<<endl;
    cout<<"Nazwisko: "<<getSurname()<<endl;
    cout<<"Numer telefonu: "<<getPhoneNumber()<<endl;
    cout<<"Email: "<<getEmail()<<endl;
    cout<<"Adres zamieszkania: "<<getAddress()<<endl;
}

void Recipient::setUserId(int userId){
    this->userId=userId;
}
void Recipient::setRecipientId(int recipientId){
    this->recipientId=recipientId;
}
void Recipient::setName(string name){
    this->name=name;
}
void Recipient::setSurname(string surname){
    this->surname=surname;
}
void Recipient::setPhoneNumber(string phoneNumber){
    this->phoneNumber=phoneNumber;
}
void Recipient::setEmail(string email){
    this->email=email;
}
void Recipient::setAddress(string address){
    this->address=address;
}

int Recipient::getUserId(){
    return userId;
}
int Recipient::getRecipientId(){
    return recipientId;
}
string Recipient::getName(){
    return name;
}
string Recipient::getSurname(){
    return surname;
}
string Recipient::getPhoneNumber(){
    return phoneNumber;
}
string Recipient::getEmail(){
    return email;
}
string Recipient::getAddress(){
    return address;
}
