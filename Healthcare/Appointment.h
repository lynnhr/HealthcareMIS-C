//LYNN HAYDAR_SARA ALAYAN
#include<iostream>
#include <fstream> 
#include <sstream> 
#include <regex>
#include <ctime>

using namespace std;

struct Appointment {
    string ApptId;              
    Patient* patient;       
    Doctor* doctor;         
    string date;            
    string time;                     
};

struct AppointmentNode {
    Appointment data;
    AppointmentNode* next;
};

AppointmentNode* InitializeListAppointment() {
    return NULL;
}

bool IsEmptyAppointment(AppointmentNode* head) {
    return (head == NULL);
}

void PrintAppointmentList(AppointmentNode* head) {
    AppointmentNode* cur;
    if (IsEmptyAppointment(head)) {
        cout << "List of Appointments is empty.\n";
        return;
    }
    cout << "List of Appointments:\n";
    cur = head;
    while (cur != NULL) {
        cout << "Appointment ID: " << cur->data.ApptId << endl;
        cout << "Patient: " << cur->data.patient->id << endl;
        cout << "Doctor: " << cur->data.doctor->id << endl;
        cout << "Date: " << cur->data.date << endl;
        cout << "Time: " << cur->data.time << endl;
        cout << endl;
        cur = cur->next;
    }
}

AppointmentNode* InsertAtQueueAppointment(AppointmentNode* head, Appointment appointment) {
    AppointmentNode* tmp = new AppointmentNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = appointment;
    tmp->next = NULL;

    if (head == NULL) {
        head = tmp;
        return head;
    }

    AppointmentNode* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = tmp;
    return head;
}

AppointmentNode* InsertAtHeadAppointment(AppointmentNode* head, Appointment appointment) {
    AppointmentNode* tmp = new AppointmentNode;
    if (tmp == NULL)
        exit(1);

    tmp->data = appointment;
    tmp->next = head;
    head = tmp;
    return head;
}

AppointmentNode* DeleteAppointment(AppointmentNode* head, string appointmentID) {
    AppointmentNode* cur = head;
    AppointmentNode* prev = NULL;

    if (head == NULL) {
        return head;
    }

    if (head->data.ApptId == appointmentID) {
        cur = head->next;
        delete head;
        head = cur;
        return head;
    }

    while (cur != NULL && cur->data.ApptId != appointmentID) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Appointment with ID " << appointmentID << " not found.\n";
        return head;
    }

    prev->next = cur->next;
    delete cur;
    return head;
}

AppointmentNode* DeleteListAppointment(AppointmentNode* head) {
    AppointmentNode* cur = head;
    while (cur != NULL) {
        AppointmentNode* next = cur->next;
        delete cur;
        cur = next;
    }
    return NULL;
}

int GetElementNbAppointment(AppointmentNode* head) {
    AppointmentNode* cur = head;
    int n = 0;
    while (cur != NULL) {
        n++;
        cur = cur->next;
    }
    return n;
}

void AddAppointment(AppointmentNode*& head) {
    Appointment newAppointment;
    cout << "Enter Appointment ID: ";
    cin >> newAppointment.ApptId;

    string patientId, doctorId;
    cout << "Enter Patient's ID: ";
    cin >> patientId;
    newAppointment.patient = new Patient{ patientId, "", "", 0, ' ', "" };

    cout << "Enter Doctor's ID: ";
    cin >> doctorId;
    newAppointment.doctor = new Doctor{ doctorId, "", "", "", "" };

    cout << "Enter Appointment Date (YYYY-MM-DD): ";
    cin >> newAppointment.date;

    cout << "Enter Appointment Time (HH:MM): ";
    cin >> newAppointment.time;

    head = InsertAtHeadAppointment(head, newAppointment);
    cout << "Appointment added successfully!\n";
}

AppointmentNode* ReadAppointmentsFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return nullptr;
    }

    AppointmentNode* head = InitializeListAppointment();
    string line;

    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        cout << "Reading line: " << line << endl;  // Debugging output to show each line
        stringstream ss(line);
        Appointment appointment;

        string appointmentID, patientId, doctorId, date, time;

        getline(ss, appointmentID, ',');
        getline(ss, patientId, ',');
        getline(ss, doctorId, ',');
        getline(ss, date, ',');
        getline(ss, time, ',');

        appointment.ApptId = appointmentID;
        appointment.patient = new Patient{ patientId, "", "", 0, ' ', "" };
        appointment.doctor = new Doctor{ doctorId, "", "", "", "" };
        appointment.date = date;
        appointment.time = time;

        head = InsertAtQueueAppointment(head, appointment);
    }

    file.close();
    return head;
}

void SaveAppointmentsToFile(AppointmentNode* head, const string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << "\n";
        return;
    }

    AppointmentNode* cur = head;
    while (cur != NULL) {
        file << cur->data.ApptId << ","
            << cur->data.patient->id << ","
            << cur->data.doctor->id << ","
            << cur->data.date << ","
            << cur->data.time << "\n";
        cur = cur->next;
    }

    file.close();
    cout << "Appointments saved successfully to " << filename << ".\n";
}