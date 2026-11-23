#ifndef HOTELSYSTEM_H
#define HOTELSYSTEM_H

#include <string>
#include <vector>

class Date {
private:
    int dayOfYear;

public:
    Date(int day = 1);
    int getDay() const;
    void setDay(int day);

    int operator-(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator==(const Date& other) const;
};

class Guest {
private:
    std::string lastName;
    Date checkIn;
    Date checkOut;
    int roomNumber;

public:
    Guest(std::string lastName, Date checkIn, Date checkOut, int roomNumber);

    std::string getLastName() const;
    Date getCheckIn() const;
    Date getCheckOut() const;
    int getRoomNumber() const;
};

struct Room {
    int number;
    double pricePerNight;
};

class Hotel {
private:
    std::vector<Room> rooms;
    std::vector<Guest> guests;

    bool isRoomFreeInPeriod(int roomNum, const Date& start, const Date& end) const;

public:
    void addRoom(int number, double pricePerNight);
    bool addGuest(const Guest& guest);

    int getFreeRoomsCountOnDate(const Date& date) const;


    int findFreeRoomInPeriod(const Date& start, const Date& end) const;

    double calculateStayCost(const std::string& lastName, const Date& start, const Date& end) const;

    int getGuestRoomInPeriod(const std::string& lastName, const Date& start, const Date& end) const;
};

#endif // HOTELSYSTEM_H
