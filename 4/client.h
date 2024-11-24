#pragma once
#include <iostream> 
#include "person.h"
#include "car.h"
using namespace std;

class Client : protected Person {
private:
    int IdUser;
    int rentalPeriod;
    string orderStatus;

public:
    string clientName;

    // Оголошення конструктора з параметрами
    Client(string name, int idUser, int rentalPeriod, string orderStatus);

    // Геттери і сеттери
    string getClientName() const;
    void setClientName(const string& name);

    int getIdUser() const;
    void setIdUser(int id);

    int getRentalPeriod() const;
    void setRentalPeriod(int period);

    string getOrderStatus() const;
    void setOrderStatus(const string& status);

    void printClientInfo() const;

};