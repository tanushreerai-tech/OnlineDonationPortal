#include <iostream>
#include "Manager.h"
using namespace std;

int main()
{
    //  #pragma once WHAT IS ITS USE?
        // Creating a Person object
    // Person person1("Tanushree", "tanu@gmail.com", "9876543210");

    // Displaying the original profile
   // cout << "----- ORIGINAL PROFILE -----" << endl;
    //person1.displayProfile();

    // Updating the person's details
   // person1.setName("Tanushree Rai");
    //person1.setEmail("tanushree@gmail.com");

    // Displaying the updated profile
   // cout << "\n----- UPDATED PROFILE -----" << endl;
    //person1.displayProfile();
// Testing the getter functions
    //cout << "\n----- GETTER TEST -----" << endl;
//cout << person1.getName() << endl;
//cout << person1.getEmail() << endl;out << person1.getContactNumber() << endl;



//User user1("Yash", "yash@gmail.com", "9876543210", "USER001");

//cout << "\n----- USER PROFILE -----" << endl;
//user1.displayProfile();

//cout << "\n----- GETTER TEST -----" << endl;
//cout << user1.getUserID() << endl;
    Manager manager1("Tanushree", "tanushree@gmail.com", "9876543210", "MAN001");

    cout << "\n----- MANAGER PROFILE -----" << endl;
    manager1.displayProfile();

    cout << "\n----- GETTER TEST -----" << endl;
    cout <<"Manager ID: " << manager1.getManagerID() << endl;    
      return 0;
}