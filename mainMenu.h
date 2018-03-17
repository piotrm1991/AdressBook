#include <iostream>

using namespace std;

class MainMenu{
    int userIdLoggedIn;
    string userLoginLoggedIn;
    bool answerPasswordChange;
public:
    MainMenu(int = 0, string = "", bool = false);
    void runMainMenu();
    void addNewRecipient();
    void displayAllRecipients();
    void findRecipientName();
    void findRecipientSurname();
    void editAddress();
    void deleteAddress();
    void changePassword();
    void logOut();

    void setAnswerPasswordChangeFalse(bool = false);
    void setAnswerPasswordChangeTrue(bool = true);
    bool getAnswerPasswordChange();

    void setUserIdLoggedIn(int userIdLoggedIn);
    void setUserLoginLoggedIn(string userLoginLoggedIn);

    int getUserIdLoggedIn();
    string getUserLoginLoggedIn();
};
