#include <iostream>
#include <vector>
#include "fileUsers.h"

using namespace std;

class Users {
    int userIdLoggedIn;
    string userLoginLoggedIn;
    string userPasswordLoggedIn;
    vector<User> users;
public:
    FileUsers fileUsers;

    Users (int = 0, string = "", string = "");

    void addNewUser();
    void signIn();
    void loadUsers();
    void changePassword();
    void logOut(int = 0, string = "", string = "");

    void setUserIdLoggedIn(int userIdLoggedIn);
    void setUserLoginLoggedIn(string userLoginLoggedIn);
    void setUserPasswordLoggedIn(string userPasswordLoggedIn);

    int getUserIdLoggedIn();
    string getUserLoginLoggedIn();
    string getUserPasswordLoggedIn();

private:
    char changeToSmallWhenNeeded (char letterBefore);
    bool checkIfExists (string login);
};
