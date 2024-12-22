//LYNN HAYDAR_SARA ALAYAN
#include <iostream>
#include <fstream> 
#include <sstream> 
using namespace std;

struct Patient {
	string id;
	string fname;
	string lname;
	int age;
	char gender;
	string contact;
};

struct NODE {
	Patient data;
	NODE* next;
};

NODE* InitializeListPatient() {
	return NULL;
}

bool IsEmpty(NODE* head) {
	return (head == NULL);
}

void PrintList(NODE* head) {
	NODE* cur;
	if (IsEmpty(head)) {
		cout << "List is empty.";
		return;
	}
	cout << "List of Patients:\n";
	cur = head;
	while (cur != NULL) {
		cout << "ID: " << cur->data.id << endl;
		cout << "First name: " << cur->data.fname << endl;
		cout << "Last name: " << cur->data.lname << endl;
		cout << "Age: " << cur->data.age << endl;
		cout << "Gender: " << ((cur->data.gender) == 'M' ? "Male" : "Female") << endl;
		cout << "Contact: " << cur->data.contact << endl << endl;
		cur = cur->next;
	}
}

int GetElementNb(NODE* head) {
	NODE* cur;
	int n = 0;
	if (IsEmpty(head))
		return 0;
	cur = head;
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}
	return n;
}

NODE* SearchPatient(NODE* head, string id) {
	NODE* cur = head;

	while (cur != NULL)
	{
		if (cur->data.id == id)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

NODE* InsertAtQueue(NODE* head, Patient patient) {
	NODE* tmp, * cur;
	//create new Node
	tmp = new NODE;

	if (tmp == NULL)
		exit(1);  //memory allocation error

	//Initialise
	tmp->data = patient;
	tmp->next = NULL;

	//if list empty
	if (head == NULL) {
		head = tmp;
		return head;
	}

	//search for the queue of the list
	cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	return head;
}

NODE* InsertAtHead(NODE* head, Patient patient) {
	NODE* tmp;
	tmp = new NODE;
	if (tmp == NULL)
		exit(1);
	tmp->data = patient;
	tmp->next = NULL;

	tmp->next = head;
	head = tmp;
	return head;
}


NODE* DeletePatient(NODE* head, string id) {
	NODE* cur, * prev;

	if (head == NULL)
		return head;

	//delete from head
	if (head->data.id == id) {
		cur = head->next;
		delete head;
		head = cur;
		return head;
	}

	cur = head;
	prev = NULL;
	while (cur != NULL && cur->data.id != id) {
		prev = cur;
		cur = cur->next;
	}

	//if does not exist
	if (cur == NULL)
		return head;

	prev->next = cur->next;
	delete cur;
	return head;
}

NODE* DeleteList(NODE* head) {
	NODE* cur = head;
	while (cur != NULL) {
		cur = head->next;
		delete head;
		head = cur;
	}
	return head;
}

void UpdatePatientAge(NODE* head, string id, int age) {
	NODE* cur = SearchPatient(head, id);
	if (cur != NULL) {
		cur->data.age = age;
		cout << "Patient age with ID " << id << " has been updated to " << age << ".\n";
	}
	else
		cout << "Patient with ID " << id << " not found.\n";
}



NODE* ReadPatientsFromFile(const string filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error: Unable to open file " << filename << "\n";
		return NULL;
	}

	NODE* head = InitializeListPatient();
	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		Patient patient;
		string age, gender;

		// Parse the line into Patient fields
		getline(ss, patient.id, ',');
		getline(ss, patient.fname, ',');
		getline(ss, patient.lname, ',');
		getline(ss, age, ',');
		getline(ss, gender, ',');
		getline(ss, patient.contact, ',');

		// Convert string fields to appropriate types
		patient.age = stoi(age);
		patient.gender = gender[0]; // Assumes gender is a single character

		// Add the patient to the list
		head = InsertAtQueue(head, patient);
	}

	file.close();
	return head;
}

void SavePatientsToFile(NODE* head, string filename) {

	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Error: Unable to open file " << filename << "\n";
		return;
	}

	NODE* cur = head;
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
	cout << "Patients saved successfully to " << filename << ".\n";
}






