// OOP Concept: Hierarchical Inheritance (Staff has children: Doctor, Nurse)
#ifndef NURSE_CPP
#define NURSE_CPP
#include <iostream>
#include <string>
#include "Staff.cpp"
#include "HealthcareWorker.cpp"
using namespace std;

class Nurse : public Staff, public HealthcareWorker {
private:
    string ward;

public:
    Nurse(string n, int i, string dept, string w)
        : Person(n, i), Staff(n, i, dept) {
        ward = w;
    }

    void display() const override {
        cout << "  Role : Nurse" << endl;
        Staff::display();
        cout << "  Ward : " << ward << endl;
    }

    string getRole() const override { return "Nurse"; }
    int getId() const override { return Person::getId(); }
    int getFee() const override { return 500; }
};
#endif
