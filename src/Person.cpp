#include "Person.h"
#include <iostream>
using namespace std;    

// Constructor implementation
Person::Person(string name, string email, string contactNumber)
{
    this->name =name; // Assigns the parameter recieved by the constructor to the private member variable name of the current object. The this pointer is used to refer to the current object instance.
    this->email = email; // Assigns the parameter recieved by the constructor to the private member variable email of the current object. 
    this->contactNumber = contactNumber; // Assigns the parameter recieved by the constructor to the private member variable contactNumber of the current object.
}

// Getters implementation 
// getters only retrieve the value, it provides read-only access to the private member variables of the class. They do not modify the state of the object and are typically declared as const member functions to indicate that they do not change the object's state.
string Person::getName() const
{
    return name; // Returns the value of the private member variable name of the current object.
}   

string Person::getEmail() const
{
    return email; // Returns the value of the private member variable email of the current object.
}

string Person::getContactNumber() const
{
    return contactNumber; // Returns the value of the private member variable contactNumber of the current object.
}   

// Setters implementation
// setters are used to modify the private member variables of the class, it provides contolled access to the private member variables of the class. They allow you to set or update the values of the private member variables while encapsulating the implementation details and enforcing any necessary validation or constraints.
 void Person::setName(string name)
{                   
    this->name = name; // Assigns the parameter recieved by the setter function to the private member variable name of the current object. The this pointer is used to refer to the current object instance.
}                                   

void Person::setEmail(string email)
{
    this->email = email; // Assigns the parameter recieved by the setter function to the private member variable email of the current object. The this pointer is used to refer to the current object instance.
}

void Person::setContactNumber(string contactNumber)
{
    this->contactNumber = contactNumber; // Assigns the parameter recieved by the setter function to the private member variable contactNumber of the current object. The this pointer is used to refer to the current object instance.
}

// Display profile implementation
void Person::displayProfile() const // const keyword is used to make sure that this function does not modify the state of the object. It indicates that the function can be called on const instances of the class and guarantees that it will not change any member variables of the object.
{
    cout << "Name: " << name << endl; // Displays the value of the private member variable name of the current object.
    cout << "Email: " << email << endl; // Displays the value of the private member variable email of the current object.
    cout << "Contact Number: " << contactNumber << endl; // Displays the value of the private member variable contactNumber of the current object.
}

