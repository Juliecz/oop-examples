//
// Created by yuliya on 23.5.16.
//

#ifndef HOTELRESERVATION_STUDENT_H
#define HOTELRESERVATION_STUDENT_H
#include <iostream>
#include <vector>

class Student {
public:
    Student();
    Student(std::string);
    Student(const Student &);
    Student& operator=(const Student &);
    ~Student() {};
    int zapisPredmetu(int);
    int zapocet(int);
    int zkouska(int, int);
    int najitPredmet(int);
    void splnenePredmety();
    void vypsatSeznamPredmetu();
    float prumer();
    std::string getName();
    void setName(std::string);
private:
    std::string name;
    int pocetPredmetu;
    int seznamPredmetu[3][20];
};


#endif //HOTELRESERVATION_STUDENT_H
