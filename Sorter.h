#ifndef SORTER_H
#define SORTER_H

#include "BusPark.h"

class Sorter {
public:
    static void sortBusesByCapacity(BusPark& park);
    static void sortBusesByRoute(BusPark& park);
};

#endif
