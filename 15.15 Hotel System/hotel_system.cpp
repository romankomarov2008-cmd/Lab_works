#include "hotel_system.h"
#include <algorithm>
#include <iostream>

// ================= Реалізація класу Date =================

Date::Date(int day) : dayOfYear(day) {}

int Date::getDay() const { return dayOfYear; }

void Date::setDay(int day) { dayOfYear = day; }

int Date::operator-(const Date& other) const {
    return this->dayOfYear - other.dayOfYear;
}

bool Date::operator<=(const Date& other) const { return dayOfYear <= other.dayOfYear; }
bool Date::operator<(const Date& other) const { return dayOfYear < other.dayOfYear; }
bool Date::operator>=(const Date& other) const { return dayOfYear >= other.dayOfYear; }
bool Date::operator>(const Date& other) const { return dayOfYear > other.dayOfYear; }
bool Date::operator==(const Date& other) const { return dayOfYear == other.dayOfYear; }

// ================= Реалізація класу Guest =================

Guest::Guest(std::string lastName, Date checkIn, Date checkOut, int roomNumber)
    : lastName(lastName), checkIn(checkIn), checkOut(checkOut), roomNumber(roomNumber) {}

std::string Guest::getLastName() const { return lastName; }
Date Guest::getCheckIn() const { return checkIn; }
Date Guest::getCheckOut() const { return checkOut; }
int Guest::getRoomNumber() const { return roomNumber; }

// ================= Реалізація класу Hotel =================

void Hotel::addRoom(int number, double pricePerNight) {
    rooms.push_back({number, pricePerNight});
}

bool Hotel::isRoomFreeInPeriod(int roomNum, const Date& start, const Date& end) const {
    for (const auto& guest : guests) {
        if (guest.getRoomNumber() == roomNum) {
            if (guest.getCheckIn() < end && start < guest.getCheckOut()) {
                return false;
            }
        }
    }
    return true;
}

bool Hotel::addGuest(const Guest& guest) {
    bool roomExists = false;
    for (const auto& r : rooms) {
        if (r.number == guest.getRoomNumber()) {
            roomExists = true;
            break;
        }
    }
    if (!roomExists) return false;

    if (isRoomFreeInPeriod(guest.getRoomNumber(), guest.getCheckIn(), guest.getCheckOut())) {
        guests.push_back(guest);
        return true;
    }
    return false;
}

int Hotel::getFreeRoomsCountOnDate(const Date& date) const {
    int occupiedCount = 0;
    for (const auto& room : rooms) {
        for (const auto& guest : guests) {
            if (guest.getRoomNumber() == room.number) {
                if (guest.getCheckIn() <= date && date < guest.getCheckOut()) {
                    occupiedCount++;
                    break;
                }
            }
        }
    }
    return static_cast<int>(rooms.size()) - occupiedCount;
}

int Hotel::findFreeRoomInPeriod(const Date& start, const Date& end) const {
    for (const auto& room : rooms) {
        if (isRoomFreeInPeriod(room.number, start, end)) {
            return room.number;
        }
    }
    return -1;
}

double Hotel::calculateStayCost(const std::string& lastName, const Date& start, const Date& end) const {
    double totalCost = 0.0;

    for (const auto& guest : guests) {
        if (guest.getLastName() == lastName) {
            int overlapStart = std::max(guest.getCheckIn().getDay(), start.getDay());
            int overlapEnd = std::min(guest.getCheckOut().getDay(), end.getDay());

            if (overlapStart < overlapEnd) {
                int days = overlapEnd - overlapStart;
                for (const auto& room : rooms) {
                    if (room.number == guest.getRoomNumber()) {
                        totalCost += days * room.pricePerNight;
                        break;
                    }
                }
            }
        }
    }
    return totalCost;
}

int Hotel::getGuestRoomInPeriod(const std::string& lastName, const Date& start, const Date& end) const {
    for (const auto& guest : guests) {
        if (guest.getLastName() == lastName) {
            if (guest.getCheckIn() < end && start < guest.getCheckOut()) {
                return guest.getRoomNumber();
            }
        }
    }
    return -1;
}
