#include "Manager.h"
#include <iostream>

using namespace std;

Manager::Manager(string name, string email, string contactNumber, string managerID)
    : Person(name, email, contactNumber) // reusing the parent class's constructor to initialize the inherited attributes 
    // rather than duplicating the initialization code in the derived class constructor. This promotes code reuse and ensures that the base class's constructor is called to properly initialize the inherited attributes.
    {
        this->managerID = managerID;
    }

    string Manager::getManagerID() const 
    {
        return managerID;
    }

    void Manager::displayProfile() const 
    {
       Person::displayProfile(); // Call the base class displayProfile function to display common profile information
        cout << "Manager ID: " << managerID << endl;
    }