// OOP Concepts: Multilevel Inheritance (Person->Staff->Doctor), Interface Implementation
#ifndef DOCTOR_CPP
#define DOCTOR_CPP
#include <iostream>
#include <string>
#include "Staff.cpp"
#include "HealthcareWorker.cpp"
using namespace std;

// Doctor inherits Staff (multilevel) and implements HealthcareWorker (abstract class)
class Doctor : public Staff, public HealthcareWorker {
private:
    string specialization;

public:
    Doctor(string n, int i, string dept, string spec)
        : Person(n, i), Staff(n, i, dept) {
        specialization = spec;
    }

    string getSpecialization() const { return specialization; }

    void display() const override {
        cout << "  Role : Doctor" << endl;
        Staff::display();
        cout << "  Spec : " << specialization << endl;
    }

    string getRole() const override { return "Doctor"; }
    int getId() const override { return Person::getId(); }
    int getFee() const override { return 2000; }
};
#endif
