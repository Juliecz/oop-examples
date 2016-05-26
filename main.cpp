#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

#include "Room.h"
#include "Person.h"
#include "Reservation.h"
#include "Date.h"
#include "Hotel.h"
#include "priklady/Student.h"
#include "priklady/Cislo.h"
#include "priklady/GumovePole.h"

using namespace std;

int main() {

    //Hotel reservation system
    //tvorba pokoju v hotelu
    Hotel hotel;
    hotel.createRooms();

    //nacteni ze souboru
    vector<Reservation> reservations = hotel.reservationsToVector();
    vector<Person> guests = hotel.guestsToVector();
    vector<Room> rooms = hotel.roomsToVector();

    //vypis hlavniho menu
    hotel.mainMenu();
    int kategorie;

    while (true) {
        while (true) {
            cin >> kategorie;
            if (kategorie>0 && kategorie<8) { break;}
            else {
                //cout << "Zadejte cislo od 1 do 7\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        switch (kategorie) {
            case 1: {
                //nova rezervace
                hotel.createReservation(reservations, guests);
                hotel.mainMenu();
                break;
            }
            case 2: {
                //vypis vsech rezervaci
                hotel.getAllReservations(reservations);
                hotel.reservationMenu(reservations);
                break;
            }
            case 3: {
                //vypis vsech hostu
                hotel.getAllGuests(guests);
                hotel.guestsMenu(guests);
                break;
            }
            case 4: {
                //vyhledavani
                hotel.reservationFindMenu(reservations);
                break;
            }
            case 5: {
                int k = hotel.guestFindMenu(guests);
                break;
            }
            case 6: {
                int den, mesic, rok;
                bool valid = false;
                Date start, end;
                while (!valid) {
                    do {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\n\nZadejte data nastehovani a odstehovani\n";
                        std::cout << "Checkin (ve tvaru dd mm yyyy): ";
                        std::cin >> den >> mesic >> rok;
                    } while (std::cin.fail());
                    start.setDate(den, mesic, rok);
                    valid = start.validDate();
                }
                valid = false;
                while (!valid) {
                    do {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Checkout (ve tvaru dd mm yyyy): ";
                        std::cin >> den >> mesic >> rok;
                    } while (std::cin.fail());
                    end.setDate(den, mesic, rok);
                    valid = end.validDate();
                }
                hotel.checkAvailability(reservations, start, end, false);
                break;
            }
            case 7: {
                hotel.guestsToFile(guests);
                hotel.reservationsToFile(reservations);
                return 0;
            }
        }
    }

/*
    //Student
    Student student("Julie");
    for (int i = 0; i<30; i++) {
        int r = rand() %50 +1;
        student.zapisPredmetu(r);
    }
    cout << "\n";
    student.zapocet(19);
    student.zkouska(19, 5);
    student.zkouska(19, 2);
    student.zapocet(16);
    student.zapocet(43);
    student.zapocet(33);
    student.zkouska(33, 1);
    student.zapocet(13);
    student.zkouska(16, 4);

    student.splnenePredmety();
    //cout << "\n" << student.prumer() << "\n";
    student.vypsatSeznamPredmetu();
    Student *s = new Student("Novy");
    s->setName("MyName");
    s->getName();
    Student student1;
    vector<Student> students;
    students.push_back(student);
    students.push_back(*s);
    students.push_back(student1);
    student.save(students);
*/
    /*
    //Cislo - Cele, Realne, Komplexni
    Realne realne(4.5), realne1(78.29), realne2;
    Komplexni cislo(8.34, -77), cislo1(-32, 7.3);
    Komplexni cislo3 = cislo+cislo1;
    (cislo*cislo).vypisCisla();
    cislo3.vypisCisla();
    (realne-realne1).vypisCisla();
    (realne*realne1).vypisCisla();
    (realne/realne1).vypisCisla();
    realne2=realne;
    realne2.vypisCisla();
    cislo3 = cislo1;
    cislo3.vypisCisla();
    Cele cele(15), cele1, cele2(73);
    cele2 -= cele;
    (cele2*cele).vypisCisla();
    Komplexni komplexni(1.11, 10), komplexni1(7, 3);
    //komplexni1 *= komplexni;
    komplexni1 = komplexni*komplexni1;
    komplexni1.vypisCisla();
    */
    /*
    //Gumove pole
    GumovePole<int> pole(5);
    for (int i=0; i<18; i++) {
        pole[i] = i+1;
    }
    pole.vypis();
     *
    return 0;*/
}