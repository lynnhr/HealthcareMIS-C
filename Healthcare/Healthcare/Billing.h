//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string>

using namespace std;


struct BillingRecord {
    string billID;          
    double amount;          
    bool isPaid;            
    Patient* patient;       
};
struct BillingNode {
    BillingRecord data;
    BillingNode* next;
};

BillingNode* InitializeBillingList() {
    return NULL;
}

bool IsBillingListEmpty(BillingNode* head) {
    return (head == NULL);
}

void PrintBillingList(BillingNode* head) {
    BillingNode* cur;
    if (IsBillingListEmpty(head)) {
        cout << "Billing list is empty.\n";
        return;
    }
    cout << "Billing Records:\n";
    cur = head;
    while (cur != NULL) {
        cout << "Bill ID: " << cur->data.billID << endl;
        cout << "Amount: " << cur->data.amount << endl;
        cout << "Paid: " << (cur->data.isPaid ? "Yes" : "No") << endl;
        cout << "Patient ID: " << cur->data.patient->id << endl;
        cout << endl;
        cur = cur->next;
    }
}

BillingNode* InsertAtEndBilling(BillingNode* head, BillingRecord record) {
    BillingNode* tmp = new BillingNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = record;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return head;
    }

    BillingNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

BillingNode* InsertAtStartBilling(BillingNode* head, BillingRecord record) {
    BillingNode* tmp = new BillingNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = record;
    tmp->next = head;
    head = tmp;
    return head;
}

BillingNode* DeleteBillingRecord(BillingNode* head, string billID) {
    BillingNode* cur = head;
    BillingNode* prev = NULL;

    if (head == NULL) {
        return head;
    }

    if (head->data.billID == billID) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    while (cur != NULL && cur->data.billID != billID) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Billing record with ID " << billID << " not found.\n";
        return head;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

BillingNode* DeleteBillingList(BillingNode* head) {
    BillingNode* cur = head;
    while (cur != NULL) {
        BillingNode* next = cur->next;
        delete cur;
        cur = next;
    }
    return NULL;
}

int GetBillingRecordCount(BillingNode* head) {
    BillingNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}

void AddBillingRecord(BillingNode*& head) {
    BillingRecord newRecord;
    cout << "Enter Bill ID: ";
    cin >> newRecord.billID;

    cout << "Enter Amount: ";
    cin >> newRecord.amount;

    cout << "Is the bill paid? (1 for Yes, 0 for No): ";
    cin >> newRecord.isPaid;

    string patientId;
    cout << "Enter Patient ID: ";
    cin >> patientId;
    newRecord.patient = new Patient{ patientId, "", "", 0, ' ', "" };

    head = InsertAtStartBilling(head, newRecord);
    cout << "Billing record added successfully!\n";
}
void ModifyBilling(BillingNode* head, const string& billID) {
    if (head == NULL) {
        cout << "Billing list is empty. No record to modify.\n";
        return;
    }

    BillingNode* cur = head;
    while (cur != NULL) {
        if (cur->data.billID == billID) {
            cout << "Billing record found.\n";
            cout << "Current Amount: " << cur->data.amount << "\n";
            cout << "Enter new amount: ";
            double newAmount;
            cin >> newAmount;
            cur->data.amount = newAmount;
            cout << "Billing record updated successfully.\n";
            return;
        }
        cur = cur->next;
    }

    cout << "Billing record with ID " << billID << " not found.\n";
}


BillingNode* ReadBillingRecordsFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return nullptr;
    }

    BillingNode* head = InitializeBillingList();
    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        cout << "Reading line: " << line << endl; // Debugging output to show each line
        stringstream ss(line);
        BillingRecord record;

        string billID, patientId, amountStr, isPaidStr;

        getline(ss, billID, ',');
        getline(ss, amountStr, ',');
        getline(ss, patientId, ',');
        getline(ss, isPaidStr, ',');

        record.billID = billID;
        record.amount = stod(amountStr);
        record.isPaid = (isPaidStr == "true");
        record.patient = new Patient{ patientId, "", "", 0, ' ', "" };

        head = InsertAtEndBilling(head, record);
    }

    file.close();
    return head;
}

void SaveBillingRecordsToFile(BillingNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    BillingNode* cur = head;
    while (cur != NULL) {
        file << cur->data.billID << ","
            << cur->data.amount << ","
            << cur->data.patient->id << ","
            << (cur->data.isPaid ? "true" : "false") << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Billing records saved successfully to " << filename << ".\n";
}