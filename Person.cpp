//
// Created by yuliya on 12.4.16.
//

#include <iostream>
#include "Person.h"
#include "Date.h"

Person::Person() { };

Person::Person(std::string jmeno, std::string prijmeni, std::string tel, std::string mail, Date &date) {

    name = jmeno;
    surname = prijmeni;
    phone = tel;
    email = mail;
    birthday.setDate(date.getDay(), date.getMonth(), date.getYear());
};
Person::Person(const Person &person) {
    this->name = person.name;
    this->surname = person.surname;
    this->phone = person.phone;
    this->email = person.email;
    this->birthday = person.birthday;
};
Person& Person::operator=(const Person &person) {
    this->name = person.name;
    this->surname = person.surname;
    this->phone = person.phone;
    this->email = person.email;
    this->birthday = person.birthday;
    return *this;
}
std::string Person::getName() {
    //std::cout << name << "\n";
    return name;
};
std::string Person::getSurname() {
    //std::cout << surname << "\n";
    return surname;
};
std::string Person::getPhone() {
    //std::cout << phone << "\n";
    return phone;
};
std::string Person::getEmail() {
    //std::cout << email << "\n";
    return email;
};
void Person::getPerson() {
    std::cout << name << " " << surname << " " << phone << " " << email << " " << birthday.showDate() << "\n";
};
std::string Person::getBirthday() {
    std::string date = birthday.showDate();
    return date;
};