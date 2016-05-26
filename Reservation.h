#ifndef HOTELRESERVATION_RESERVATION_H
#define HOTELRESERVATION_RESERVATION_H


#include "Person.h"

class Reservation {
public:
    Reservation(int, Date, Date, Person&, int);
    Reservation(int, Date, Date, std::string, std::string, int);
    Reservation(const Reservation &);
    ~Reservation() {};
    void getPerson();
    Date getStartDate();
    Date getEndDate();
    int getRoom() { return room;};
    std::string getSurname();
    int getId();

    void setRoom(int);
    void setNewDates(Date, Date);
    void setName(std::string);
    void setSurname(std::string);

    std::string showReservation();

private:
    Reservation() {};
    int id;
    Date checkin;
    Date checkout;
    Person person;
    int room;
};


#endif //HOTELRESERVATION_RESERVATION_H
