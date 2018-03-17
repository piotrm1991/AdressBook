#include <iostream>
#include "file.h"
#include "recipient.h"
#include <vector>

using namespace std;
class FileRecipients :public File{
    vector<Recipient> downloadedRecipients;
    string nameFileTemporary01;
    string nameFileTemporary02;
public:
    Recipient recipient;

    FileRecipients(string = "Recipients.txt", string = "PlikTymczasowy_01.txt", string = "PlikTymczasowy_02.txt");

    vector<Recipient> downloadRecipients(int userIdLoggedIn);
    void saveNewRecipient(Recipient newRecipient);
    void refreshFileAfterEdit(Recipient newRecipient,  int idEditedRecipent);
    void refreshFileAfterDelete(int idDeletedRecipent);
    void deleteTemporaryFiles();
    void clearVector();

    int getIdLastRecipient();
private:
    void saveToTemporaryOlderRecipients(int idEditedRecipent);
    void saveToTemporaryNewerRecipients(int idEditedRecipent);
    void saveToMainFileOlderRecipients();
    void saveToMainFileNewerRecipients();
    int stringToInt(string stringBefore);
    void separateString(string stringBefore, vector<string>&stringAfterSeparation);
    void loadOneUser(string recipientData);
};
