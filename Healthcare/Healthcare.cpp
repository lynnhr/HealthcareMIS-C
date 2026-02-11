//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
using namespace std;
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Room.h"
#include "Appointment.h"
#include "Billing.h"
#include "MedicalRecord.h"
#include <iostream>
#include <string>
#include <unordered_map> // For storing user credentials
using namespace std;

// Structure to represent user credentials
struct User {
    string username;
    string password;
    string role; // Roles: "admin", "doctor", "secretary", "accountant", "roommanager"
};

// Function prototypes
void DoctorManagerMenu();
void NurseManagerMenu();
void AdminMenu();
void DoctorMenu();
void AppointmentMenu();
void MedicalRecordManagement();
void SecretaryMenu();
void AccountantMenu();
void RoomManagerMenu();
void LoginMenu(unordered_map<string, User>& users);

int main() {
    // Sample users (can be loaded from a file in a real-world application)
    unordered_map<string, User> users = {
        {"admin1", {"admin1", "adminpass", "admin"}},
        {"doc1", {"doc1", "docpass", "doctor"}},
        {"sec1", {"sec1", "secpass", "secretary"}},
        {"acc1", {"acc1", "accpass", "accountant"}},
        {"room1", {"room1", "roompass", "roommanager"}}
    };

    // Display login menu
    LoginMenu(users);

    return 0;
}

