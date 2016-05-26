#ifndef HOTELRESERVATION_DATE_H
#define HOTELRESERVATION_DATE_H


#include <bits/stringfwd.h>

class Date {
public:
    Date();
    Date(int, int, int);
    Date(char []);
    Date(const Date&);
    Date& operator=(const Date &);
    ~Date() {};
    int getDay() { return day;};
    int getMonth() { return month;};
    int getYear() { return year;};
    void setDate(int, int);
    void setDate(int, int, int);
    std::string showDate();
    Date getDate();
    bool validDate();

    bool operator==(Date&);
    bool operator>=(Date&);
    bool operator<=(Date&);
    bool operator<(Date&);

private:
    int day;
    int month;
    int year;
};


#endif //HOTELRESERVATION_DATE_H
