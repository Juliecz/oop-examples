#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <limits>
#include "Hotel.h"
#include "Room.h"
#include "Date.h"
#include "Person.h"
#include "Reservation.h"

Hotel::Hotel() {
     singleRoom = 5;
     doubleRoom = 5;
     twinRoom = 5;
 };
Hotel::Hotel(const Hotel &hotel) {
    this->singleRoom = hotel.singleRoom;
    this->doubleRoom = hotel.doubleRoom;
    this->twinRoom = hotel.twinRoom;
}
Hotel::Hotel(int s, int d, int t) {
    singleRoom = s;
    doubleRoom = d;
    twinRoom = t;
};
void Hotel::mainMenu() {
    std::cout << "\n\nHOTEL RESERVATION SYSTEM\n\n";
    std::cout << "Vyberte kategorii:\n";
    std::cout << " 1.Pridat rezervaci\n";
    std::cout << " 2.Seznam vsech rezervaci\n";
    std::cout << " 3.Seznam vsech hostu\n";
    std::cout << " 4.Najit rezervaci\n";
    std::cout << " 5.Najit hoste\n";
    std::cout << " 6.Kontrola obsazenosti dle data\n";
    std::cout << " 7.Konec\n\n";
};
int Hotel::reservationFindMenu(std::vector<Reservation> &reserv) {
    int c;
    std::cout << "Najit rezervaci podle: \n";
    std::cout << "1. Data\n";
    std::cout << "2. Prijmeni\n";
    std::cout << "3. Cisla pokoje\n";
    std::cout << "4. Hlavni menu\n\n";
    while (true) {
        std::cin >> c;
        if(c>0 && c<5) {
            break;
        }
        else {
            std::cout << "Zadejte cislo od 1 do 4\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    findReservation(reserv, c);
    return c;
};
void Hotel::reservationMenu(std::vector<Reservation> & reservations) {
    std::cout << "\n\nVyberte akci \n\n";
    std::cout << "1. Upravit data rezervaci\n";
    std::cout << "2. Smazat rezervaci\n";
    std::cout << "3. Najit jine rezervace\n";
    std::cout << "4. Hlavni menu\n";
    int k, id;
    while (true) {
        std::cin >> k;
        if(k>0 && k<5) {
            break;
        }
        else {
            std::cout << "Zadejte cislo od 1 do 4\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    switch(k) {
        case 1: {
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Zadejte ID rezervaci\n";
                std::cin >> id;
            } while (std::cin.fail());
            this->editReservation(reservations, id);
            break;
        }
        case 2: {
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Zadejte ID rezervaci\n";
                std::cin >> id;
            } while (std::cin.fail());
            this->removeReservation(reservations, id);
            this->mainMenu();
            break;
        }
        case 3: {
            int k = this->reservationFindMenu(reservations);
            //this->reservationMenu(reservations);
            break;
        }
        case 4: {
            this->mainMenu();
            break;
        }
        //todo
    }

};
int Hotel::guestFindMenu(std::vector<Person> &person) {
    int c;
    bool k = false;
    std::cout << "Najit hoste podle: \n";
    std::cout << "1. Prijmeni\n";
    std::cout << "2. Telefoniho cisla\n";
    std::cout << "3. Email\n";
    std::cout << "4. Seznam vsech hostu\n";
    std::cout << "5. Hlavni menu\n";
    std::cin >> c;
    while (std::cin.fail() || c<1 || c>5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Zadejte cislo od 1 do 5\n";
        std::cin >> c;
    }
    if (c==5) {
        k = true;
        this->mainMenu();
    }
    else if (c==4) {
        k= true;
        this->getAllGuests(person);
        this->guestsMenu(person);
    }
    else {
        std::string val;
        std::vector<Person>::iterator it;
        if (c == 1) {
            std::cout << "\nZadejte prijmeni hoste: ";
            std::cin >> val;
            for (it = person.begin(); it != person.end(); ++it) {
                if (val == it->getSurname()) {
                    it->getPerson();
                    k = true;
                }
            }
            if (k) {
                this->guestsMenu(person);
            }
        }
        else if (c == 2) {
            std::cout << "\nZadejte telefoni cislo hoste: ";
            std::cin >> val;
            for (it = person.begin(); it != person.end(); ++it) {
                if (val == it->getPhone()) {
                    it->getPerson();
                    k = true;
                    this->guestsMenu(person);
                    break;
                }
            }
        }
        else if (c == 3) {
            std::cout << "\nZadejte email hoste: ";
            std::cin >> val;
            for (it = person.begin(); it != person.end(); ++it) {
                if (val == it->getEmail()) {
                    it->getPerson();
                    k = true;
                    this->guestsMenu(person);
                    break;
                }
            }
        }
    }
    if(!k) {
        std::cout << "\nZadny host nebyl nalezen\n";
        this->mainMenu();
    }
    return c;
};
void Hotel::guestsMenu(std::vector<Person> &person) {
    std::cout << "\n\nVyberte akci \n\n";
    std::cout << "1. Upravit osobni udaje hoste\n";
    std::cout << "2. Hlavni menu\n";
    int k;
    std::string jm, pr;
    do {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> k;
    } while (std::cin.fail() || k<1 || k>2);
    switch (k) {
        case 1: {
            std::cout << "\nVyberte: \n1. Zmena telefoniho cisla\n";
            std::cout << "2. Zmena email\n";
            std::cout << "3. Hlavni menu\n";
            int v;
            bool k = false;
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> v;
            } while (std::cin.fail() || v<1 || v>3);
            if (v!=3) {
                std::cout << "\nZadejte jmeno a prijmeni hoste\n";
                std::cin >> jm >> pr;
                std::vector<Person>::iterator it;
                for (it = person.begin(); it != person.end(); ++it) {
                    if (jm == it->getName() && pr == it->getSurname()) {
                        k = true;
                        if (v == 1) {
                            std::cout << "\nZadejte nove telefoni cislo:\n";
                            std::string tel;
                            std::cin >> tel;
                            it->setPhone(tel);
                            std::cout << "ID Jmeno Prijmeni Checkin Chekout Cislo pokoje\n";
                            it->getPerson();
                            this->mainMenu();
                        }
                        else if (v == 2) {
                            std::cout << "\nZadejte novy email:\n";
                            std::string email;
                            std::cin >> email;
                            it->setEmail(email);
                            std::cout << "ID Jmeno Prijmeni Checkin Chekout Cislo pokoje\n";
                            it->getPerson();
                            this->mainMenu();
                        }
                        else if (v == 3) { this->mainMenu(); }
                        break;
                    }
                }
            }
            if (!k) {
                if (v!=3) {
                    std::cout << "\nZadny host nebyl nalezen\n";
                }
                this->mainMenu();
            }
            break;
        }
        case 2: {
            this->mainMenu();
            break;
        }
    }
};
void Hotel::createRooms() {
    std::vector<SingleRoom> singleV;
    std::fstream file;
    file.open("rooms.txt", std::ios_base::out);

    for (int i=0; i<singleRoom; i++) {
        SingleRoom singleRoom1(i+1);
        singleV.push_back(singleRoom1);
        file << singleV[i].getData();
    }
    file.close();

    std::vector<DoubleRoom> doubleV;
    file.open("rooms.txt", std::ios_base::app | std::ios_base::in | std::ios_base::out);

    for (int i=0; i<doubleRoom; i++) {
        DoubleRoom dRoom(i+1+singleRoom);
        doubleV.push_back(dRoom);
        doubleV[i].getData();
        file << doubleV[i].getData();
    }
    file.close();

    std::vector<TwinRoom> t;
    file.open("rooms.txt", std::ios_base::app | std::ios_base::in | std::ios_base::out);

    for (int i=0; i<twinRoom; i++) {
        TwinRoom tRoom(i+1+singleRoom+doubleRoom);
        t.push_back(tRoom);
        file << t[i].getData();
    }
    file.close();
};

