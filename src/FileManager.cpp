#include "FileManager.h"
#include "MonetaryDonation.h"
#include "MaterialDonation.h"
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;


FileManager::FileManager(const string& filename)
    : donationFile(filename)
{
}


bool FileManager::saveDonations(const vector<Record*>& records) const
{
    ofstream file(donationFile);

    if (!file.is_open())
    {
        cout << "Error: Unable to open donation file." << endl;
        return false;
    }

    // Donation records will be written here.

for (const Record* record : records)
{
    if (record == nullptr)
    {
        return false;
    }

    // Check whether the record is a MonetaryDonation
    const MonetaryDonation* monetary =
        dynamic_cast<const MonetaryDonation*>(record);

    if (monetary != nullptr)
    {
        file << "MONETARY "
             << quoted(monetary->getDonationID()) << " "
             << quoted(monetary->getDonorID()) << " "
             << quoted(monetary->getDonationDate()) << " "
             << quoted(monetary->getCause()) << " "
             << quoted(monetary->getVerificationStatus()) << " "
             << setprecision(17) << monetary->getAmount() << " "
             << quoted(monetary->getPaymentMode()) << " "
             << quoted(monetary->getTransactionReference())
             << endl;
    }

    // Check whether the record is a MaterialDonation
    else
    {
        const MaterialDonation* material =
            dynamic_cast<const MaterialDonation*>(record);

        if (material == nullptr)
        {
            return false;
        }

        file << "MATERIAL "
             << quoted(material->getDonationID()) << " "
             << quoted(material->getDonorID()) << " "
             << quoted(material->getDonationDate()) << " "
             << quoted(material->getCause()) << " "
             << quoted(material->getVerificationStatus()) << " "
             << quoted(material->getItemName()) << " "
             << setprecision(17) << material->getQuantity() << " "
             << quoted(material->getUnit()) << " "
             << quoted(material->getCategory()) << " "
             << quoted(material->getCondition())
             << endl;
    }

    if (!file)
    {
        return false;
    }
}


    file.close();
    return true;
}

bool FileManager::loadDonations(vector<Record*>& records) const
{
    ifstream file(donationFile);

    if (!file.is_open())
    {
        cout << "Error: Unable to open donation file." << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        istringstream recordStream(line);

        string type;

        if (!(recordStream >> type))
        {
            continue;
        }

        // We will read the donation details here.
        if (type == "MONETARY")
{
    string donationID;
    string donorID;
    string donationDate;
    string cause;
    string status;
    double amount;
    string paymentMode;
    string transactionReference;

    if (!(recordStream >> quoted(donationID)
                      >> quoted(donorID)
                      >> quoted(donationDate)
                      >> quoted(cause)
                      >> quoted(status)
                      >> amount
                      >> quoted(paymentMode)
                      >> quoted(transactionReference)))
    {
        cout << "Error: Invalid monetary donation record." << endl;
        return false;
    }

    MonetaryDonation* donation = new MonetaryDonation(
        donationID,
        donorID,
        amount,
        paymentMode,
        transactionReference,
        donationDate,
        cause
    );

    donation->setVerificationStatus(status);

    records.push_back(donation);
}
else if (type == "MATERIAL")
{
    string donationID;
    string donorID;
    string donationDate;
    string cause;
    string status;
    string itemName;
    double quantity;
    string unit;
    string category;
    string condition;

    if (!(recordStream >> quoted(donationID)
                      >> quoted(donorID)
                      >> quoted(donationDate)
                      >> quoted(cause)
                      >> quoted(status)
                      >> quoted(itemName)
                      >> quantity
                      >> quoted(unit)
                      >> quoted(category)
                      >> quoted(condition)))
    {
        cout << "Error: Invalid material donation record." << endl;
        return false;
    }

    MaterialDonation* donation = new MaterialDonation(
        donationID,
        donorID,
        itemName,
        quantity,
        unit,
        category,
        condition,
        donationDate,
        cause
    );

    donation->setVerificationStatus(status);

    records.push_back(donation);
}

else
{
    cout << "Error: Unknown donation type found in file." << endl;
    return false;
}
    }

    file.close();

    return true;
}

bool FileManager::appendDonation(const Record* record) const
{
    if (record == nullptr)
    {
        cout << "Error: Invalid donation record." << endl;
        return false;
    }

    ofstream file(donationFile, ios::app);

    if (!file.is_open())
    {
        cout << "Error: Unable to open donation file." << endl;
        return false;
    }

    const MonetaryDonation* monetary =
        dynamic_cast<const MonetaryDonation*>(record);

    if (monetary != nullptr)
    {
        file << "MONETARY "
             << quoted(monetary->getDonationID()) << " "
             << quoted(monetary->getDonorID()) << " "
             << quoted(monetary->getDonationDate()) << " "
             << quoted(monetary->getCause()) << " "
             << quoted(monetary->getVerificationStatus()) << " "
             << setprecision(17) << monetary->getAmount() << " "
             << quoted(monetary->getPaymentMode()) << " "
             << quoted(monetary->getTransactionReference())
             << endl;
    }
    else
    {
        const MaterialDonation* material =
            dynamic_cast<const MaterialDonation*>(record);

        if (material == nullptr)
        {
            return false;
        }

        file << "MATERIAL "
             << quoted(material->getDonationID()) << " "
             << quoted(material->getDonorID()) << " "
             << quoted(material->getDonationDate()) << " "
             << quoted(material->getCause()) << " "
             << quoted(material->getVerificationStatus()) << " "
             << quoted(material->getItemName()) << " "
             << setprecision(17) << material->getQuantity() << " "
             << quoted(material->getUnit()) << " "
             << quoted(material->getCategory()) << " "
             << quoted(material->getCondition())
             << endl;
    }

    file.close();

    return static_cast<bool>(file);
}