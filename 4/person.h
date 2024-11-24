#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    int age;
    int ID;
    string status;
    string address;
    int number;

public:

    virtual void printAdmInfo() const {
        cout << "Person: " << name << ", Age: " << age << ", Status: " << status << endl;
    }

    virtual void approveRequest(const string& request) const {
        cout << "Person " << name << " cannot approve requests." << endl;
    } 

    string name;

    // Конструктори
    Person(string n, int a, int id, string s, string addr, int num);
    Person() : name(""), age(0), ID(0), status(""), address(""), number(0) {}
    Person(string name, int age) : name(name), age(age), ID(0), status(""), address(""), number(0) {}

    // Геттери і сеттери
    string getName() const;
    void setName(const string& name);

    int getAge() const;
    void setAge(int age);

    int getID() const;
    void setID(int id);

    string getStatus() const;
    void setStatus(const string& status);

    string getAddress() const;
    void setAddress(const string& address);

    int getNumber() const;
    void setNumber(int number);

    virtual void printInfo() const;

    virtual ~Person() = default;

    // Статичні об'єкти
    static Person staticPersons[3];

    // Динамічні об'єкти
    static Person* dynamicPersons[3];

    // Методи для роботи зі статичними об'єктами
    static void printStaticPersons();
    static void Service_Static(int minAge);

    // Методи для роботи з динамічними об'єктами
    static void createDynamicPersons();
    static void deleteDynamicPersons();
    static void printDynamicPersons();
    static void Service_Dynamic(int minAge);

    Person operator+(const Person& other) const;
    Person operator-(const Person& other) const; 
    Person& operator=(const Person& other);
    Person& operator*=(int multiplier);
    Person& operator+=(const Person& other);
    Person& operator-=(const Person& other);

    Person operator*(int multiplier) const;
};


