// OOP Concept: Multiple Inheritance (Doctor + Admin), Diamond Problem solved by virtual Person
#ifndef CONSULTANT_ADMIN_CPP
#define CONSULTANT_ADMIN_CPP
#include <iostream>
#include <string>
#include "Admin.cpp"
#include "Doctor.cpp"
using namespace std;

// Inherits from two classes: Doctor and Admin
class ConsultantAdmin : public Doctor, public Admin {
public:
    // Person(n,i) called once -> virtual inheritance prevents duplicate Person object
    ConsultantAdmin(string n, int i, string dept, string spec, string office)
        : Person(n, i), Doctor(n, i, dept, spec), Admin(n, i, office) {}

    void display() const override {
        Doctor::display();
        cout << "  Office : " << getOffice() << endl;
        cout << "  Note   : Consultant with admin duties" << endl;
    }

    string getRole() const override { return "Consultant Admin"; }
    int getId() const override { return Person::getId(); }
    int getFee() const override { return 3500; }
};
#endif
