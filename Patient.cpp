// OOP Concepts: Deep Copy, Constructor, Destructor, Inheritance
#ifndef PATIENT_CPP
#define PATIENT_CPP
#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

class Patient : public Person {
private:
    string* medicalHistory;  // pointer member needs deep copy

public:
    // Constructor
    Patient(string n, int i, string history) : Person(n, i) {
        medicalHistory = new string(history);
    }

    // Deep Copy Constructor: used when creating patient backup records
    // Without this, copy would be shallow (both objects share same pointer)
    Patient(const Patient& other) : Person(other) {
        medicalHistory = new string(*other.medicalHistory);
    }

    string getMedicalHistory() const { return *medicalHistory; }

    void display() const override {
        cout << "  Role : Patient" << endl;
        Person::display();
        cout << "  History : " << *medicalHistory << endl;
    }

    ~Patient() {
        delete medicalHistory;
    }
};
#endif
