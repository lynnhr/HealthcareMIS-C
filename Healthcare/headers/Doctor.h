//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
using namespace std;
#include <fstream> // For file handling
#include <sstream>


struct Doctor {
    string id;
    string fname;
    string lname;
    string specialty;
    string contact;
};

struct DoctorNode {
    Doctor data;
    DoctorNode* next;
};

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
        exit(1);  

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

bool IsValidContact(const string& contact) {
    // Check if contact is all digits and has a length of 10 (adjust as needed)
    if (contact.length() != 8) return false;
    for (char c : contact) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool IsValidDoctorID(const string& id) {
    // Check if ID starts with "DR" followed by digits
    if (id.substr(0, 2) != "dr") return false;
    for (size_t i = 2; i < id.length(); i++) {
        if (!isdigit(id[i])) return false;
    }
    return true;
}

bool IsUniqueDoctorID(DoctorNode* head, const string& id) {
    DoctorNode* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return false; // ID already exists in the list
        }
        current = current->next;
    }
    return true; // ID is unique
}

void AddDoctor(DoctorNode*& head) {
    Doctor newDoctor;
    bool validInput = false;

    // Loop until a valid Doctor ID is provided
    while (!validInput) {
        cout << "Enter Doctor ID: ";
        cin >> newDoctor.id;

        // Validate ID format
        if (!IsValidDoctorID(newDoctor.id)) {
            cout << "Error: Doctor ID must start with 'DR' followed by numbers (e.g., DR123).\n";
        }
        else if (!IsUniqueDoctorID(head, newDoctor.id)) {
            cout << "Error: Doctor ID already exists. Please enter a unique ID.\n";
        }
        else {
            validInput = true; // Valid ID, exit loop
        }
    }

    // Loop until a valid first name is provided
    do {
        cout << "Enter First Name: ";
        cin >> newDoctor.fname;
        if (newDoctor.fname.empty()) {
            cout << "Error: First name cannot be empty.\n";
        }
    } while (newDoctor.fname.empty());

    // Loop until a valid last name is provided
    do {
        cout << "Enter Last Name: ";
        cin >> newDoctor.lname;
        if (newDoctor.lname.empty()) {
            cout << "Error: Last name cannot be empty.\n";
        }
    } while (newDoctor.lname.empty());

    // Loop until a valid specialty is provided
    do {
        cout << "Enter Specialty: ";
        cin >> newDoctor.specialty;
        if (newDoctor.specialty.empty()) {
            cout << "Error: Specialty cannot be empty.\n";
        }
    } while (newDoctor.specialty.empty());

    // Loop until a valid contact number is provided
    validInput = false;
    while (!validInput) {
        cout << "Enter Contact: ";
        cin >> newDoctor.contact;
        if (newDoctor.contact.empty()) {
            cout << "Error: Contact number cannot be empty.\n";
        }
        else if (!IsValidContact(newDoctor.contact)) {
            cout << "Error: Contact number must be 10 digits long and contain only numbers.\n";
        }
        else {
            validInput = true; // Valid contact, exit loop
        }
    }

    // If all validations pass, insert the new doctor at the head of the list
    head = InsertAtHeadDoctor(head, newDoctor);
    cout << "Doctor added successfully!\n";
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



