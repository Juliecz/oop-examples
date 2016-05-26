#include "Room.h"
#include <iostream>
#include <sstream>

Room::Room(const Room &pokoj) {
    this->roomNumber = pokoj.roomNumber;
    this->price = pokoj.price;
    this->typeRoom = pokoj.typeRoom;
};
Room::Room(int cislo, std::string typ, int cena) {
    roomNumber = cislo;
    typeRoom = typ;
    price = cena;
};
std::string Room::getType() {
    return typeRoom;
}
//_________________________
SingleRoom::SingleRoom(int num) {
    typeRoom = "single";
    roomNumber = num;
    price=700;
};
SingleRoom::SingleRoom(const SingleRoom &s) {
    typeRoom = s.typeRoom;
    roomNumber = s.roomNumber;
    price = s.price;
};
std::string SingleRoom::getData() {
    std::ostringstream str;
    str << roomNumber << " " << typeRoom << " " << price << "\n";
    std::string data = str.str();
    //std::cout << data;
    return data;
};

//_________________________
DoubleRoom::DoubleRoom(int num) {
    typeRoom = "double";
    roomNumber = num;
    price = 1800;
};
DoubleRoom::DoubleRoom(const DoubleRoom &d) {
    typeRoom = d.typeRoom;
    roomNumber = d.roomNumber;
    price = d.price;
}
std::string DoubleRoom::getData() {
    std::ostringstream str;
    str << roomNumber << " " << typeRoom << " " << price << "\n";
    std::string data = str.str();
    //std::cout << data;
    return data;
};

//_________________________
TwinRoom::TwinRoom(int num) {
    typeRoom = "twin";
    roomNumber = num;
    price = 2000;
};
TwinRoom::TwinRoom(const TwinRoom &t) {
    typeRoom = t.typeRoom;
    roomNumber = t.roomNumber;
    price = t.price;
};
std::string TwinRoom::getData() {
    std::ostringstream str;
    str << roomNumber << " " << typeRoom << " " << price << "\n";
    std::string data = str.str();
    //std::cout << data;
    return data;
};