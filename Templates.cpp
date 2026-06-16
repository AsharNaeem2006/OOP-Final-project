#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream> // For NULL or nullptr

// OOP Concept: Function Template
// One simple template - searches any record by ID
template <class T>
T* searchById(T* arr[], int size, int id) {
    for (int i = 0; i < size; i++) {
        // Assumes that whatever class 'T' is passed has a getId() method
        if (arr[i]->getId() == id) {
            return arr[i];
        }
    }
    return nullptr; // In modern C++, 'nullptr' is preferred over 'NULL'
}

#endif