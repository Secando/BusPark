#ifndef BUS_H
#define BUS_H

#include <string>
#include <iostream>
using namespace std;

class Bus {
private:
    string busNumber;
    string driverName;
    int routeNumber;
    int capacity;

public:
    Bus(string number, string driver, int route, int cap);
    
    string getBusNumber() const;
    string getDriverName() const;
    int getRouteNumber() const;
    int getCapacity() const;

    void displayInfo() const;
    void saveToFile(ofstream& outFile) const;
    static Bus loadFromFile(ifstream& inFile);
};

#endif