void LoginMenu(unordered_map<string, User>& users) {
    string username, password;

    cout << "--- Login Menu ---\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username].password == password) {
        string role = users[username].role;
        cout << "Login successful! Role: " << role << "\n";

        // Show the corresponding menu based on role
        if (role == "admin") {
            AdminMenu();
        }
        else if (role == "doctor") {
            DoctorMenu();
        }
        else if (role == "secretary") {
            SecretaryMenu();
        }
        else if (role == "accountant") {
            AccountantMenu();
        }
        else if (role == "roommanager") {
            RoomManagerMenu();
        }
        else {
            cout << "Unknown role. Access denied.\n";
        }
    }
    else {
        cout << "Invalid username or password. Try again.\n";
    }
}
void DoctorManagerMenu() {
    int choice;
    DoctorNode* head = ReadDoctorsFromFile("Doctor.txt");

    do {
        cout << "\n--- Doctor Manager Menu ---\n";
        cout << "1. Add a Doctor\n";
        cout << "2. Update Doctor Specialty\n";
        cout << "3. Delete a Doctor\n";
        cout << "4. Print Doctor List\n";
        cout << "5. Check if list of doctors is empty\n";
        cout << "6. Get Total Number of Doctors\n";
        cout << "7. Exit to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddDoctor(head);
            break;
        case 2: {
            string id, specialty;
            cout << "Enter Doctor ID to update: ";
            cin >> id;
            cout << "Enter new specialty: ";
            cin >> specialty;
            UpdateDoctorSpecialty(head, id, specialty);
            break;
        }
        case 3: {
            string id;
            cout << "Enter Doctor ID to delete: ";
            cin >> id;
            head = DeleteDoctor(head, id);
            break;
        }
        case 4:
            PrintDoctorList(head);
            break;
        case 5:
            if (IsEmptyDoctor(head)) {
                cout << "The list of doctors is empty.\n";
            }
            else {
                cout << "The list of doctors is not empty.\n";
            }
            break;
        case 6:
            cout << "Total number of doctors: " << GetElementNbDoctor(head) << endl;
            break;
        case 7:
            cout << "Returning to Admin Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    SaveDoctorsToFile(head, "Doctors.txt");
    DeleteListDoctor(head);
}
void NurseManagerMenu() {
    int choice;
    string filename = "Nurse.txt";
    NurseNode* nurseHead = ReadNursesFromFile(filename);
    do {
        cout << "\n--- Nurse Manager Menu ---\n";
        cout << "1. View all nurses\n";
        cout << "2. Add a new nurse\n";
        cout << "3. Update nurse contact\n";
        cout << "4. Delete a nurse\n";
        cout << "5. Save nurses to file\n";
        cout << "6. Read nurses from file\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            PrintNurseList(nurseHead);
            break;
        case 2:
            AddNurse(nurseHead);
            break;
        case 3: {
            string id, contact;
            cout << "Enter Nurse ID to update contact: ";
            cin >> id;
            cout << "Enter new contact: ";
            cin >> contact;
            UpdateNurseContact(nurseHead, id, contact);
            break;
        }
        case 4: {
            string id;
            cout << "Enter Nurse ID to delete: ";
            cin >> id;
            nurseHead = DeleteNurse(nurseHead, id);
            break;
        }
        case 5: {
            string filename;
            cout << "Enter filename to save nurses: ";
            cin >> filename;
            SaveNursesToFile(nurseHead, filename);
            break;
        }
        case 6: {
            string filename;
            cout << "Enter filename to read nurses from: ";
            cin >> filename;
            nurseHead = ReadNursesFromFile(filename);
            break;
        }
        case 7:
            cout << "Exiting Nurse Manager Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
  
    SaveNursesToFile(nurseHead, filename);
    DeleteListNurse(nurseHead);
}

// Admin menu
void AdminMenu() {
    int choice;; 
   

    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Manage Doctors\n";
        cout << "2. Manage Nurses\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            DoctorManagerMenu();  
            break;
        case 2:
            cout << "Admin: Managing nurses...\n";
            NurseManagerMenu();
            break;
        case 3:
            cout << "Exiting Admin Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    
}

void DoctorMenu() {
    int choice;
    string filename = "Patient.txt";
    NODE* head = ReadPatientsFromFile(filename);
    
    do {
        cout << "\n--- Doctor Menu ---\n";
        cout << "1. View Patients\n";
        cout << "2. Add Patient\n";
        cout << "3. Update Patient Age\n";
        cout << "4. Delete Patient\n";
        cout << "5. Search Patient by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            PrintList(head);
            break;
        case 2: {
            Patient newPatient;
            cout << "Enter patient ID: ";
            cin >> newPatient.id;
            cout << "Enter first name: ";
            cin >> newPatient.fname;
            cout << "Enter last name: ";
            cin >> newPatient.lname;
            cout << "Enter age: ";
            cin >> newPatient.age;
            cout << "Enter gender (M/F): ";
            cin >> newPatient.gender;
            cout << "Enter contact: ";
            cin >> newPatient.contact;
            head = InsertAtQueue(head, newPatient);
            cout << "Patient added successfully.\n";
            break;
        }
        case 3: {
            string id;
            int age;
            cout << "Enter patient ID to update age: ";
            cin >> id;
            cout << "Enter new age: ";
            cin >> age;
            UpdatePatientAge(head, id, age);
            break;
        }
        case 4: {
            string id;
            cout << "Enter patient ID to delete: ";
            cin >> id;
            head = DeletePatient(head, id);
            cout << "Patient deleted successfully (if ID existed).\n";
            break;
        }
        
  
        case 5: {
            string id;
            cout << "Enter patient ID to search: ";
            cin >> id;
            NODE* foundPatient = SearchPatient(head, id);
            if (foundPatient != NULL) {
                cout << "Patient found:\n";
                cout << "ID: " << foundPatient->data.id << endl;
                cout << "First name: " << foundPatient->data.fname << endl;
                cout << "Last name: " << foundPatient->data.lname << endl;
                cout << "Age: " << foundPatient->data.age << endl;
                cout << "Gender: " << ((foundPatient->data.gender) == 'M' ? "Male" : "Female") << endl;
                cout << "Contact: " << foundPatient->data.contact << endl;
            }
            else {
                cout << "Patient with ID " << id << " not found.\n";
            }
            break;
        }
        case 6:
            cout << "Exiting Doctor Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}

void AppointmentMenu() {
        int choice;
        string filename="Appointment.txt";
        AppointmentNode* appointmentList = ReadAppointmentsFromFile(filename);
        string appointmentID;

        do {
            // Display the menu
            cout << "\nAppointment Management Menu\n";
            cout << "1. Add Appointment\n";
            cout << "2. Print Appointments\n";
            cout << "3. Delete Appointment\n";
            cout << "4. Get Number of Appointments\n";
            cout << "5. Read Appointments from File\n";
            cout << "6. Save Appointments to File\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // Add a new appointment
                AddAppointment(appointmentList);
                break;
            case 2:
                // Print all appointments
                PrintAppointmentList(appointmentList);
                break;
            case 3:
                // Delete an appointment by ID
                cout << "Enter Appointment ID to delete: ";
                cin >> appointmentID;
                appointmentList = DeleteAppointment(appointmentList, appointmentID);
                break;
            case 4:
                // Display the number of appointments
                cout << "Number of appointments: " << GetElementNbAppointment(appointmentList) << endl;
                break;
            case 5:
                // Read appointments from a file
                cout << "Enter filename to read from: ";
                cin >> filename;
                appointmentList = ReadAppointmentsFromFile(filename);
                break;
            case 6:
                // Save appointments to a file
                cout << "Enter filename to save to: ";
                cin >> filename;
                SaveAppointmentsToFile(appointmentList, filename);
                break;
            case 7:
                // Exit the program
                cout << "Exiting program.\n";
                break;
            default:
                // Handle invalid menu choices
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 7);

        // Clean up dynamically allocated memory before exiting
        SaveAppointmentsToFile(appointmentList, filename);
        appointmentList = DeleteListAppointment(appointmentList);
    }

void MedicalRecordManagement() {
    int choice;
    string filename=("MedicalRecord.txt");
    MedicalRecordNode* medicalRecordList=ReadMedicalRecordsFromFile(filename);
    string recordID;

    do {
        // Display the menu
        cout << "\nMedical Record Management Menu\n";
        cout << "1. Add Medical Record\n";
        cout << "2. Print Medical Records\n";
        cout << "3. Delete Medical Record\n";
        cout << "4. Modify Medical Record\n";
        cout << "5. Sort Medical Records\n";
        cout << "6. Get Number of Medical Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Add a new medical record
            AddMedicalRecord(medicalRecordList);
            break;
        case 2:
            // Print all medical records
            PrintMedicalRecordList(medicalRecordList);
            break;
        case 3:
            // Delete a medical record by ID
            cout << "Enter Record ID to delete: ";
            cin >> recordID;
            medicalRecordList = DeleteMedicalRecord(medicalRecordList, recordID);
            break;
        case 4:
            // Modify a medical record by ID
            cout << "Enter Record ID to modify: ";
            cin >> recordID;
            ModifyMedicalRecord(medicalRecordList, recordID);
            break;
        case 5:
            // Sort the medical records
            SortMedicalRecords(medicalRecordList);
            cout << "Medical records sorted successfully.\n";
            break;
        case 6:
            // Display the number of medical records
            cout << "Number of medical records: " << GetMedicalRecordCount(medicalRecordList) << endl;
            break;
        case 7:
            // Exit the program
            cout << "Exiting program.\n";
            break;
        default:
            // Handle invalid menu choices
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    // Clean up dynamically allocated memory before exiting
    SaveMedicalRecordsToFile(medicalRecordList, filename);
    medicalRecordList = DeleteMedicalRecordList(medicalRecordList);
}


// Secretary menu
void SecretaryMenu() {
    int choice;
    do {
        cout << "\n--- Secretary Menu ---\n";
        cout << "1. Manage Medical Records\n";
        cout << "2. Manage Appointments\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Secretary: Managing medical records...\n";
            MedicalRecordManagement();
            break;
        case 2:
            cout << "Secretary: Managing appointments...\n";
            AppointmentMenu();
            break;
        case 3:
            cout << "Exiting Secretary Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

// Accountant menu
void AccountantMenu() {
        BillingNode* billingList = InitializeBillingList();
        int choice;
        string filename="Billing.txt";
        billingList = ReadBillingRecordsFromFile(filename);


        do {
            // Display the menu
            cout << "----- Billing Record Management -----\n";
            cout << "1. Add a new billing record\n";
            cout << "2. Print all billing records\n";
            cout << "3. Modify a billing record\n";
            cout << "4. Delete a billing record\n";
            cout << "5. View total number of billing records\n";
            cout << "6. Exit\n";
            cout << "-------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                AddBillingRecord(billingList);
                break;
            }
            case 2: {
                PrintBillingList(billingList);
                break;
            }
            case 3: {
                string billID;
                cout << "Enter Bill ID to modify: ";
                cin >> billID;
                ModifyBilling(billingList, billID);
                break;
            }
            case 4: {
                string billID;
                cout << "Enter Bill ID to delete: ";
                cin >> billID;
                billingList = DeleteBillingRecord(billingList, billID);
                break;
            }
            case 5: {
                int count = GetBillingRecordCount(billingList);
                cout << "Total number of billing records: " << count << endl;
                break;
            }
            case 6: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
                break;
            }
            }
        } while (choice != 6);

        SaveBillingRecordsToFile(billingList, filename);
        DeleteBillingList(billingList);
    }

// Room manager menu
void RoomManagerMenu() {

    int choice;
    string filename="Room.txt";
    RoomNode* head;
    head = ReadRoomsFromFile(filename);

    do {
        cout << "\n--- Room Manager Menu ---\n";
        cout << "1. Print Room List\n";
        cout << "2. Update Room Availibilty\n";
        cout << "3. Delete a Room\n";
        cout << "4. Get Total Number of Rooms\n";
        cout << "5. Check if list of rooms is empty\n ";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            PrintRoomList(head);
            break;
        }
        case 2: {
            int roomNumber;
            bool isAvailable;
            cout << "Enter Room Number to update: ";
            cin >> roomNumber;
            cout << "Enter Availability (1 for available, 0 for occupied): ";
            cin >> isAvailable;
            UpdateRoomAvailability(head, roomNumber, isAvailable);
            SaveRoomsToFile(head, filename);
            break;
        }
        case 3: {
            int roomNumber;
            cout << "Enter Room Number to delete: ";
            cin >> roomNumber;
            head = DeleteRoom(head, roomNumber);
            SaveRoomsToFile(head, filename);
            break;
        }
        case 4: {
            int totalRooms = GetElementNbRoom(head);
            cout << "Total number of rooms: " << totalRooms << "\n";
            break;
        }
        case 5: {
            if (IsEmptyRoom(head)) {
                cout << "The list of rooms is empty." << endl;
            }
            else {
                cout << "The list of rooms is not empty." << endl;
            }
            break;
        }
        case 6: {
            cout << "Exiting Room Manager Menu...\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 6);

    // Clean up the linked list when exiting
    SaveRoomsToFile(head, filename);
    head = DeleteListRoom(head);
}




 

