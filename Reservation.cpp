#include <iostream>
#include <sstream>
#include "Reservation.h"
#include "Date.h"

Reservation::Reservation(int num, Date start, Date end, Person &p, int cisloPokoje) {
    person.setName(p.getName());
    person.setSurname(p.getSurname());
    person.setPhone(p.getPhone());
    person.setEmail(p.getEmail());
    room = cisloPokoje;
    id = num;

    if(end<start) {
        //Vymenit data
        Date tmp;
        tmp = start;
        start = end;
        end = tmp;
    }
    checkin.setDate(start.getDay(), start.getMonth(), start.getYear());
    checkout.setDate(end.getDay(), end.getMonth(), end.getYear());
};
Reservation::Reservation(int num, Date start, Date end, std::string jmeno, std::string prijmeni, int pokoj) {
    person.setName(jmeno);
    person.setSurname(prijmeni);
    id = num;
    room = pokoj;
    //Vymenit data
    if(end<start) {
        Date tmp;
        tmp = start;
        start = end;
        end = tmp;
    }
    checkin.setDate(start.getDay(), start.getMonth(), start.getYear());
    checkout.setDate(end.getDay(), end.getMonth(), end.getYear());
};
Reservation::Reservation(const Reservation &rezervace) {
    this->checkin = rezervace.checkin;
    this->checkout = rezervace.checkout;
    this->id = rezervace.id;
    this->person = rezervace.person;
    this->room = rezervace.room;
};
void Reservation::getPerson() {
    person.getPerson();
};
Date Reservation::getStartDate() {
    //checkin.getDate();
    return checkin;
};
Date Reservation::getEndDate() {
    //checkout.getDate();
    return checkout;
};
int Reservation::getId() { return id; };
void Reservation::setRoom(int num) {
    room = num;
};
std::string Reservation::getSurname() {
    return person.getSurname();
};
void Reservation::setNewDates(Date start, Date end) {
    this->checkin = start;
    this->checkout = end;
};
void Reservation::setName(std::string jmeno) {
    person.setName(jmeno);
};
void Reservation::setSurname(std::string prijmeni) {
    person.setSurname(prijmeni);
};
std::string Reservation::showReservation() {
    std::ostringstream str;
    str << id << " " << person.getSurname() << " " << person.getName() << " " << checkin.showDate() << " " << checkout.showDate() << " " << room;
    std::string output = str.str();
    return output;
};