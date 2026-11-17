
#include "Report.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include "Record.h"
#include "MonetaryDonation.h"
#include "MaterialDonation.h"


using namespace std;

 
void Report::showOverallSummary(const vector<Record*>& records) const
{
    int totalDonations = 0;
    int monetaryCount = 0;
    int materialCount = 0;

    int verifiedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;

    double confirmedAmount = 0.0;

    for (const Record* record : records)
    {
        if (record == nullptr)
        {
            continue;
        }

        totalDonations++;

        string status = record->getVerificationStatus();

        if (status == "Verified")
        {
            verifiedCount++;
        }
        else if (status == "Pending")
        {
            pendingCount++;
        }
        else if (status == "Rejected")
        {
            rejectedCount++;
        }

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary != nullptr)
        {
            monetaryCount++;

            if (status == "Verified")
            {
                confirmedAmount += monetary->getAmount();
            }
        }
        else
        {
            const MaterialDonation* material =
                dynamic_cast<const MaterialDonation*>(record);

            if (material != nullptr)
            {
                materialCount++;
            }
        }
    }

    cout << "\n========================================" << endl;
    cout << "       OVERALL DONATION SUMMARY" << endl;
    cout << "========================================" << endl;

    cout << "Total Donations       : " << totalDonations << endl;
    cout << "Monetary Donations    : " << monetaryCount << endl;
    cout << "Material Donations    : " << materialCount << endl;

    cout << "\n----- VERIFICATION SUMMARY -----" << endl;

    cout << "Verified Donations    : " << verifiedCount << endl;
    cout << "Pending Donations     : " << pendingCount << endl;
    cout << "Rejected Donations    : " << rejectedCount << endl;

    cout << "\n----- FINANCIAL SUMMARY -----" << endl;

    cout << fixed << setprecision(2);
    cout << "Confirmed Monetary Amount : Rs. "
         << confirmedAmount << endl;

    cout << "========================================" << endl;
}


void Report::showAllDonations(const vector<Record*>& records) const
{
    cout << "\n========================================" << endl;
    cout << "          ALL DONATION RECORDS" << endl;
    cout << "========================================" << endl;

    if (records.empty())
    {
        cout << "No donation records available." << endl;
        return;
    }

    for (const Record* record : records)
    {
        if (record == nullptr)
        {
            continue;
        }

        cout << "\n----------------------------------------" << endl;
        cout << "Donation ID : " << record->getDonationID() << endl;
        cout << "Donor ID    : " << record->getDonorID() << endl;
        cout << "Date        : " << record->getDonationDate() << endl;
        cout << "Cause       : " << record->getCause() << endl;
        cout << "Type        : " << record->getDonationType() << endl;
        cout << "Status      : " << record->getVerificationStatus() << endl;

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary != nullptr)
        {
            cout << "Amount      : Rs. " << monetary->getAmount() << endl;
            cout << "Payment Mode: " << monetary->getPaymentMode() << endl;
            cout << "Reference   : " << monetary->getTransactionReference() << endl;
        }
        else
        {
            const MaterialDonation* material =
                dynamic_cast<const MaterialDonation*>(record);

            if (material != nullptr)
            {
                cout << "Item        : " << material->getItemName() << endl;
                cout << "Quantity    : " << material->getQuantity()
                     << " " << material->getUnit() << endl;
                cout << "Category    : " << material->getCategory() << endl;
                cout << "Condition   : " << material->getCondition() << endl;
            }
        }
    }

    cout << "\n========================================" << endl;
}

void Report::showDonorHistory(
    const vector<Record*>& records,
    const string& donorID
) const
{
    bool found = false;

    cout << "\n========================================" << endl;
    cout << "           DONOR DONATION HISTORY" << endl;
    cout << "========================================" << endl;

    for (const Record* record : records)
    {
        if (record == nullptr || record->getDonorID() != donorID)
            continue;

        found = true;

        cout << "\nDonation ID : " << record->getDonationID() << endl;
        cout << "Type        : " << record->getDonationType() << endl;
        cout << "Date        : " << record->getDonationDate() << endl;
        cout << "Cause       : " << record->getCause() << endl;
        cout << "Status      : " << record->getVerificationStatus() << endl;

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary != nullptr)
        {
            cout << "Amount      : Rs. " << monetary->getAmount() << endl;
            cout << "Payment Mode: " << monetary->getPaymentMode() << endl;
        }
        else
        {
            const MaterialDonation* material =
                dynamic_cast<const MaterialDonation*>(record);

            if (material != nullptr)
            {
                cout << "Item        : " << material->getItemName() << endl;
                cout << "Quantity    : " << material->getQuantity()
                     << " " << material->getUnit() << endl;
                cout << "Category    : " << material->getCategory() << endl;
            }
        }
    }

    if (!found)
        cout << "\nNo donation history found for Donor ID: "
             << donorID << endl;

    cout << "========================================" << endl;
}

