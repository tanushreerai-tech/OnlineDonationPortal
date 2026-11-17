#include "MonetaryDonation.h"

using namespace std;

MonetaryDonation::MonetaryDonation(
    const string& donationID,
    const string& donorID,
    double amount,
    const string& paymentMode,
    const string& transactionReference,
    const string& donationDate,
    const string& cause
)
    // member initializer list to initialize the base class and member variables
      : Record(donationID, donorID, donationDate, cause),
      amount(amount),
      paymentMode(paymentMode),
      transactionReference(transactionReference)
{
}


string MonetaryDonation::getDonationType() const
{
    return "MONETARY";
}


double MonetaryDonation::getAmount() const
{
    return amount;
}

string MonetaryDonation::getPaymentMode() const
{
    return paymentMode;
}

string MonetaryDonation::getTransactionReference() const
{
    return transactionReference;
}
