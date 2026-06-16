// OOP Concept: Multilevel Inheritance (Person->Staff->Doctor->Surgeon)
#ifndef SURGEON_CPP
#define SURGEON_CPP
#include <iostream>
#include <string>
#include "Doctor.cpp"
using namespace std;

class Surgeon : public Doctor {
private:
    string surgeryType;

public:
    Surgeon(string n, int i, string dept, string spec, string type)
        : Person(n, i), Doctor(n, i, dept, spec) {
        surgeryType = type;
    }

    void display() const override {
        Doctor::display();
        cout << "  Surgery Type : " << surgeryType << endl;
    }

    string getRole() const override { return "Surgeon"; }
    int getId() const override { return Person::getId(); }
    int getFee() const override { return 5000; }
};
#endif
