#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

#include "Person.h"
#include "User.h"
#include "Manager.h"
#include "Record.h"
#include "MonetaryDonation.h"
#include "MaterialDonation.h"
#include "FileManager.h"
#include "Report.h"

using namespace std;


// Generate a unique donation ID
string generateDonationID(const vector<Record*>& records)
{
    int number = records.size() + 1;

    string id;

    do
    {
        id = "D" + to_string(number);
        number++;

        bool exists = false;

        for (const Record* record : records)
        {
            if (record != nullptr && record->getDonationID() == id)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
            return id;

    } while (true);
}


// Register a new donor
void registerDonor(vector<User>& users)
{
    string name, email, contact;

    cout << "\n========== DONOR REGISTRATION ==========" << endl;

    cout << "Enter donor name: ";
    getline(cin >> ws, name);

    cout << "Enter email: ";
    getline(cin, email);

    cout << "Enter contact number: ";
    getline(cin, contact);

    string userID = "USER" + to_string(users.size() + 1);

    User newUser(name, email, contact, userID);

    users.push_back(newUser);

    cout << "\nDonor registered successfully!" << endl;
    cout << "Your Donor ID is: " << userID << endl;
}


// Accept a monetary donation
void addMonetaryDonation(
    const vector<User>& users,
    vector<Record*>& records,
    FileManager& fileManager
)
{
    if (users.empty())
    {
        cout << "\nPlease register a donor first." << endl;
        return;
    }

    string donorID, paymentMode, reference, date, cause;
    double amount;

    cout << "\n========== MONETARY DONATION ==========" << endl;

    cout << "Enter Donor ID: ";
    cin >> donorID;

    bool donorFound = false;

    for (const User& user : users)
    {
        if (user.getUserID() == donorID)
        {
            donorFound = true;
            break;
        }
    }

    if (!donorFound)
    {
        cout << "Donor ID not found. Please register first." << endl;
        return;
    }

    cout << "Enter donation amount: Rs. ";
    if (!(cin >> amount) || amount <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid donation amount." << endl;
        return;
    }

    cout << "Enter payment mode: ";
    getline(cin >> ws, paymentMode);

    cout << "Enter transaction reference: ";
    getline(cin, reference);

    cout << "Enter donation date (YYYY-MM-DD): ";
    getline(cin, date);

    cout << "Enter donation cause: ";
    getline(cin, cause);

    string donationID = generateDonationID(records);

    Record* donation = new MonetaryDonation(
        donationID,
        donorID,
        amount,
        paymentMode,
        reference,
        date,
        cause
    );

    if (fileManager.appendDonation(donation))
    {
        records.push_back(donation);

        cout << "\nMonetary donation recorded successfully!" << endl;
        cout << "Donation ID: " << donationID << endl;
        cout << "Verification Status: Pending" << endl;
    }
    else
    {
        delete donation;
        cout << "Unable to save donation record." << endl;
    }
}


// Accept a material donation
void addMaterialDonation(
    const vector<User>& users,
    vector<Record*>& records,
    FileManager& fileManager
)
{
    if (users.empty())
    {
        cout << "\nPlease register a donor first." << endl;
        return;
    }

    string donorID, itemName, unit, category;
    string condition, date, cause;
    double quantity;

    cout << "\n========== MATERIAL DONATION ==========" << endl;

    cout << "Enter Donor ID: ";
    cin >> donorID;

    bool donorFound = false;

    for (const User& user : users)
    {
        if (user.getUserID() == donorID)
        {
            donorFound = true;
            break;
        }
    }

    if (!donorFound)
    {
        cout << "Donor ID not found. Please register first." << endl;
        return;
    }

    cout << "Enter item name: ";
    getline(cin >> ws, itemName);

    cout << "Enter quantity: ";
    if (!(cin >> quantity) || quantity <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid quantity." << endl;
        return;
    }

    cout << "Enter unit (kg, pieces, boxes, etc.): ";
    getline(cin >> ws, unit);

    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter item condition: ";
    getline(cin, condition);

    cout << "Enter donation date (YYYY-MM-DD): ";
    getline(cin, date);

    cout << "Enter donation cause: ";
    getline(cin, cause);

    string donationID = generateDonationID(records);

    Record* donation = new MaterialDonation(
        donationID,
        donorID,
        itemName,
        quantity,
        unit,
        category,
        condition,
        date,
        cause
    );

    if (fileManager.appendDonation(donation))
    {
        records.push_back(donation);

        cout << "\nMaterial donation recorded successfully!" << endl;
        cout << "Donation ID: " << donationID << endl;
        cout << "Verification Status: Pending" << endl;
    }
    else
    {
        delete donation;
        cout << "Unable to save donation record." << endl;
    }
}


// Manager verifies or rejects a donation
void verifyDonation(
    vector<Record*>& records,
    FileManager& fileManager
)
{
    string donationID;
    char decision;

    cout << "\n========== DONATION VERIFICATION ==========" << endl;

    cout << "Enter Donation ID: ";
    cin >> donationID;

    Record* selectedRecord = nullptr;

    for (Record* record : records)
    {
        if (record != nullptr &&
            record->getDonationID() == donationID)
        {
            selectedRecord = record;
            break;
        }
    }

    if (selectedRecord == nullptr)
    {
        cout << "Donation record not found." << endl;
        return;
    }

    cout << "\nDonation ID : " << selectedRecord->getDonationID() << endl;
    cout << "Donor ID    : " << selectedRecord->getDonorID() << endl;
    cout << "Type        : " << selectedRecord->getDonationType() << endl;
    cout << "Cause       : " << selectedRecord->getCause() << endl;
    cout << "Current Status: "
         << selectedRecord->getVerificationStatus() << endl;

    cout << "\nV - Verify donation" << endl;
    cout << "R - Reject donation" << endl;
    cout << "Enter decision: ";
    cin >> decision;

    if (decision == 'V' || decision == 'v')
    {
        selectedRecord->setVerificationStatus("Verified");
    }
    else if (decision == 'R' || decision == 'r')
    {
        selectedRecord->setVerificationStatus("Rejected");
    }
    else
    {
        cout << "Invalid decision." << endl;
        return;
    }

    if (fileManager.saveDonations(records))
    {
        cout << "Donation status updated successfully!" << endl;
        cout << "New Status: "
             << selectedRecord->getVerificationStatus() << endl;
    }
    else
    {
        cout << "Unable to save updated verification status." << endl;
    }
}


int main()
{
    vector<User> users;
    vector<Record*> records;

    FileManager fileManager;
    Report report;

    Manager manager1(
        "Portal Manager",
        "manager@donationportal.com",
        "9876543210",
        "MAN001"
    );

    cout << "\n========================================" << endl;
    cout << "       ONLINE DONATION PORTAL" << endl;
    cout << "========================================" << endl;

    cout << "\nLoading donation records..." << endl;

    if (fileManager.loadDonations(records))
    {
        cout << records.size()
             << " donation record(s) loaded successfully." << endl;
    }
    else
    {
        cout << "No existing donation file found or unable to read it." << endl;
        cout << "The portal will start with an empty donation list." << endl;
    }

    int choice = -1;

    do
    {
        cout << "\n========================================" << endl;
        cout << "             MAIN MENU" << endl;
        cout << "========================================" << endl;

        cout << "1. Register Donor" << endl;
        cout << "2. Make Monetary Donation" << endl;
        cout << "3. Make Material Donation" << endl;
        cout << "4. View All Donations" << endl;
        cout << "5. Manager Verification" << endl;
        cout << "6. Reports and Analytics" << endl;
        cout << "7. View Manager Profile" << endl;
        cout << "0. Exit Portal" << endl;

        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                registerDonor(users);
                break;

            case 2:
                addMonetaryDonation(users, records, fileManager);
                break;

            case 3:
                addMaterialDonation(users, records, fileManager);
                break;

            case 4:
                report.showAllDonations(records);
                break;

            case 5:
                verifyDonation(records, fileManager);
                break;

            case 6:
                report.showMenu(records);
                break;

            case 7:
                manager1.displayProfile();
                break;

            case 0:
                cout << "\nSaving donation records..." << endl;

                if (fileManager.saveDonations(records))
                    cout << "Records saved successfully." << endl;
                else
                    cout << "Warning: Unable to save records." << endl;

                cout << "\nThank you for using Online Donation Portal!"
                     << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    // Release dynamically allocated donation objects
    for (Record* record : records)
    {
        delete record;
    }

    records.clear();

    return 0;
}

 