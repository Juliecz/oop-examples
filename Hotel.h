#ifndef HOTELRESERVATION_HOTEL_H
#define HOTELRESERVATION_HOTEL_H


#include "Reservation.h"
#include "Room.h"

class Hotel {
public:
    Hotel();
    Hotel(const Hotel&);
    Hotel(int, int, int);
    ~Hotel() {};
    void mainMenu();
    void reservationMenu(std::vector<Reservation> &);
    int reservationFindMenu(std::vector<Reservation> &);
    void guestsMenu(std::vector<Person> &);
    int guestFindMenu(std::vector<Person> &);

    std::vector<Room> roomsToVector();
    std::vector<Reservation> reservationsToVector();
    std::vector<Person> guestsToVector();

    void reservationsToFile(std::vector<Reservation> &);
    void guestsToFile(std::vector<Person> &);

    void createRooms();
    void createReservation(std::vector<Reservation> &, std::vector<Person> &);
    void getAllReservations(std::vector<Reservation> &);

    void getAllGuests(std::vector<Person> &);
    bool findPerson(std::vector<Person> &, std::string);
    bool findPerson(std::vector<Person> &, Person);

    void addToGuestList(Person &, std::vector<Person> &);
    int checkAvailability(std::vector<Reservation> &, Date, Date, bool);
    void editReservation(std::vector<Reservation> &, int);
    void findReservation(std::vector<Reservation> &, int);
    void removeReservation(std::vector<Reservation> &, int);

private:
    int singleRoom;
    int doubleRoom;
    int twinRoom;
};


#endif //HOTELRESERVATION_HOTEL_H
