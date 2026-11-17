
#pragma once

#include "Record.h"
#include <string>

using namespace std;

class MonetaryDonation : public Record
{
private:
    double amount;
    string paymentMode;
    string transactionReference;

public:
    // Constructor
    MonetaryDonation(
        const string& donationID,
        const string& donorID,
        double amount,
        const string& paymentMode,
        const string& transactionReference,
        const string& donationDate,
        const string& cause
    );

    // Identify donation type
    string getDonationType() const override;

    // Getters
    double getAmount() const;
    string getPaymentMode() const;
    string getTransactionReference() const;
};
