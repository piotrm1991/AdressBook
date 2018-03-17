#include <iostream>
#include "user.h"

using namespace std;

void User::setUserId(int userId){
    this->userId=userId;
}
void User::setUserLogin(string userLogin){
    this->userLogin=userLogin;
}
void User::setUserPassword(string userPassword){
    this->userPassword=userPassword;
}

int User::getUserId(){
    return userId;
}
string User::getUserLogin(){
    return userLogin;
}
string User::getUserPassword(){
    return userPassword;
}

void User::assignUserId() {
    userId++;
}
User::User(int userId, string userLogin, string userPassword) {
    this->userId=userId;
    this->userLogin=userLogin;
    this->userPassword=userPassword;
}
