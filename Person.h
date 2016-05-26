//
// Created by yuliya on 12.4.16.
//

#ifndef HOTELRESERVATION_PERSON_H
#define HOTELRESERVATION_PERSON_H

#include <string>
#include "Date.h"

class Person {
public:
    Person();
    Person(std::string, std::string, std::string, std::string, Date&);
    Person(const Person&);
    ~Person() {};
    std::string getName();
    std::string getSurname();
    std::string getPhone();
    std::string getEmail();
    void getPerson();
    void setName(std::string jmeno) { name = jmeno;};
    void setSurname(std::string prijmeni) { surname = prijmeni;};
    void setPhone(std::string tel) { phone = tel;};
    void setEmail(std::string mail) { email = mail;};
    std::string getBirthday();
    Person& operator=(const Person &);

private:
    std::string name;
    std::string surname;
    std::string phone;
    std::string email;
    Date birthday;
};


#endif //HOTELRESERVATION_PERSON_H
