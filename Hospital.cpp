// OOP: Composition, Aggregation, Association, File Handling,  Polymorphism
#ifndef HOSPITAL_CPP
#define HOSPITAL_CPP
#include <iostream>
#include <fstream>
#include <string>
#include "Patient.cpp"
#include "Doctor.cpp"
#include "Nurse.cpp"
#include "Surgeon.cpp"
#include "Admin.cpp"
#include "Consultant_Admin.cpp"
#include "Templates.cpp"
using namespace std;

const int MAX = 30;

class Hospital {
    string name;

    // Composition: departments belong to this hospital
    string departments[5];
    int deptCount;

    // Aggregation: hospital keeps list of patients
    Patient* patients[MAX];
    int patientCount;

    // Polymorphism: one array for all medical staff (Doctor, Nurse, Surgeon, etc.)
    HealthcareWorker* staff[MAX];
    int staffCount;

    Admin* admins[MAX];
    int adminCount;

public:
    Hospital(string hospitalName) {
        name = hospitalName;
        patientCount = staffCount = adminCount = 0;

        departments[deptCount++] = "Emergency";
        departments[deptCount++] = "Surgery";
        departments[deptCount++] = "ICU";
    }

    ~Hospital() {
        int i;
        for (i = 0; i < patientCount; i++) delete patients[i];
        for (i = 0; i < staffCount; i++) delete staff[i];
        for (i = 0; i < adminCount; i++) delete admins[i];
    }

    string getName() const { return name; }

    void addPatient(Patient* p) {
        if (patientCount < MAX)
            patients[patientCount++] = p;
    }

    void addStaff(HealthcareWorker* s) {
        if (staffCount < MAX)
            staff[staffCount++] = s;
    }

    void addAdmin(Admin* a) {
        if (adminCount < MAX)
            admins[adminCount++] = a;
    }

    void showDepartments() const {
        cout << "\n--- Departments ---" << endl;
        for (int i = 0; i < deptCount; i++)
            cout << "  " << departments[i] << endl;
    }

    void showPatients() const {
        cout << "\n--- Patients ---" << endl;
        if (patientCount == 0) {
            cout << "  No patients." << endl;
            return;
        }
        for (int i = 0; i < patientCount; i++) {
            cout << "\n#" << (i + 1) << endl;
            patients[i]->display();
        }
    }

    void showStaff() const {
        cout << "\n--- Staff Directory ---" << endl;
        if (staffCount == 0) {
            cout << "  No staff." << endl;
            return;
        }
        for (int i = 0; i < staffCount; i++) {
            cout << "\n#" << (i + 1) << "  " << staff[i]->getRole()
                 << "  |  Fee: Rs." << staff[i]->getFee() << endl;
            staff[i]->display();
        }
    }

    void showAdmins() const {
        cout << "\n--- Admins ---" << endl;
        for (int i = 0; i < adminCount; i++) {
            cout << "\n#" << (i + 1) << endl;
            admins[i]->display();
        }
    }

    Patient* findPatient(int id) {
        return searchById(patients, patientCount, id);
    }

    HealthcareWorker* findStaff(int id) {
        return searchById(staff, staffCount, id);
    }

    // Association: connects staff + patient for appointment
    void bookAppointment(int staffId, int patientId) {
        HealthcareWorker* doc = findStaff(staffId);
        Patient* pat = findPatient(patientId);

        if (doc == NULL || pat == NULL) {
            cout << "\nStaff or patient not found." << endl;
            return;
        }

        cout << "\n--- Appointment ---" << endl;
        cout << "Hospital: " << name << endl;
        doc->display();
        pat->display();
        cout << "Fee: Rs." << doc->getFee() << endl;
    }

    // Deep Copy: Patient copy constructor makes a separate backup copy
    void backupPatient(int id) {
        Patient* p = findPatient(id);
        if (p == NULL) {
            cout << "\nPatient not found." << endl;
            return;
        }

        Patient backup = *p;
        cout << "\nBackup created for " << p->getName() << endl;
        backup.display();
    }

    void saveData() {
        ofstream file("patients.txt");
        for (int i = 0; i < patientCount; i++)
            file << patients[i]->getName() << " "
                 << patients[i]->getId() << " "
                 << patients[i]->getMedicalHistory() << endl;
        file.close();
        cout << "\nData saved." << endl;
    }

    void loadData() {
        ifstream file("patients.txt");
        if (!file) {
            cout << "\nNo file found." << endl;
            return;
        }

        string n, h;
        int id;
        while (file >> n >> id >> h)
            addPatient(new Patient(n, id, h));

        file.close();
        cout << "\nData loaded." << endl;
    }
};
#endif
