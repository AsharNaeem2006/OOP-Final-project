// OOP Concepts: Encapsulation, Constructor, Destructor, Polymorphism (virtual function)
#ifndef PERSON_CPP
#define PERSON_CPP
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    // Encapsulation: data is hidden, accessed only through public functions
    string name;
    int id;

public:
    // Default Constructor
    Person() {
        name = "";
        id = 0;
    }

    // Parameterized Constructor
    Person(string n, int i) {
        name = n;
        id = i;
    }

    // Getters (Encapsulation)
    string getName() const { return name; }
    int getId() const { return id; }

    // Polymorphism: virtual function overridden in child classes
    virtual void display() const {
        cout << "  Name : " << name << endl;
        cout << "  ID   : " << id << endl;
    }

    // Virtual Destructor: ensures correct destructor runs in inheritance
    virtual ~Person() {}
};
#endif
