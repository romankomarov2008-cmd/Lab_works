#include <iostream>
#include "hotel_system.h"

int main() {
    Hotel hotel;

    hotel.addRoom(101, 1200.0);
    hotel.addRoom(102, 1500.0);
    hotel.addRoom(201, 2500.0);

    hotel.addGuest(Guest("Kovalenko", Date(10), Date(15), 101)); // z 10 po 15 sichnia (5 nochei)
    hotel.addGuest(Guest("Shevchenko", Date(12), Date(20), 102)); // z 12 po 20 sichnia (8 nochei)
    hotel.addGuest(Guest("Bondarenko", Date(16), Date(19), 101)); // z 16 po 19 sichnia (3 nochi)

    std::cout << "=== HOTEL SYSTEM TESTING ===\n\n";

    Date checkDate(13);
    std::cout << "1. Number of rooms on " << checkDate.getDay() << "-day of a year: "
              << hotel.getFreeRoomsCountOnDate(checkDate) << " (Expected: 1)\n\n";

    Date searchStart(11), searchEnd(14);
    int freeRoom = hotel.findFreeRoomInPeriod(searchStart, searchEnd);
    std::cout << "2. Free room from " << searchStart.getDay() << " to " << searchEnd.getDay() << " the day: ";
    if (freeRoom != -1) {
        std::cout << "Number " << freeRoom << " (Expected: 201)\n\n";
    } else {
        std::cout << "No free rooms\n\n";
    }

    Date costStart(14), costEnd(18);
    double cost = hotel.calculateStayCost("Shevchenko", costStart, costEnd);
    std::cout << "3. Cost of living for 'Shevchenko' for the period ["
              << costStart.getDay() << " - " << costEnd.getDay() << "]: "
              << cost << " hrn (Expected: 6000 hrn)\n\n";

    Date findGuestStart(15), findGuestEnd(17);
    int guestRoom = hotel.getGuestRoomInPeriod("Bondarenko", findGuestStart, findGuestEnd);
    std::cout << "4. Guest 'Bondarenko' has a room for the period ["
              << findGuestStart.getDay() << " - " << findGuestEnd.getDay() << "]: ";
    if (guestRoom != -1) {
        std::cout << "Number " << guestRoom << " (Expected: 101)\n";
    } else {
        std::cout << "Guest not found in this period\n";
    }

    return 0;
}