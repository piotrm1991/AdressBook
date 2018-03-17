#include <iostream>
#include "file.h"
#include "user.h"
#include <vector>

using namespace std;

class FileUsers :public File{
    vector<User> usersDowloadedFromFile;
public:
    User user;

    FileUsers(string = "Users.txt");

    vector<User> downloadUsers();
    void appendUser();
    void clearVector();
    void refreshFileUsers(vector<User>);
private:
    int stringToInt(string stringBefore);
    void separateString(string stringBefore, vector<string>&stringAfterSeparation);
    void loadOneUser(string userData);
};