void Hotel::addToGuestList(Person &person, std::vector<Person> &guests) {
    //check: if guest is not exist add to guests list
    bool k = this->findPerson(guests, person);
    if (!k) {
        guests.push_back(person);
    }
};

//from vector to file_______________
void Hotel::reservationsToFile(std::vector<Reservation> &reservations) {
    int i=1;
    std::vector<Reservation>::iterator it;
    std::fstream fileReservations;
    fileReservations.open("reservations.txt", std::ios_base::trunc | std::ios_base::out);
    for (it = reservations.begin(); it != reservations.end(); ++it) {
        fileReservations << " " << it->showReservation() << "\n";
        i++;
    }
};
void Hotel::guestsToFile(std::vector<Person> &guests) {
    std::vector<Person>::iterator it;
    std::fstream file;
    file.open("guests.txt", std::ios_base::trunc | std::ios_base::out);
    for (it = guests.begin(); it != guests.end(); ++it) {
        file << it->getName() << " " << it->getSurname() << " " << it->getPhone() << " " << it->getEmail() << " " << it->getBirthday() << "\n";
    }
};
//from file to vector___________________
std::vector<Reservation> Hotel::reservationsToVector() {
    std::fstream file;
    int id, cisloPokoje;
    std::string jmeno, prijmeni, checkin, checkout;
    std::vector<Reservation> reservations;
    file.open("reservations.txt", std::ios_base::in);
    while(file >> id >> prijmeni >> jmeno >> checkin >> checkout >> cisloPokoje) {
        char s[checkin.length()],e[checkout.length()];
        strcpy(s, checkin.c_str());
        strcpy(e, checkout.c_str());
        Date start(s), end(e);
        Reservation r(id, start, end, jmeno, prijmeni, cisloPokoje);
        reservations.push_back(r);
    }
    file.close();
    return reservations;
};
std::vector<Room> Hotel::roomsToVector() {
    std::fstream file;
    std::vector<Room> rooms;
    file.open("rooms.txt", std::ios_base::in);
    std::string typ;
    int cislo, cena;
    while(file >> cislo >> typ >> cena) {
        Room r(cislo, typ, cena);
        rooms.push_back(r);
    }
    return  rooms;
};
std::vector<Person> Hotel::guestsToVector() {
    std::fstream file;
    std::vector<Person> guests;
    file.open("guests.txt", std::ios_base::in);
    std::string jmeno, prijmeni, tel, email, dNarozeni;
    while(file >> jmeno >> prijmeni >> tel >> email >> dNarozeni) {
        char d[dNarozeni.length()];
        strcpy(d, dNarozeni.c_str());
        Date date(d);
        Person person(jmeno, prijmeni, tel, email, date);
        guests.push_back(person);
    }
    return guests;
};
//_____________________________

