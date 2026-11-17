#ifndef MONETARYDONATION_H
#define MONETARYDONATION_H

#include "Record.h"
#include <string>

class MonetaryDonation : public Record
{
private:
    double amount;
    std::string paymentMode;
    std::string transactionReference;

public:
    MonetaryDonation(
        const std::string& donationID,
        const std::string& donorID,
        const std::string& donationDate,
        const std::string& cause,
        double amount,
        const std::string& paymentMode,
        const std::string& transactionReference
    );

    double getAmount() const;
    std::string getPaymentMode() const;
    std::string getTransactionReference() const;

    void setAmount(double amount);
    void setPaymentMode(const std::string& paymentMode);
    void setTransactionReference(const std::string& transactionReference);

};

#endif