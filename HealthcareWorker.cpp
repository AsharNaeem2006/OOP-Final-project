// OOP Concept: Abstract Class / Interface (pure virtual functions)
#ifndef HEALTHCAREWORKER_CPP
#define HEALTHCAREWORKER_CPP
#include <string>
using namespace std;

class HealthcareWorker {
public:
  // Pure virtual functions = abstract class (cannot create object of this class)
    virtual void display() const = 0;
    virtual string getRole() const = 0;
    virtual int getId() const = 0;
    virtual int getFee() const = 0;
    virtual ~HealthcareWorker() {}
};
#endif
