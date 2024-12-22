//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
#include <fstream> 
#include <sstream> 
using namespace std;
struct Nurse {
    string id;
    string fname;
    string lname;
    int age;
    char gender;
    string contact;
};

struct NurseNode {
    Nurse data;
    NurseNode* next;
};

NurseNode* InitializeListNurse() {
    return NULL;
}

bool IsEmptyNurse(NurseNode* head) {
    return (head == NULL);
}

void PrintNurseList(NurseNode* head) {
    NurseNode* cur;
    if (IsEmptyNurse(head)) {
        cout << "List of Nurses is empty.\n";
        return;
    }
    cout << "List of Nurses:\n";
    cur = head;
    while (cur != NULL) {
        cout << "ID: " << cur->data.id << endl;
        cout << "First name: " << cur->data.fname << endl;
        cout << "Last name: " << cur->data.lname << endl;
        cout << "Age: " << cur->data.age << endl;
        cout << "Gender: " << cur->data.gender << endl;
        cout << "Contact: " << cur->data.contact << endl<<endl;
        cur = cur->next;
    }
  
}

NurseNode* InsertAtQueueNurse(NurseNode* head, Nurse nurse) {
    NurseNode* tmp = new NurseNode;
    if (tmp == NULL)
        exit(1);  

    tmp->data = nurse;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return head;
    }

    NurseNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

NurseNode* InsertAtHeadNurse(NurseNode* head, Nurse nurse) {
    NurseNode* tmp = new NurseNode;
    if (tmp == NULL)
        exit(1);  

    tmp->data = nurse;
    tmp->next = head;
    head = tmp;
    return head;
}
bool IsValidContact(const string& contact) {
    // Check if contact is all digits and has a length of 10 (adjust as needed)
    if (contact.length() != 8) return false;
    for (char c : contact) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void UpdateNurseContact(NurseNode* head, const string id, const string contact) {
    if (!IsValidContact(contact)) {
        cout << "Error: Contact number must be 8 digits long and contain only numbers.\n";
        return;
    }

    NurseNode* cur = head;
    while (cur != NULL) {
        if (cur->data.id == id) {
            cur->data.contact = contact;
            cout << "Nurse contact with ID " << id << " has been updated to " << contact << ".\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Nurse with ID " << id << " not found.\n";
}

NurseNode* DeleteNurse(NurseNode* head, const string& id) {
    NurseNode* cur = head;
    NurseNode* prev = NULL;

    if (head == NULL) {
        return head;
    }

    if (head->data.id == id) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    while (cur != NULL && cur->data.id != id) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Nurse with ID " << id << " not found.\n";
        return head;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

NurseNode* DeleteListNurse(NurseNode* head) {
    NurseNode* cur = head;
    while (cur != NULL) {
        NurseNode* next = cur->next;
        delete cur;
        cur = next;
    }
    return NULL;
}

int GetElementNbNurse(NurseNode* head) {
    NurseNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}



bool IsValidNurseID(const string& id) {
    // Check if ID starts with "NR" followed by digits
    if (id.substr(0, 2) != "nr") return false;
    for (size_t i = 2; i < id.length(); i++) {
        if (!isdigit(id[i])) return false;
    }
    return true;
}

bool IsUniqueNurseID(NurseNode* head, const string& id) {
    NurseNode* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return false; // ID already exists in the list
        }
        current = current->next;
    }
    return true; // ID is unique
}

void AddNurse(NurseNode*& head) {
    Nurse newNurse;
    bool validInput = false;

    // Loop until a valid Nurse ID is provided
    while (!validInput) {
        cout << "Enter Nurse ID: ";
        cin >> newNurse.id;

        // Validate ID format
        if (!IsValidNurseID(newNurse.id)) {
            cout << "Error: Nurse ID must start with 'NR' followed by numbers (e.g., NR123).\n";
        }
        else if (!IsUniqueNurseID(head, newNurse.id)) {
            cout << "Error: Nurse ID already exists. Please enter a unique ID.\n";
        }
        else {
            validInput = true; // Valid ID, exit loop
        }
    }

    // Loop until a valid first name is provided
    do {
        cout << "Enter First Name: ";
        cin >> newNurse.fname;
        if (newNurse.fname.empty()) {
            cout << "Error: First name cannot be empty.\n";
        }
    } while (newNurse.fname.empty());

    // Loop until a valid last name is provided
    do {
        cout << "Enter Last Name: ";
        cin >> newNurse.lname;
        if (newNurse.lname.empty()) {
            cout << "Error: Last name cannot be empty.\n";
        }
    } while (newNurse.lname.empty());

    // Loop until a valid age is provided
    validInput = false;
    while (!validInput) {
        cout << "Enter Age: ";
        cin >> newNurse.age;
        if (cin.fail() || newNurse.age <= 0) {
            cin.clear(); // Clear input error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Error: Age must be a positive integer.\n";
        }
        else {
            validInput = true; // Valid age, exit loop
        }
    }

    // Loop until a valid gender is provided
    validInput = false;
    while (!validInput) {
        cout << "Enter Gender (M/F): ";
        cin >> newNurse.gender;
        if (newNurse.gender != 'M' && newNurse.gender != 'F') {
            cout << "Error: Gender must be 'M' or 'F'.\n";
        }
        else {
            validInput = true; // Valid gender, exit loop
        }
    }

    // Loop until a valid contact number is provided
    validInput = false;
    while (!validInput) {
        cout << "Enter Contact: ";
        cin >> newNurse.contact;
        if (newNurse.contact.empty()) {
            cout << "Error: Contact number cannot be empty.\n";
        }
        else if (!IsValidContact(newNurse.contact)) {
            cout << "Error: Contact number must be 10 digits long and contain only numbers.\n";
        }
        else {
            validInput = true; // Valid contact, exit loop
        }
    }

    // If all validations pass, insert the new nurse into the list
    head = InsertAtQueueNurse(head, newNurse);
    cout << "Nurse added successfully!\n";
}

NurseNode* ReadNursesFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return NULL;
    }

    NurseNode* head = InitializeListNurse();
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Nurse nurse;

        
        getline(ss, nurse.id, ',');
        getline(ss, nurse.fname, ',');
        getline(ss, nurse.lname, ',');
        string ageStr, genderStr;
        getline(ss, ageStr, ',');
        getline(ss, genderStr, ',');
        getline(ss, nurse.contact, ',');

        nurse.age = stoi(ageStr);          // Convert age to int
        nurse.gender = genderStr[0];      // Convert gender to char

        // Add the nurse to the list
        head = InsertAtQueueNurse(head, nurse);
    }

    file.close();
    return head;
}

void SaveNursesToFile(NurseNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    NurseNode* cur = head;
    while (cur != NULL) {
        file << cur->data.id << ","
            << cur->data.fname << ","
            << cur->data.lname << ","
            << cur->data.age << ","
            << cur->data.gender << ","
            << cur->data.contact << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Nurses saved successfully to " << filename << ".\n";
}



