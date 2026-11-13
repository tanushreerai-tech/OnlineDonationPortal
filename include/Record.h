#pragma once

#include <iostream>
#include <string>

using namespace std;
class Record
{
private:
    string donationID;
    string donorID;
    string donationDate;
    string cause;
    string verificationStatus;

protected:
    // We can add carefully selected helper methods later.

public:
    // Constructors, getters and setters will go here.
    Record(const string& donationID, const string& donorID,
       const string& donationDate, const string& cause);

       // Getters
string getDonationID() const;
string getDonorID() const;
string getDonationDate() const;
string getCause() const;
string getVerificationStatus() const;

// Setters
void setDonationDate(const string& donationDate);
void setCause(const string& cause);
void setVerificationStatus(const string& status);

virtual ~Record() = default;

virtual string getDonationType() const = 0;
};