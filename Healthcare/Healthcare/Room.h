//LYNN HAYDAR_SARA ALAYAN  
#include<iostream>
#include <fstream> 
#include <sstream>
#include <algorithm>
#include <limits>
using namespace std;

struct Room {
    int roomNumber;         
    bool isAvailable;          
    Patient* assignedPatient;  // Pointer to the Patient assigned to the room 
    Doctor* assignedDoctor;    // Pointer to the Doctor assigned to the room 
};

struct RoomNode {
    Room data;
    RoomNode* next;
};

RoomNode* InitializeListRoom() {
    return NULL;
}

bool IsEmptyRoom(RoomNode* head) {
    return (head == NULL);
}

void PrintRoomList(RoomNode* head) {
    RoomNode* cur;
    if (IsEmptyRoom(head)) {
        cout << "List of Rooms is empty.\n";
        return;
    }
    cout << "List of Rooms:\n";
    cur = head;
    while (cur != NULL) {
        cout << "Room Number: " << cur->data.roomNumber << endl;
        cout << "Availability: " << (cur->data.isAvailable ? "Available" : "Occupied") << endl;
        if (cur->data.assignedPatient != nullptr) {
            cout << "Assigned Patient: " << cur->data.assignedPatient->id  << endl;
        }
        else {
            cout << "No patient assigned.\n";
        }
        if (cur->data.assignedDoctor != nullptr) {
            cout << "Assigned Doctor: " << cur->data.assignedDoctor->id  << endl;
        }
        else {
            cout << "No doctor assigned.\n";
        }
        cout << endl;
        cur = cur->next;
    }
}

RoomNode* InsertAtQueueRoom(RoomNode* head, Room room) {
    RoomNode* tmp = new RoomNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = room;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return head;
    }

    RoomNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

RoomNode* InsertAtHeadRoom(RoomNode* head, Room room) {
    RoomNode* tmp = new RoomNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = room;
    tmp->next = head;
    head = tmp;
    return head;
}