void Hotel::createReservation(std::vector<Reservation> &rezervace, std::vector<Person> &guests) {
    std::string n, s, tel, email;
    int den, mesic, rok;
    std::cout << "Zadejte jmeno a prijmeni nastevnika \n";
    std::cin >> n >> s;

    std::cout << "Telefoni cislo, email navstevnika \n";
    std::cin >> tel >> email;

    bool valid = false;
    Person person;
    while (!valid) {
        do {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Zadejte datum narozeni navstevnika ve tvaru dd mm yyyy ";
            std::cin >> den >> mesic >> rok;
        } while (std::cin.fail());

        Date date(den, mesic, rok);
        if (date.validDate()) {
            valid= true;
            Person person1(n, s, tel, email, date);
            person = person1;
            //add to guests.txt
            this->addToGuestList(person, guests);
        }
    }

    valid = false;
    Date checkin, checkout, now;
    while (!valid) {
        do {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Zadejte datum nastehovani ve tvaru dd mm yyyy ";
            std::cin >> den >> mesic >> rok;
        } while (std::cin.fail());

        checkin.setDate(den, mesic, rok);
        if (checkin.validDate() && now <= checkin) { valid = true; }
    }
    valid = false;
    while (!valid) {
        do {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Zadejte datum odstehovani ve tvaru dd mm yyyy ";
            std::cin >> den >> mesic >> rok;
        } while (std::cin.fail());

        checkout.setDate(den, mesic, rok);
        if (checkout.validDate()&& now <= checkout) { valid = true; }
    }
    int room = this->checkAvailability(rezervace, checkin, checkout, true);
    int id = rezervace.back().getId() + 1; //reservation id
    Reservation reservation1(id, checkin, checkout, person, room);
    std::cout << "Byla vytvorena rezervace: \n\n";
    std::cout << "ID Prijmeni Jmeno Checkin Chekout Cislo pokoje\n";
    std::cout << reservation1.showReservation() << "\n\n";
    //put to reservation list
    rezervace.push_back(reservation1);

};

