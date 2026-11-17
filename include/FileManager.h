
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Record.h"

using namespace std;

class FileManager
{
private:
    string donationFile;

public:
    // Constructor
    FileManager(const string& filename = "data/donations.txt");

    // Save all donation records
    bool saveDonations(const vector<Record*>& records) const;

    // Load donation records from the file
    bool loadDonations(vector<Record*>& records) const;

    // Append one donation record
    bool appendDonation(const Record* record) const;
};