void Report::showMonetaryReport(const vector<Record*>& records) const
{
    int totalCount = 0;
    int verifiedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;
    double confirmedAmount = 0.0;

    for (const Record* record : records)
    {
        if (record == nullptr)
            continue;

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary == nullptr)
            continue;

        totalCount++;

        string status = record->getVerificationStatus();

        if (status == "Verified")
        {
            verifiedCount++;
            confirmedAmount += monetary->getAmount();
        }
        else if (status == "Pending")
        {
            pendingCount++;
        }
        else if (status == "Rejected")
        {
            rejectedCount++;
        }
    }

    cout << "\n========================================" << endl;
    cout << "          MONETARY DONATION REPORT" << endl;
    cout << "========================================" << endl;
    cout << "Total Monetary Donations : " << totalCount << endl;
    cout << "Verified Donations       : " << verifiedCount << endl;
    cout << "Pending Donations        : " << pendingCount << endl;
    cout << "Rejected Donations       : " << rejectedCount << endl;
    cout << fixed << setprecision(2);
    cout << "Confirmed Amount         : Rs. "
         << confirmedAmount << endl;
    cout << "========================================" << endl;
}

void Report::showMaterialReport(const vector<Record*>& records) const
{
    map<pair<string, string>, double> materialTotals;

    int totalCount = 0;
    int verifiedCount = 0;
    int pendingCount = 0;
    int rejectedCount = 0;

    for (const Record* record : records)
    {
        if (record == nullptr)
            continue;

        const MaterialDonation* material =
            dynamic_cast<const MaterialDonation*>(record);

        if (material == nullptr)
            continue;

        totalCount++;

        string status = record->getVerificationStatus();

        if (status == "Verified")
            verifiedCount++;
        else if (status == "Pending")
            pendingCount++;
        else if (status == "Rejected")
            rejectedCount++;

        if (status != "Rejected")
        {
            pair<string, string> key = {
                material->getCategory(),
                material->getUnit()
            };

            materialTotals[key] += material->getQuantity();
        }
    }

    cout << "\n========================================" << endl;
    cout << "          MATERIAL DONATION REPORT" << endl;
    cout << "========================================" << endl;
    cout << "Total Material Donations : " << totalCount << endl;
    cout << "Verified Donations       : " << verifiedCount << endl;
    cout << "Pending Donations        : " << pendingCount << endl;
    cout << "Rejected Donations       : " << rejectedCount << endl;

    cout << "\n----- CATEGORY-WISE QUANTITY -----" << endl;

    if (materialTotals.empty())
    {
        cout << "No material donations available." << endl;
    }
    else
    {
        for (const auto& entry : materialTotals)
        {
            cout << "Category: " << entry.first.first
                 << " | Quantity: " << entry.second
                 << " " << entry.first.second << endl;
        }
    }

    cout << "========================================" << endl;
}

void Report::verifyReportData(const vector<Record*>& records) const
{
    int invalidRecords = 0;

    cout << "\n========================================" << endl;
    cout << "          DATA VALIDATION REPORT" << endl;
    cout << "========================================" << endl;

    for (const Record* record : records)
    {
        if (record == nullptr)
        {
            invalidRecords++;
            cout << "Invalid record: Null pointer found." << endl;
            continue;
        }

        bool invalid = false;

        if (record->getDonationID().empty())
        {
            cout << "Missing Donation ID." << endl;
            invalid = true;
        }

        if (record->getDonorID().empty())
        {
            cout << "Missing Donor ID." << endl;
            invalid = true;
        }

        if (record->getDonationDate().empty())
        {
            cout << "Missing Donation Date." << endl;
            invalid = true;
        }

        string status = record->getVerificationStatus();

        if (status != "Pending" &&
            status != "Verified" &&
            status != "Rejected")
        {
            cout << "Invalid verification status for Donation ID: "
                 << record->getDonationID() << endl;
            invalid = true;
        }

        if (invalid)
        {
            invalidRecords++;

            cout << "Record ID: " << record->getDonationID()
                 << " requires correction.\n" << endl;
        }
    }

    if (invalidRecords == 0)
        cout << "All donation records passed basic validation." << endl;
    else
        cout << "Records requiring correction: "
             << invalidRecords << endl;

    cout << "========================================" << endl;
}

