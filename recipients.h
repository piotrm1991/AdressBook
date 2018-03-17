#include <iostream>
#include <vector>
#include "fileRecipients.h"

using namespace std;

class Recipients{
    vector<Recipient> recipients;
    string changeFirstLetterCapital(string word);
    char changeToSmallWhenNeeded (char letterBefore);
public:
    FileRecipients fileRecipients;

    void loadRecepients(int userIdLoggedIn);
    void addNewRecipient(int userIdLoggedIn);
    void findName();
    void findSurname();
    void editAddress();
    void deleteAddress();
    void displayAllRecipients();

    int getNumberRecipients();
};
