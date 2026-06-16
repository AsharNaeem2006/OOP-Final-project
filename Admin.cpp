// OOP Concept: Single Inheritance (Admin inherits only from Person)
#ifndef ADMIN_CPP
#define ADMIN_CPP
#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

// virtual public Person -> used again in ConsultantAdmin for diamond problem
class Admin : virtual public Person {
private:
    string office;

public:
    Admin(string n, int i, string off) : Person(n, i) {
        office = off;
    }

    string getOffice() const { return office; }

    void display() const override {
        cout << "  Role : Admin" << endl;
        Person::display();
        cout << "  Office : " << office << endl;
    }
};
#endif
