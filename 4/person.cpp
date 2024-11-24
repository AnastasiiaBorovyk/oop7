﻿#include "Person.h"
#include <stdexcept>

// Конструктор
Person::Person(string n, int a, int id, string s, string addr, int num)
    : name(n), age(a), ID(id), status(s), address(addr), number(num) {}

// Геттери і сеттери
string Person::getName() const { return name; }
void Person::setName(const string& name) { this->name = name; }

int Person::getAge() const { return age; }
void Person::setAge(int age) { this->age = age; }

int Person::getID() const { return ID; }
void Person::setID(int id) { ID = id; }

string Person::getStatus() const { return status; }
void Person::setStatus(const string& status) { this->status = status; }

string Person::getAddress() const { return address; }
void Person::setAddress(const string& address) { this->address = address; }

int Person::getNumber() const { return number; }
void Person::setNumber(int number) { this->number = number; }

// Інші методи
void Person::printInfo() const {
    cout << "Name: " << name
        << ", Age: " << age
        << ", ID: " << ID
        << ", Status: " << status
        << ", Address: " << address
        << ", Number: " << number << endl;
}

// Ініціалізація статичних об'єктів
Person Person::staticPersons[3] = { 
    Person("Alice", 30, 101, "Active", "123 Main St", 5551234),
    Person("Bob", 40, 102, "Inactive", "456 Elm St", 5555678),
    Person("Charlie", 25, 103, "Pending", "789 Oak St", 5559101)
};

// Ініціалізація динамічних об'єктів
Person* Person::dynamicPersons[3] = { nullptr, nullptr, nullptr };

void Person::printStaticPersons() { //завдання 10
    for (int i = 0; i < 3; ++i) {
        cout << "Static Person " << (i + 1) << ":\n";
        staticPersons[i].printInfo(); 
    }
}

void Person::createDynamicPersons() {
    try {
        dynamicPersons[0] = new Person("Kai", 28, 201, "Active", "101 Dynamic St", 5551001);
        dynamicPersons[1] = new Person("Adam", 35, 202, "Inactive", "202 Dynamic St", 5551002);
        dynamicPersons[2] = new Person("Ben", 22, 203, "Pending", "303 Dynamic St", 5551003);
    }
    catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
        for (int i = 0; i < 3; ++i) {
            delete dynamicPersons[i];
            dynamicPersons[i] = nullptr;
        }
    }
}

void Person::deleteDynamicPersons() {
    for (int i = 0; i < 3; ++i) {
        delete dynamicPersons[i];
        dynamicPersons[i] = nullptr;
    }
}

void Person::printDynamicPersons() { //завдання 10
    for (int i = 0; i < 3; ++i) {
        if (dynamicPersons[i]) {
            cout << "Dynamic Person " << (i + 1) << ":\n";
            dynamicPersons[i]->printInfo();
        }
        else {
            cout << "Dynamic Person " << (i + 1) << " is null.\n";
        }
    }
}

void Person::Service_Static(int minAge) {
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (staticPersons[i].age > minAge) {
            cout << "Static Person " << (i + 1) << " marked as inactive.\n";
            staticPersons[i].status = "Removed";
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No static persons found with age greater than the criterion.");
    }
}

void Person::Service_Dynamic(int minAge) {
    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (dynamicPersons[i] && dynamicPersons[i]->age > minAge) {
            delete dynamicPersons[i];
            dynamicPersons[i] = nullptr;
            cout << "Dynamic Person " << (i + 1) << " deleted.\n";
            found = true;
        }
    }
    if (!found) {
        throw runtime_error("No dynamic persons found with age greater than the criterion.");
    }
}

Person Person::operator+(const Person& other) const {
    string combinedName = name + " & " + other.name;
    int combinedAge = age + other.age;
    return Person(combinedName, combinedAge, ID, status, address, number);
}

Person Person::operator-(const Person& other) const {
    int ageDifference = age - other.age;
    string resultName = name + " vs " + other.name;
    return Person(resultName, max(ageDifference, 0), ID, status, address, number);
}
// Перевантаження оператора *
Person Person::operator*(int multiplier) const {
    int newAge = age * multiplier;
    return Person(name, newAge, ID, status, address, number);
}

// Перевантаження оператора =
Person& Person::operator=(const Person& other) {
    if (this == &other) return *this; // Перевірка на самоприсвоєння
    name = other.name;
    age = other.age;
    ID = other.ID;
    status = other.status;
    address = other.address;
    number = other.number;
    return *this;
}

// Перевантаження оператора +=
Person& Person::operator+=(const Person& other) {
    age += other.age;
    return *this;
}

// Перевантаження оператора -=
Person& Person::operator-=(const Person& other) {
    age -= other.age;
    if (age < 0) age = 0; // Уникнення негативного віку
    return *this;
}

// Перевантаження оператора *=
Person& Person::operator*=(int multiplier) {
    age *= multiplier;
    return *this;
}

