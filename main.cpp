#include <iostream>
#include <limits>
#include "Hospital.cpp"
#include "Consultant_Admin.cpp"
using namespace std;
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    Hospital hospital("City General Hospital");
    int choice = -1;

    cout << "\nWelcome to " << hospital.getName() << endl;

    while (choice != 0) {
        cout << "\n========== MENU ==========" << endl;
        cout << " 1. Add Patient" << endl;
        cout << " 2. Add Doctor" << endl;
        cout << " 3. Add Nurse" << endl;
        cout << " 4. Add Surgeon" << endl;
        cout << " 5. Add Consultant Admin" << endl;
        cout << " 6. Add Admin" << endl;
        cout << " 7. View Patients" << endl;
        cout << " 8. View Staff" << endl;          // Polymorphism
        cout << " 9. View Admins" << endl;
        cout << "10. Find Patient" << endl;          // Function Template
        cout << "11. Book Appointment" << endl;    // Association
        cout << "12. Backup Patient Record" << endl; // Deep Copy
        cout << "13. View Departments" << endl;      // Composition
        cout << "14. Save Data" << endl;             // File Handling
        cout << "15. Load Data" << endl;
        cout << " 0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        clearBuffer();

        string name, dept, spec, ward, surgery, office, history;
        int id;

        if (choice == 1) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "History: "; getline(cin, history);
            hospital.addPatient(new Patient(name, id, history));
            cout << "Done." << endl;
        }
        else if (choice == 2) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "Dept: "; getline(cin, dept);
            cout << "Specialization: "; getline(cin, spec);
            hospital.addStaff(new Doctor(name, id, dept, spec));
            cout << "Done." << endl;
        }
        else if (choice == 3) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "Dept: "; getline(cin, dept);
            cout << "Ward: "; getline(cin, ward);
            hospital.addStaff(new Nurse(name, id, dept, ward));
            cout << "Done." << endl;
        }
        else if (choice == 4) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "Dept: "; getline(cin, dept);
            cout << "Spec: "; getline(cin, spec);
            cout << "Surgery type: "; getline(cin, surgery);
            hospital.addStaff(new Surgeon(name, id, dept, spec, surgery));
            cout << "Done." << endl;
        }
        else if (choice == 5) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "Dept: "; getline(cin, dept);
            cout << "Spec: "; getline(cin, spec);
            cout << "Office: "; getline(cin, office);
            hospital.addStaff(new ConsultantAdmin(name, id, dept, spec, office));
            cout << "Done." << endl;
        }
        else if (choice == 6) {
            cout << "Name: "; getline(cin, name);
            cout << "ID: "; cin >> id; clearBuffer();
            cout << "Office: "; getline(cin, office);
            hospital.addAdmin(new Admin(name, id, office));
            cout << "Done." << endl;
        }
        else if (choice == 7) hospital.showPatients();
        else if (choice == 8) hospital.showStaff();
        else if (choice == 9) hospital.showAdmins();
        else if (choice == 10) {
            cout << "Patient ID: "; 
            cin >> id;
            Patient* p = hospital.findPatient(id);
            if (p) 
            { 
                cout << "\nFound:" << endl; p->display(); 
            }
            else 
            {
                cout << "\nNot found." << endl;
            }
        }
        else if (choice == 11) {
            int sId, pId;
            cout << "Staff ID: "; cin >> sId;
            cout << "Patient ID: "; cin >> pId;
            hospital.bookAppointment(sId, pId);
        }
        else if (choice == 12) {
            cout << "Patient ID: "; cin >> id;
            hospital.backupPatient(id);
        }
        else if (choice == 13) hospital.showDepartments();
        else if (choice == 14) hospital.saveData();
        else if (choice == 15) hospital.loadData();
        else if (choice == 0) {
            hospital.saveData();
            cout << "\nGoodbye." << endl;
        }
        else cout << "\nInvalid choice." << endl;
    }

    return 0;
}
