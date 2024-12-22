#include <iostream>
#include <fstream>
#include <sstream>
#include "Doctor.h"

using namespace std;

void AddDoctor(DoctorNode*& head) {
    Doctor newDoctor;

    cout << "Enter Doctor ID: ";
    cin >> newDoctor.id;
    cout << "Enter First Name: ";
    cin >> newDoctor.fname;
    cout << "Enter Last Name: ";
    cin >> newDoctor.lname;
    cout << "Enter Specialty: ";
    cin >> newDoctor.specialty;
    cout << "Enter Contact: ";
    cin >> newDoctor.contact;

    // Insert the new doctor at the head of the list
    head = InsertAtHeadDoctor(head, newDoctor);
    cout << "Doctor added successfully!\n";
}

DoctorNode* InitializeListDoctor() {
    return NULL;
}

bool IsEmptyDoctor(DoctorNode* head) {
    return (head == NULL);
}

void PrintDoctorList(DoctorNode* head) {
    DoctorNode* cur;
    if (IsEmptyDoctor(head)) {
        cout << "List of Doctors is empty.\n";
        return;
    }
    cout << "List of Doctors:\n";
    cur = head;
    while (cur != NULL) {
        cout << "ID: " << cur->data.id << endl;
        cout << "First name: " << cur->data.fname << endl;
        cout << "Last name: " << cur->data.lname << endl;
        cout << "Specialty: " << cur->data.specialty << endl;
        cout << "Contact: " << cur->data.contact << endl << endl;
        cur = cur->next;
    }
}

DoctorNode* InsertAtQueueDoctor(DoctorNode* head, Doctor doctor) {
    DoctorNode* tmp = new DoctorNode;
    if (tmp == NULL)
        exit(1);  // Memory allocation error

    // Initialize
    tmp->data = doctor;
    tmp->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = tmp;
        return head;
    }

    // Search for the end of the list
    DoctorNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

DoctorNode* ReadDoctorsFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return NULL;
    }

    DoctorNode* head = InitializeListDoctor();
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Doctor doctor;

        // Parse the line into Doctor fields
        getline(ss, doctor.id, ',');
        getline(ss, doctor.fname, ',');
        getline(ss, doctor.lname, ',');
        getline(ss, doctor.specialty, ',');
        getline(ss, doctor.contact, ',');

        // Add the doctor to the list
        head = InsertAtQueueDoctor(head, doctor);
    }

    file.close();
    return head;
}

void SaveDoctorsToFile(DoctorNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    DoctorNode* cur = head;
    while (cur != NULL) {
        file << cur->data.id << ","
            << cur->data.fname << ","
            << cur->data.lname << ","
            << cur->data.specialty << ","
            << cur->data.contact << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Doctors saved successfully to " << filename << ".\n";
}

DoctorNode* InsertAtHeadDoctor(DoctorNode* head, Doctor doctor) {
    DoctorNode* tmp = new DoctorNode;
    if (tmp == NULL)
        exit(1);  // Memory allocation error

    // Initialize
    tmp->data = doctor;
    tmp->next = head; // Point new node to the current head
    head = tmp;       // Update head to new node
    return head;
}

void UpdateDoctorSpecialty(DoctorNode* head, const string id, const string specialty) {
    DoctorNode* cur = head;
    while (cur != NULL) {
        if (cur->data.id == id) {
            cur->data.specialty = specialty;
            cout << "Doctor specialty with ID " << id << " has been updated to " << specialty << ".\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Doctor with ID " << id << " not found.\n";
}

DoctorNode* DeleteDoctor(DoctorNode* head, const string& id) {
    DoctorNode* cur = head;
    DoctorNode* prev = NULL;

    // If list is empty
    if (head == NULL) {
        return head;
    }

    // Delete from head
    if (head->data.id == id) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    // Search for the doctor to delete
    while (cur != NULL && cur->data.id != id) {
        prev = cur;
        cur = cur->next;
    }

    // If the doctor does not exist
    if (cur == NULL) {
        cout << "Doctor with ID " << id << " not found.\n";
        return head;
    }

    // Unlink the node from the list
    prev->next = cur->next;
    delete cur; // Free memory
    return head;
}

DoctorNode* DeleteListDoctor(DoctorNode* head) {
    DoctorNode* cur = head;
    while (cur != NULL) {
        DoctorNode* next = cur->next;
        delete cur; // Free memory
        cur = next;
    }
    return NULL; // Return NULL to indicate the list is empty
}

int GetElementNbDoctor(DoctorNode* head) {
    DoctorNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}