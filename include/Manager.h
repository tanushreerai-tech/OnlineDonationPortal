#pragma once
#include "Person.h" // Include the Person class header file
// because the compiler needs to know the definition of the Person class before it can compile the User class, which inherits from Person.
#include <string>

using namespace std;

class Manager : public Person
{
    private:
        string managerID;

    public:
        // Constructor
        Manager(string name, string email, string contactNumber, string managerID);

        // Getter
        string getManagerID() const; // Getter function to retrieve the managerID

        // Display profile
        void displayProfile() const override; // Override the displayProfile function from the Person class to provide a specific implementation for the Manager class
        //displays the inherited attributes from the Person class along with the managerID attribute specific to the Manager class.  
};
