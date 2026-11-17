#ifndef MATERIALDONATION_H
#define MATERIALDONATION_H

#include "Record.h"
#include <string>

class MaterialDonation : public Record
{
private:
    std::string itemName;
    int quantity;
    std::string unit;
    std::string category;
    std::string condition;

public:
    MaterialDonation(
        const std::string& donationID,
        const std::string& donorID,
        const std::string& donationDate,
        const std::string& cause,
        const std::string& itemName,
        int quantity,
        const std::string& unit,
        const std::string& category,
        const std::string& condition
    );

    std::string getItemName() const;
    int getQuantity() const;
    std::string getUnit() const;
    std::string getCategory() const;
    std::string getCondition() const;

    void setItemName(const std::string& itemName);
    void setQuantity(int quantity);
    void setUnit(const std::string& unit);
    void setCategory(const std::string& category);
    void setCondition(const std::string& condition);
};

#endif