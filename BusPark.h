#ifndef BUS_PARK_H
#define BUS_PARK_H

#include "Bus.cpp"
#include <vector>
#include <string>
using namespace std;

class BusPark {
private:
    vector<Bus> buses;

public:
    void addBus(const Bus& bus);
    void removeBusByNumber(const string& busNumber);
    void displayAllBuses() const;
    void findBusesByRoute(int routeNumber) const;
    void sortBusesByCapacity();
    void sortBusesByRoute();
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
