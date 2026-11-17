#pragma once
#include <string>
using namespace std;
class Person 
{ 
    private:
    string name;
    string email;
    string contactNumber;
// Constructor
    public:
    Person(string name, string email, string contactNumber);
//  Getters
    string getName() const;
    string getEmail() const;
    string getContactNumber() const;

    // Setters
    void setName(string name);
    void setEmail(string email);
    void setContactNumber(string contactNumber);

    // Display profile
    // The displayProfile function is declared as a virtual function, allowing derived classes to override it and provide their own implementation for displaying the profile information. This promotes runtime polymorphism and enables the use of base class pointers to call the appropriate displayProfile function based on the actual object type at runtime.
    virtual void displayProfile() const;

    // Virtual destructor 
    // a good practice to create a virtual destructor in the base class to ensure proper cleanup of derived class objects when deleted through a base class pointer
    virtual ~Person() = default;
};
