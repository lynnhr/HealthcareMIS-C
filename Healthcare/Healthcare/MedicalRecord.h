//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
#include <string>
#include <fstream> 
#include <sstream> 

using namespace std;

struct MedicalRecord {
    string recordID;
    string diagnosis;
    string treatment;
    Patient* patient;
};
struct MedicalRecordNode {
    MedicalRecord data;
    MedicalRecordNode* next;
};

MedicalRecordNode* InitializeMedicalRecordList() {
    return NULL;
}

bool IsMedicalRecordListEmpty(MedicalRecordNode* head) {
    return (head == NULL);
}

void PrintMedicalRecordList(MedicalRecordNode* head) {
    MedicalRecordNode* cur;
    if (IsMedicalRecordListEmpty(head)) {
        cout << "Medical record list is empty.\n";
        return;
    }
    cout << "Medical Records:\n";
    cur = head;
    while (cur != NULL) {
        cout << "Record ID: " << cur->data.recordID << endl;
        cout << "Diagnosis: " << cur->data.diagnosis << endl;
        cout << "Treatment: " << cur->data.treatment << endl;
        cout << "Patient ID: " << cur->data.patient->id << endl;
        cout << endl;
        cur = cur->next;
    }
}

MedicalRecordNode* InsertAtEndMedicalRecord(MedicalRecordNode* head, MedicalRecord record) {
    MedicalRecordNode* tmp = new MedicalRecordNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = record;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return head;
    }

    MedicalRecordNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

MedicalRecordNode* InsertAtStartMedicalRecord(MedicalRecordNode* head, MedicalRecord record) {
    MedicalRecordNode* tmp = new MedicalRecordNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = record;
    tmp->next = head;
    head = tmp;
    return head;
}

MedicalRecordNode* DeleteMedicalRecord(MedicalRecordNode* head, string recordID) {
    MedicalRecordNode* cur = head;
    MedicalRecordNode* prev = NULL;

    if (head == NULL) {
        return head;
    }

    if (head->data.recordID == recordID) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    while (cur != NULL && cur->data.recordID != recordID) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Medical record with ID " << recordID << " not found.\n";
        return head;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

MedicalRecordNode* DeleteMedicalRecordList(MedicalRecordNode* head) {
    MedicalRecordNode* cur = head;
    while (cur != NULL) {
        MedicalRecordNode* next = cur->next;
        delete cur;
        cur = next;
    }
    return NULL;
}

int GetMedicalRecordCount(MedicalRecordNode* head) {
    MedicalRecordNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}

void AddMedicalRecord(MedicalRecordNode*& head) {
    MedicalRecord newRecord;
    cout << "Enter Record ID: ";
    cin >> newRecord.recordID;

    cout << "Enter Diagnosis: ";
    cin.ignore();
    getline(cin, newRecord.diagnosis);

    cout << "Enter Treatment: ";
    getline(cin, newRecord.treatment);

    string patientId;
    cout << "Enter Patient ID: ";
    cin >> patientId;
    newRecord.patient = new Patient{ patientId, "", "", 0, ' ', "" };

    head = InsertAtStartMedicalRecord(head, newRecord);
    cout << "Medical record added successfully!\n";
}

void ModifyMedicalRecord(MedicalRecordNode* head, const string& recordID) {
    if (head == NULL) {
        cout << "Medical record list is empty. No record to modify.\n";
        return;
    }

    MedicalRecordNode* cur = head;
    while (cur != NULL) {
        if (cur->data.recordID == recordID) {
            cout << "Medical record found.\n";
            cout << "Current Diagnosis: " << cur->data.diagnosis << "\n";
            cout << "Enter new Diagnosis: ";
            string newDiagnosis;
            cin.ignore();
            getline(cin, newDiagnosis);
            cur->data.diagnosis = newDiagnosis;

            cout << "Medical record updated successfully.\n";
            return;
        }
        cur = cur->next;
    }

    cout << "Medical record with ID " << recordID << " not found.\n";
}

void SwapMedicalRecords(MedicalRecordNode* node1, MedicalRecordNode* node2) {
    MedicalRecord temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void SortMedicalRecords(MedicalRecordNode* head) {
    if (head == NULL) {
        return;  // If the list is empty, no need to sort
    }

    MedicalRecordNode* cur = head;
    while (cur != NULL) {
        MedicalRecordNode* next = cur->next;
        while (next != NULL) {
            if (cur->data.recordID > next->data.recordID) {
                // Swap the records if they are out of order
                SwapMedicalRecords(cur, next);
            }
            next = next->next;
        }
        cur = cur->next;
    }
}


MedicalRecordNode* ReadMedicalRecordsFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return nullptr;
    }

    MedicalRecordNode* head = InitializeMedicalRecordList();
    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        MedicalRecord record;

        string recordID, diagnosis, treatment, patientId;

        getline(ss, recordID, ',');
        getline(ss, diagnosis, ',');
        getline(ss, treatment, ',');
        getline(ss, patientId, ',');

        record.recordID = recordID;
        record.diagnosis = diagnosis;
        record.treatment = treatment;
        record.patient = new Patient{ patientId, "", "", 0, ' ', "" };

        head = InsertAtEndMedicalRecord(head, record);
    }

    file.close();
    return head;
}

void SaveMedicalRecordsToFile(MedicalRecordNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    MedicalRecordNode* cur = head;
    while (cur != NULL) {
        file << cur->data.recordID << ","
            << cur->data.diagnosis << ","
            << cur->data.treatment << ","
            << cur->data.patient->id << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Medical records saved successfully to " << filename << ".\n";
}
