#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
    // Creating a Person object
    Person person1("Tanushree", "tanu@gmail.com", "9876543210");

    // Displaying the original profile
    cout << "----- ORIGINAL PROFILE -----" << endl;
    person1.displayProfile();

    // Updating the person's details
    person1.setName("Tanushree Rai");
    person1.setEmail("tanushree@gmail.com");

    // Displaying the updated profile
    cout << "\n----- UPDATED PROFILE -----" << endl;
    person1.displayProfile();
// Testing the getter functions
    cout << "\n----- GETTER TEST -----" << endl;
cout << person1.getName() << endl;
cout << person1.getEmail() << endl;
cout << person1.getContactNumber() << endl;

    return 0;
}