
#include "MaterialDonation.h"

using namespace std;

// Constructor
MaterialDonation::MaterialDonation(
    const string& donationID,
    const string& donorID,
    const string& itemName,
    double quantity,
    const string& unit,
    const string& category,
    const string& condition,
    const string& donationDate,
    const string& cause
)
    : Record(donationID, donorID, donationDate, cause),
      itemName(itemName),
      quantity(quantity),
      unit(unit),
      category(category),
      condition(condition)
{
}

// Identify donation type
string MaterialDonation::getDonationType() const
{
    return "MATERIAL";
}

// Getters
string MaterialDonation::getItemName() const
{
    return itemName;
}

double MaterialDonation::getQuantity() const
{
    return quantity;
}

string MaterialDonation::getUnit() const
{
    return unit;
}

string MaterialDonation::getCategory() const
{
    return category;
}

string MaterialDonation::getCondition() const
{
    return condition;
}
