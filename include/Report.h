
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declaration of Record class
class Record;

class Report
{
public:

    // Display a summary of all donations
    void showOverallSummary(const vector<Record*>& records) const;

    // Display all donation records
    void showAllDonations(const vector<Record*>& records) const;

    // Display donation history of a particular donor
    void showDonorHistory(const vector<Record*>& records, const string& donorID) const;

    // Display monetary donation report
    void showMonetaryReport(const vector<Record*>& records) const;

    // Display material donation report
    void showMaterialReport(const vector<Record*>& records) const;

    // Display top donors (default: 5)
    void showTopDonors(const vector<Record*>& records, int limit = 5) const;

    // Check records for inconsistencies
    void verifyReportData(const vector<Record*>& records) const;

    // Export donation records to CSV
    bool exportToCSV(const vector<Record*>& records, const string& filename) const;

    // Display the report menu
    void showMenu(const vector<Record*>& records);
};
