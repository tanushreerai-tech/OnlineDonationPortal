#include "MaterialDonation.h"

// Constructor
MaterialDonation::MaterialDonation(
    const std::string& donationID,
    const std::string& donorID,
    const std::string& donationDate,
    const std::string& cause,
    const std::string& itemName,
    int quantity,
    const std::string& unit,
    const std::string& category,
    const std::string& condition
)
    : Record(donationID, donorID, donationDate, cause),
      itemName(itemName),
      quantity(quantity),
      unit(unit),
      category(category),
      condition(condition)
{
}

// Getters
std::string MaterialDonation::getItemName() const
{
    return itemName;
}

int MaterialDonation::getQuantity() const
{
    return quantity;
}

std::string MaterialDonation::getUnit() const
{
    return unit;
}

std::string MaterialDonation::getCategory() const
{
    return category;
}

std::string MaterialDonation::getCondition() const
{
    return condition;
}

// Setters
void MaterialDonation::setItemName(const std::string& itemName)
{
    this->itemName = itemName;
}

void MaterialDonation::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void MaterialDonation::setUnit(const std::string& unit)
{
    this->unit = unit;
}

void MaterialDonation::setCategory(const std::string& category)
{
    this->category = category;
}

void MaterialDonation::setCondition(const std::string& condition)
{
    this->condition = condition;
}