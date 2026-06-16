# 🏥 Hospital Management System

A console-based Hospital Management System developed in C++ that demonstrates core Object-Oriented Programming (OOP) concepts including inheritance, polymorphism, composition, aggregation, templates, and file handling.

## 📌 Features

- Patient Management
- Doctor Management
- Nurse Management
- Surgeon Management
- Admin Management
- Consultant Admin Operations
- Department Management
- File-Based Data Storage
- Template Functions
- Dynamic Staff Handling using Polymorphism

---

## 🏗️ OOP Concepts Used

### Inheritance
Specialized classes are derived from common base classes.

### Polymorphism
Different healthcare workers are managed through base-class pointers.

```cpp
HealthcareWorker* staff[MAX];
```

### Composition
A hospital contains departments that belong exclusively to it.

```cpp
string departments[5];
```

### Aggregation
A hospital maintains a collection of patients.

```cpp
Patient* patients[MAX];
```

### Encapsulation
Data and functions are grouped within classes to provide controlled access.

### Templates
Generic template functions are used to increase code reusability.

### File Handling
Patient and staff records can be saved and loaded using file streams.

---

## 📂 Project Structure

```text
OOP Project
│
├── main.cpp
├── Hospital.cpp
├── Person.cpp
├── Patient.cpp
├── Staff.cpp
├── HealthcareWorker.cpp
├── Doctor.cpp
├── Nurse.cpp
├── Surgeon.cpp
├── Admin.cpp
├── Consultant_Admin.cpp
└── Templates.cpp
```

---

## 🚀 Compilation & Execution

### Compile

```bash
g++ *.cpp -o HospitalMS
```

### Run

#### Windows

```bash
HospitalMS.exe
```

#### Linux / macOS

```bash
./HospitalMS
```

---

## 📖 Functionalities

- Add and View Patients
- Add and Manage Doctors
- Add and Manage Nurses
- Add and Manage Surgeons
- Administrative Operations
- Department Management
- Save and Retrieve Records from Files

---

## 🎯 Learning Objectives

This project demonstrates:

- Object-Oriented Programming in C++
- Inheritance
- Polymorphism
- Composition
- Aggregation
- Encapsulation
- Template Programming
- File Handling
- Modular Software Design

---

## 🛠️ Technologies Used

- C++
- STL (Standard Template Library)
- File Streams (`fstream`)
- Visual Studio Code

---

## 👨‍💻  Ashar Naeem

Developed as an academic Object-Oriented Programming project to demonstrate the implementation of real-world hospital management operations using C++.

⭐ Feel free to fork, improve, and contribute to this project.