void UpdateRoomAvailability(RoomNode* head) {
    int roomNumber;
    string availabilityInput;
    bool isAvailable;

    // Validate Room Number
    do {
        cout << "Enter Room Number (positive integer): ";
        cin >> roomNumber;
        if (cin.fail() || roomNumber <= 0) {
            cout << "Error: Room number must be a positive integer.\n";
            cin.clear(); // Clear input error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover characters
            break;
        }
    } while (true);

    // Validate Availability Input
    do {
        cout << "Enter Availability (1 for available, 0 for occupied): ";
        cin >> availabilityInput;
        if (availabilityInput == "1") {
            isAvailable = true;
            break;
        }
        else if (availabilityInput == "0") {
            isAvailable = false;
            break;
        }
        else {
            cout << "Error: Availability must be 1 (available) or 0 (occupied).\n";
            cin.clear(); // Clear input error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (true);

    // Search for the room and update availability
    RoomNode* cur = head;
    while (cur != NULL) {
        if (cur->data.roomNumber == roomNumber) {
            cur->data.isAvailable = isAvailable;
            cout << "Room number " << roomNumber << " availability has been updated to "
                << (isAvailable ? "available" : "occupied") << ".\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Room with number " << roomNumber << " not found.\n";
}

RoomNode* DeleteRoom(RoomNode* head, int roomNumber) {
    RoomNode* cur = head;
    RoomNode* prev = NULL;

    if (head == NULL) {
        return head;
    }

    if (head->data.roomNumber == roomNumber) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    while (cur != NULL && cur->data.roomNumber != roomNumber) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Room with number " << roomNumber << " not found.\n";
        return head;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

RoomNode* DeleteListRoom(RoomNode* head) {
    RoomNode* cur = head;
    while (cur != NULL) {
        RoomNode* next = cur->next;
        delete cur;
        cur = next;
    }
    return NULL;
}

int GetElementNbRoom(RoomNode* head) {
    RoomNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}

void AddRoom(RoomNode*& head) {
    Room newRoom;
    int roomNumber;
    string availability, patientId, doctorId;

    // Validate Room Number
    do {
        cout << "Enter Room Number (positive integer): ";
        cin >> roomNumber;
        if (roomNumber <= 0) {
            cout << "Error: Room number must be a positive integer.\n";
        }
    } while (roomNumber <= 0);
    newRoom.roomNumber = roomNumber;

    // Validate Availability
    do {
        cout << "Enter Availability (1 for available, 0 for occupied): ";
        cin >> availability;
        if (availability != "1" && availability != "0") {
            cout << "Error: Availability must be 1 (available) or 0 (occupied).\n";
        }
    } while (availability != "1" && availability != "0");
    newRoom.isAvailable = (availability == "1");

    // Validate Patient's ID
    do {
        cout << "Enter Patient's ID (starts with 'pt' followed by digits): ";
        cin >> patientId;
        if (patientId.size() < 3 || patientId.substr(0, 2) != "pt" ||
            !all_of(patientId.begin() + 2, patientId.end(), ::isdigit)) {
            cout << "Error: Patient ID must start with 'pt' followed by digits.\n";
        }
    } while (patientId.size() < 3 || patientId.substr(0, 2) != "pt" ||
        !all_of(patientId.begin() + 2, patientId.end(), ::isdigit));
    newRoom.assignedPatient = new Patient{ patientId, "", "", 0, ' ', "" };

    // Validate Doctor's ID
    do {
        cout << "Enter Doctor's ID (starts with 'dr' followed by digits): ";
        cin >> doctorId;
        if (doctorId.size() < 3 || doctorId.substr(0, 2) != "dr" ||
            !all_of(doctorId.begin() + 2, doctorId.end(), ::isdigit)) {
            cout << "Error: Doctor ID must start with 'dr' followed by digits.\n";
        }
    } while (doctorId.size() < 3 || doctorId.substr(0, 2) != "dr" ||
        !all_of(doctorId.begin() + 2, doctorId.end(), ::isdigit));
    newRoom.assignedDoctor = new Doctor{ doctorId, "", "", "", "" };

    // Add the room to the list
    head = InsertAtHeadRoom(head, newRoom);
    cout << "Room added successfully!\n";
}


RoomNode* ReadRoomsFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return nullptr;
    }

    RoomNode* head = InitializeListRoom();
    string line;

    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        cout << "Reading line: " << line << endl;  // Debugging output to show each line
        stringstream ss(line);
        Room room;

        string roomNumberStr, availabilityStr, patientId, doctorId;

        getline(ss, roomNumberStr, ',');
        getline(ss, availabilityStr, ',');
        getline(ss, patientId, ',');
        getline(ss, doctorId, ',');

        // Check if the room number is valid and non-empty before attempting conversion
        if (roomNumberStr.empty()) {
            cout << "Error: Room number is empty. Skipping line.\n";
            continue;  // Skip this line if the room number is missing
        }

        try {
            room.roomNumber = stoi(roomNumberStr);  // Convert room number to int
        }
        catch (const std::invalid_argument& e) {
            cout << "Invalid room number: " << roomNumberStr << ". Skipping this line.\n";
            continue;  // Skip this line if the room number is invalid
        }

        // Handle availability, assuming '1' means available and '0' means unavailable
        room.isAvailable = (availabilityStr == "1");

        // Assign patient and doctor pointers if IDs are not empty
        room.assignedPatient = patientId.empty() ? nullptr : new Patient{ patientId, "", "", 0, ' ', "" };
        room.assignedDoctor = doctorId.empty() ? nullptr : new Doctor{ doctorId, "", "", "", "" };



        head = InsertAtQueueRoom(head, room);
    }

    file.close();
    return head;
}

void SaveRoomsToFile(RoomNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    RoomNode* cur = head;
    while (cur != NULL) {
        file << cur->data.roomNumber << ","
            << (cur->data.isAvailable ? "0" : "1") << ","
            << (cur->data.assignedPatient ? cur->data.assignedPatient->id : "") << ","
            << (cur->data.assignedDoctor ? cur->data.assignedDoctor->id : "") << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Rooms saved successfully to " << filename << ".\n";
}


