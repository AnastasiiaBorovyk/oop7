#include <iostream>
#include<fstream>
#include <cstring>
#include "car.h"
#include "admin.h"
#include "client.h"
#include "electroCar.h"
#include "order.h"
#include"TemplatePerson.h" 
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//void printAbc(Car* c) {
//    c->abc();
//}

void printAdminInfo(Person* p) {
    p->printInfo(); // Поліморфний виклик
}

void processRequest(Person* p, const string& request) {
    p->approveRequest(request); // Поліморфний виклик
}




void displayMenu() {
    cout << "\n==== MENU ====\n";
    cout << "1. Show static persons\n";
    cout << "2. Show dynamic persons\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void Service(Person& person, const string& filename, bool writeMode) {
    try {
        if (writeMode) {
            // Запис у файл
            ofstream file(filename, ios::out | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for writing.");
            }

            file << person.getName() << endl
                << person.getAge() << endl
                << person.getID() << endl
                << person.getStatus() << endl
                << person.getAddress() << endl
                << person.getNumber() << endl;

            if (file.fail()) {
                throw runtime_error("Error occurred while writing to file.");
            }

            file.close();
            cout << "Data written to file successfully." << endl;
        }
        else {
            // Читання з файлу
            ifstream file(filename, ios::in | ios::binary);
            if (!file.is_open()) {
                throw runtime_error("Failed to open file for reading.");
            }

            string name, status, address;
            int age, id, number;

            if (!(getline(file, name) && file >> age && file >> id && file.ignore() &&
                getline(file, status) && getline(file, address) && file >> number)) {
                throw runtime_error("Invalid data format in file.");
            }

            if (file.fail()) {
                throw runtime_error("Error occurred while reading from file.");
            }

            file.close();

            // Оновлення даних об'єкта
            person.setName(name);
            person.setAge(age);
            person.setID(id);
            person.setStatus(status);
            person.setAddress(address);
            person.setNumber(number);

            cout << "Data read from file successfully." << endl; 
        }
    }
    catch (const exception& e) {
        cerr << "Service error: " << e.what() << endl;
        throw;
    }
}

int main() {
    list<Client> clientList = {
        Client("Mark", 1, 7, "Active"),
        Client("Akira", 2, 14, "Pending"),
        Client("Nana", 3, 3, "Completed")
    };

    cout << "Clients list:\n";
    for (const auto& client : clientList) {
        client.printClientInfo();
    }

    // Алгоритм 1: Видалення Completed через ручний ітератор
    for (auto it = clientList.begin(); it != clientList.end();) {
        if (it->getOrderStatus() == "Completed") {
            it = clientList.erase(it); // erase повертає новий ітератор
        }
        else {
            ++it;
        }
    }

    cout << "\nUpdated clients list (after manual removal):\n";
    for (const auto& client : clientList) {
        client.printClientInfo();
    }

    // Вектор клієнтів
    vector<Client> clientVector = {
        Client("Momorin", 4, 5, "Confirmed"),
        Client("Kira", 5, 3, "Pending"),
        Client("Charlie", 6, 7, "Completed")
    };

    // Алгоритм 2: Ітерація та виконання операції без std::for_each
    cout << "\nIterating over vector:\n";
    for (const auto& client : clientVector) {
        client.printClientInfo();
    }

    // Видалення елементів з вектора
    for (size_t i = 0; i < clientVector.size(); ) {
        if (clientVector[i].getOrderStatus() == "Completed") {
            clientVector.erase(clientVector.begin() + i); // Видалення за індексом
        }
        else {
            ++i;
        }
    }

    cout << "\nUpdated clients vector (after manual removal):\n";
    for (const auto& client : clientVector) {
        client.printClientInfo();
    }

    return 0;
}