void Hotel::getAllReservations(std::vector<Reservation> &rezervace) {
    std::vector<Reservation>::iterator it; //
    for (it = rezervace.begin(); it!=rezervace.end(); ++it) {
        std::cout << it->showReservation() << "\n";
    }
};

void Hotel::getAllGuests(std::vector<Person> &guests) {
    std::vector<Person>::iterator it;
    std::cout << "\n\n";
    for (it = guests.begin(); it!=guests.end(); it++) {
        std::cout << it->getName() << " " << it->getSurname() << " " << it->getPhone() << " " << it->getEmail() << " " << it->getBirthday() << "\n";
    }
};
bool Hotel::findPerson(std::vector<Person> &guests, std::string text) {
    std::vector<Person>::iterator it;
    //std::cout << "Jmeno \t\tPrijmeni \t\tTel. cislo \t\tEmail \t\tDatum narozeni \n";
    for (it = guests.begin(); it!=guests.end(); it++) {
        if (text == it->getSurname()) {
            //todo show
            it->getPerson();
            //std::cout << it->getName() << " \t\t" << it->getSurname() << " \t\t" << it->getPhone() << " \t\t" <<
            //it->getEmail() << " \t\t" << it->getBirthday() << "\n";
            return true;
        }
    }
};

bool Hotel::findPerson(std::vector<Person> &guests, Person person) {
    std::vector<Person>::iterator it;
    for (it = guests.begin(); it!=guests.end(); it++) {
        if (person.getSurname() == it->getSurname() && person.getName() == it->getName()) {
            //todo vypsat
            //it->getPerson();
            return true;
        }
    }
    return false;
};

int Hotel::checkAvailability(std::vector<Reservation> &reservations, Date start, Date end, bool v) {
    int id;
    std::fstream file;
    file.open("rooms.txt", std::ios_base::in);
    std::vector<Reservation>::iterator itRezerv;
    int n, c;
    std::string t;
    if(end<start) {
        Date tmp;
        tmp = start;
        start = end;
        end = tmp;
    }
    while(file >> n >> t >> c) {
        //check each room
        bool free;
        for(itRezerv = reservations.begin(); itRezerv!=reservations.end(); itRezerv++) {
            if (n == itRezerv->getRoom()) {
                //check dates
                Date d1 = itRezerv->getStartDate(), d2 = itRezerv->getEndDate();
                if (end < d1 || (start >= d2 && d2 < end && d1 < start)) {
                    free = true;
                }
                else {
                    free = false;
                    break;
                }
            }
        }
        if (free) { std::cout << n << " " << t << " " << c << "\n" ; }

    }
    if (v) {
        do {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Vyberte cislo pokoje ze seznamu volnych pokoju\n";
            std::cin >> id;
        } while (std::cin.fail());
    }
    else {
        this->mainMenu();
    }
    return id;
};

