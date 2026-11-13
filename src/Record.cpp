
#include "Record.h"

using namespace std;

// ==========================================
// CONSTRUCTOR
// ==========================================

// Initialises a new donation record.
// Every new donation starts with Pending status.

Record::Record(const string& donationID,
               const string& donorID,
               const string& donationDate,
               const string& cause)
    : donationID(donationID),
      donorID(donorID),
      donationDate(donationDate),
      cause(cause),
      verificationStatus("Pending")
{
}


// ==========================================
// GETTERS
// ==========================================

// Returns the donation ID.
string Record::getDonationID() const
{
    return donationID;
}

// Returns the donor ID.
string Record::getDonorID() const
{
    return donorID;
}

// Returns the donation date.
string Record::getDonationDate() const
{
    return donationDate;
}

// Returns the cause of the donation.
string Record::getCause() const
{
    return cause;
}

// Returns the verification status.
string Record::getVerificationStatus() const
{
    return verificationStatus;
}


// ==========================================
// SETTERS
// ==========================================

// Updates the donation date.
void Record::setDonationDate(const string& donationDate)
{
    this->donationDate = donationDate;
}

// Updates the donation cause.
void Record::setCause(const string& cause)
{
    this->cause = cause;
}

// Updates the verification status.
void Record::setVerificationStatus(const string& status)
{
    verificationStatus = status;
}
