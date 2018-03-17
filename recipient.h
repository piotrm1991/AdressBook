#include <iostream>

using namespace std;

class Recipient{
    int userId;
    int recipientId;
    string name;
    string surname;
    string phoneNumber;
    string email;
    string address;
public:
    void displayRecipient();

    void setUserId(int userId);
    void setRecipientId(int recipientId);
    void setName(string name);
    void setSurname(string surname);
    void setPhoneNumber(string phoneNumber);
    void setEmail(string email);
    void setAddress(string address);

    int getUserId();
    int getRecipientId();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};
