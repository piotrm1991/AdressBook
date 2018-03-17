#include <iostream>

using namespace std;

class User{
    int userId;
    string userLogin;
    string userPassword;
public:
    User(int=0, string=" ", string=" ");

    void setUserId(int userId);
    void setUserLogin(string userLogin);
    void setUserPassword(string userPassword);

    int getUserId();
    string getUserLogin();
    string getUserPassword();

    void assignUserId();
};
