#include "Bus.h"
#include <fstream>
#include <iostream>
using namespace std;

Bus::Bus(string number, string driver, int route, int cap)
    : busNumber(number), driverName(driver), routeNumber(route), capacity(cap) {}

string Bus::getBusNumber() const { return busNumber; }
string Bus::getDriverName() const { return driverName; }
int Bus::getRouteNumber() const { return routeNumber; }
int Bus::getCapacity() const { return capacity; }

void Bus::displayInfo() const {
    cout << "\nАвтобус №: " << busNumber
         << "\nВодитель: " << driverName
         << "\nМаршрут: " << routeNumber
         << "\nВместимость: " << capacity << "\n";
}

void Bus::saveToFile(ofstream& outFile) const {
    outFile << busNumber << "\n" << driverName << "\n" << routeNumber << "\n" << capacity << "\n";
}

Bus Bus::loadFromFile(ifstream& inFile) {
    string number, driver;
    int route, cap;
    getline(inFile, number);
    getline(inFile, driver);
    inFile >> route >> cap;
    inFile.ignore();
    return Bus(number, driver, route, cap);
}

