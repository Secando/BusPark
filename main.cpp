#include "BusPark.cpp"
#include "Menu.cpp"
#include "Sorter.cpp"

#include <iostream>
using namespace std;

int main() {
    BusPark park;
    int choice;

    do {
        Menu::showMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string number, driver;
                int route, capacity;
                cout << "Введите номер автобуса: ";
                cin >> number;
                cout << "Введите имя водителя: ";
                cin.ignore();
                getline(cin, driver);
                cout << "Введите номер маршрута: ";
                cin >> route;
                cout << "Введите вместимость: ";
                cin >> capacity;

                Bus newBus(number, driver, route, capacity);
                park.addBus(newBus);
                break;
            }
            case 2:
                park.displayAllBuses();
                break;

            case 3: {
                int routeNumber;
                cout << "Введите номер маршрута для поиска: ";
                cin >> routeNumber;
                park.findBusesByRoute(routeNumber);
                break;
            }
            case 4: {
                string busNumber;
                cout << "Введите номер автобуса для удаления: ";
                cin >> busNumber;
                park.removeBusByNumber(busNumber);
                break;
            }
            case 5:
                Sorter::sortBusesByCapacity(park);
                break;
            case 6:
                Sorter::sortBusesByRoute(park);
                break;
            case 7: {
                string filename;
                cout << "Введите имя файла для сохранения: ";
                cin >> filename;
                park.saveToFile(filename);
                break;
            }
            case 8: {
                string filename;
                cout << "Введите имя файла для загрузки: ";
                cin >> filename;
                park.loadFromFile(filename);
                break;
            }

            case 9:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}




