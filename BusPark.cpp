#include "BusPark.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void BusPark::addBus(const Bus& bus) {
    buses.push_back(bus);
    cout << "Автобус добавлен успешно!\n";
}

void BusPark::removeBusByNumber(const string& busNumber) {
    auto it = remove_if(buses.begin(), buses.end(), [&](const Bus& bus) {
        return bus.getBusNumber() == busNumber;
    });

    if (it != buses.end()) {
        buses.erase(it, buses.end());
        cout << "Автобус с номером " << busNumber << " удалён.\n";
    } else {
        cout << "Автобус с номером " << busNumber << " не найден.\n";
    }
}

void BusPark::displayAllBuses() const {
    if (buses.empty()) {
        cout << "В автобусном парке нет автобусов.\n";
        return;
    }
    for (const auto& bus : buses) {
        bus.displayInfo();
    }
}

void BusPark::findBusesByRoute(int routeNumber) const {
    bool found = false;
    for (const auto& bus : buses) {
        if (bus.getRouteNumber() == routeNumber) {
            bus.displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "Автобусы с маршрутом № " << routeNumber << " не найдены.\n";
    }
}

void BusPark::sortBusesByCapacity() {
    sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
        return a.getCapacity() > b.getCapacity();
    });
    cout << "Автобусы отсортированы по вместимости.\n";
}

void BusPark::sortBusesByRoute() {
    sort(buses.begin(), buses.end(), [](const Bus& a, const Bus& b) {
        return a.getRouteNumber() < b.getRouteNumber();
    });
    cout << "Автобусы отсортированы по номеру маршрута.\n";
}

void BusPark::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Ошибка при открытии файла для сохранения.\n";
        return;
    }
    outFile << buses.size() << "\n";
    for (const auto& bus : buses) {
        bus.saveToFile(outFile);
    }
    cout << "Данные автобусного парка сохранены в файл \"" << filename << "\".\n";
}

void BusPark::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Ошибка при открытии файла для загрузки.\n";
        return;
    }
    size_t busCount;
    inFile >> busCount;
    inFile.ignore();
    buses.clear();
    for (size_t i = 0; i < busCount; ++i) {
        buses.push_back(Bus::loadFromFile(inFile));
    }
    cout << "Данные автобусного парка загружены из файла \"" << filename << "\".\n";
}