void Report::showTopDonors(const vector<Record*>& records, int limit) const
{
    map<string, double> donorTotals;

    for (const Record* record : records)
    {
        if (record == nullptr ||
            record->getVerificationStatus() != "Verified")
            continue;

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary != nullptr)
            donorTotals[record->getDonorID()] += monetary->getAmount();
    }

    vector<pair<string, double>> ranking(
        donorTotals.begin(), donorTotals.end()
    );

    sort(ranking.begin(), ranking.end(),
         [](const pair<string, double>& a,
            const pair<string, double>& b)
         {
             return a.second > b.second;
         });

    cout << "\n========== TOP MONETARY DONORS ==========" << endl;

    if (ranking.empty())
    {
        cout << "No verified monetary donations available." << endl;
        return;
    }

    for (int i = 0; i < min(limit, (int)ranking.size()); i++)
    {
        cout << i + 1 << ". Donor ID: " << ranking[i].first
             << " | Verified Total: Rs. "
             << fixed << setprecision(2)
             << ranking[i].second << endl;
    }
}

bool Report::exportToCSV(
    const vector<Record*>& records,
    const string& filename
) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Unable to create CSV file." << endl;
        return false;
    }

    file << "Donation ID,Donor ID,Type,Date,Cause,Status,"
         << "Amount,Payment Mode,Transaction Reference,"
         << "Item Name,Quantity,Unit,Category,Condition\n";

    for (const Record* record : records)
    {
        if (record == nullptr)
            continue;

        file << quoted(record->getDonationID()) << ","
             << quoted(record->getDonorID()) << ","
             << quoted(record->getDonationType()) << ","
             << quoted(record->getDonationDate()) << ","
             << quoted(record->getCause()) << ","
             << quoted(record->getVerificationStatus()) << ",";

        const MonetaryDonation* monetary =
            dynamic_cast<const MonetaryDonation*>(record);

        if (monetary != nullptr)
        {
            file << monetary->getAmount() << ","
                 << quoted(monetary->getPaymentMode()) << ","
                 << quoted(monetary->getTransactionReference())
                 << ",,,,,\n";
        }
        else
        {
            const MaterialDonation* material =
                dynamic_cast<const MaterialDonation*>(record);

            if (material != nullptr)
            {
                file << ",,,"
                     << quoted(material->getItemName()) << ","
                     << material->getQuantity() << ","
                     << quoted(material->getUnit()) << ","
                     << quoted(material->getCategory()) << ","
                     << quoted(material->getCondition()) << "\n";
            }
        }
    }

    file.close();

    if (!file)
    {
        cout << "Error while exporting CSV." << endl;
        return false;
    }

    cout << "CSV report exported successfully: "
         << filename << endl;

    return true;
}

void Report::showMenu(const vector<Record*>& records)
{
    int choice = -1;

    do
    {
        cout << "\n========== REPORT MENU ==========" << endl;
        cout << "1. Overall Donation Summary" << endl;
        cout << "2. View All Donations" << endl;
        cout << "3. Donor Donation History" << endl;
        cout << "4. Monetary Donation Report" << endl;
        cout << "5. Material Donation Report" << endl;
        cout << "6. Top Monetary Donors" << endl;
        cout << "7. Validate Donation Records" << endl;
        cout << "8. Export Report to CSV" << endl;
        cout << "0. Return to Main Menu" << endl;

        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                showOverallSummary(records);
                break;

            case 2:
                showAllDonations(records);
                break;

            case 3:
            {
                string donorID;
                cout << "Enter Donor ID: ";
                cin >> donorID;
                showDonorHistory(records, donorID);
                break;
            }

            case 4:
                showMonetaryReport(records);
                break;

            case 5:
                showMaterialReport(records);
                break;

            case 6:
                showTopDonors(records);
                break;

            case 7:
                verifyReportData(records);
                break;

            case 8:
            {
                string filename;
                cout << "Enter CSV filename: ";
                cin >> filename;
                exportToCSV(records, filename);
                break;
            }

            case 0:
                cout << "Returning to main menu..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 0);
}


