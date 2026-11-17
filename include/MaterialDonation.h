
#pragma once

#include "Record.h"
#include <string>

using namespace std;

class MaterialDonation : public Record
{
private:
    string itemName;
    double quantity;
    string unit;
    string category;
    string condition;

public:
    // Constructor
    MaterialDonation(
        const string& donationID,
        const string& donorID,
        const string& itemName,
        double quantity,
        const string& unit,
        const string& category,
        const string& condition,
        const string& donationDate,
        const string& cause
    );

    // Identify donation type
    string getDonationType() const override;

    // Getters
    string getItemName() const;
    double getQuantity() const;
    string getUnit() const;
    string getCategory() const;
    string getCondition() const;
};
