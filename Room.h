//
// Created by yuliya on 11.4.16.
//

#ifndef HOTELRESERVATION_ROOM_H
#define HOTELRESERVATION_ROOM_H
#include <string>
#include <vector>

class Room {
public:
    Room() {};
    Room(const Room&);
    Room(int, std::string, int);
    ~Room() {};
    std::string getType();
    int getId() { return roomNumber;};
    int getPrice() { return price; };
protected:
    std::vector<std::string> type = {"single", "double", "twin"};
    int price;
    int roomNumber;
    std::string typeRoom;
};

class SingleRoom: private Room {
public:
    SingleRoom(int num);
    SingleRoom(const SingleRoom&);
    ~SingleRoom() {};
    std::string getData();
private:
    SingleRoom() {};
};

class DoubleRoom: private Room {
public:
    DoubleRoom(int num);
    DoubleRoom(const DoubleRoom&);
    ~DoubleRoom() {};
    std::string getData();
private:
    DoubleRoom() {};
};
class TwinRoom: private Room {
public:
    TwinRoom(int num);
    TwinRoom(const TwinRoom&);
    ~TwinRoom() {};
    std::string getData();
private:
    TwinRoom() {};
};

#endif //HOTELRESERVATION_ROOM_H
