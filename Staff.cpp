// OOP Concepts: Virtual Inheritance, Deep Copy, Constructor, Destructor
#ifndef STAFF_CPP
#define STAFF_CPP
#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

// virtual public Person -> solves diamond problem in multiple inheritance
class Staff : virtual public Person {
private:
    string* department;  

public:
    Staff(string n, int i, string dept) : Person(n, i) {
        department = new string(dept);
    }

    // Deep Copy Constructor: creates new memory instead of copying pointer (shallow copy)
    Staff(const Staff& other) : Person(other) {
        department = new string(*other.department);
    }

    string getDepartment() const { return *department; }

    // override: Polymorphism
    void display() const override {
        Person::display();
        cout << "  Dept : " << *department << endl;
    }

    // Destructor: frees dynamically allocated memory
    ~Staff() {
        delete department;
    }
};
#endif
