#include "MonetaryDonation.h"

// Constructor
MonetaryDonation::MonetaryDonation(
    const std::string& donationID,
    const std::string& donorID,
    const std::string& donationDate,
    const std::string& cause,
    double amount,
    const std::string& paymentMode,
    const std::string& transactionReference
)
    : Record(donationID, donorID, donationDate, cause),
      amount(amount),
      paymentMode(paymentMode),
      transactionReference(transactionReference)
{
}

// Getters
double MonetaryDonation::getAmount() const
{
    return amount;
}

std::string MonetaryDonation::getPaymentMode() const
{
    return paymentMode;
}

std::string MonetaryDonation::getTransactionReference() const
{
    return transactionReference;
}

// Setters
void MonetaryDonation::setAmount(double amount)
{
    this->amount = amount;
}

void MonetaryDonation::setPaymentMode(const std::string& paymentMode)
{
    this->paymentMode = paymentMode;
}

void MonetaryDonation::setTransactionReference(const std::string& transactionReference)
{
    this->transactionReference = transactionReference;
}