void Hotel::editReservation(std::vector<Reservation> &reservations, int id) {
    std::vector<Reservation>::iterator it;
    int pocet=0;
    for(it = reservations.begin(); it!=reservations.end(); ++it) {
        if(id==it->getId()) {
            std::cout << it->showReservation() << "\n";
            //zadat udaje
            int den, mesic, rok;
            bool valid = false;
            Date start, end;
            while (!valid) {

                do {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n\nZadejte nova data nastehovani a odstehovani\n";
                    std::cout << "Checkin (ve tvaru dd mm yyyy): ";
                    std::cin >> den >> mesic >> rok;
                } while (std::cin.fail());

                start.setDate(den, mesic, rok);
                if (start.validDate()) { valid = true;}
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
                if (end.validDate()) { valid = true;}
            }
            //Vymenit data
            if(end<start) {
                Date tmp;
                tmp = start;
                start = end;
                end = tmp;
            }
            it->setNewDates(start, end);
            std::cout << it->showReservation() << "\n";
            this->mainMenu();
            break;
        }
        else { pocet++;}
    }
    if (pocet==reservations.size()) {
        std::cout << "Zadna rezervace nebyla nalezena\n";
        this->mainMenu();
    }
};
void Hotel::findReservation(std::vector<Reservation> &reservations, int k) {
    int a=0;
    bool b = false;
    std::vector<Reservation>::iterator it;
    //todo
    switch (k) {
        case 1: {
            a=0;
            int den, mesic, rok;
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Zadejte datum ve tvaru dd mm yyyy\n";
                std::cin >> den >> mesic >> rok;
            } while (std::cin.fail());

            Date find(den, mesic, rok);
            for(it = reservations.begin(); it!=reservations.end(); ++it) {
                Date start = it->getStartDate(), end = it->getEndDate();
                if (find >= start && find <= end) {
                    a++;
                    b=true;
                    if (a==1) { std::cout << "ID Prijmeni Jmeno Checkin Chekout Cislo pokoje\n"; }
                    std::cout << it->showReservation() << "\n";
                }
            }
            if (!b) {
                std::cout << "Zadna rezervace nebyla nalezena\n";
                this->mainMenu();
            }
            else {
                this->reservationMenu(reservations);
            }
            break;
        }
        case 2: {
            a=0;
            std::string prijmeni;
            std::cout << "Zadejte prijmeni\n";
            std::cin >> prijmeni;
            for(it = reservations.begin(); it!=reservations.end(); ++it) {
                if( prijmeni == it->getSurname()) {
                    a++;
                    b=true;
                    if (a==1) { std::cout << "ID Prijmeni Jmeno Checkin Chekout Cislo pokoje\n"; }
                    std::cout << it->showReservation() << "\n";
                }
            }
            if (!b) {
                std::cout << "Zadna rezervace nebyla nalezena\n";
                this->mainMenu();
            }
            else {
                this->reservationMenu(reservations);
            }
            break;
        }
        case 3: {
            a=0;
            int pokoj;
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Zadejte cislo pokoje\n";
                std::cin >> pokoj;
            } while (std::cin.fail());

            for(it = reservations.begin(); it!=reservations.end(); ++it) {
                if( pokoj == it->getRoom()) {
                    a++;
                    b=true;
                    if (a==1) { std::cout << "ID Prijmeni Jmeno Checkin Chekout Cislo pokoje\n"; }
                    std::cout << it->showReservation() << "\n";
                }
            }
            if (!b) {
                std::cout << "Zadna rezervace nebyla nalezena\n";
                this->mainMenu();
            }
            else {
                this->reservationMenu(reservations);
            }
            break;
        }
        case 4: {
            this->mainMenu();
        }
        if (k!=1 && k!=2 && k!=3 && k!=4) { this->mainMenu();}


    }
};
void Hotel::removeReservation(std::vector<Reservation> &reservations, int idR) {
    std::vector<Reservation>::iterator it;
    int pocet = 0;
    for (it = reservations.begin(); it!=reservations.end(); ++it) {
        if (idR == it->getId()) {
            //smazat rezervaci
            reservations.erase(it);
            std::cout << "Vybrana rezervace byla smazana\n";
            break;
        }
        else { pocet++; }
    }
    if (pocet==reservations.size()) {
        std::cout << "Zadna rezervace nebyla nalezena\n";
    }
}