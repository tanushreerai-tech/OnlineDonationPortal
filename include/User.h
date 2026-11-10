#include "Person.h"
#include <string>
using namespace std;

class User : public Person
{
    private:
    string userID;

    public: 
    // Constructor
    User(string name, string email, string contactNumber, string userID);


    // Getter
    string getUserID() const;

    // Display profile
    void displayProfile() const override;
};                