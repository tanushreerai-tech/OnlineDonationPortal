#include "User.h"
#include <iostream>

using namespace std;

User::User(string name, string email, string contactNumber, string userID)
    : Person(name, email, contactNumber), userID(userID) 
    {
        this->userID = userID;
    }

    string User::getUserID() const 
    {
        return userID;
    }

    void User::displayProfile() const 
    {
       Person::displayProfile(); // Call the base class displayProfile function to display common profile information
        cout << "User ID: " << userID << endl;
    }