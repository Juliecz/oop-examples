#include "Date.h"
#include <ctime>
#include <iostream>
#include <sstream>

Date::Date() {
    time_t rawtime;
    struct tm* timeinfo;
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon+1;
    year = timeinfo->tm_year+1900;
};
Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
};
Date::Date(const Date &datum) {
    day = datum.day;
    month = datum.month;
    year = datum.year;
};
Date::Date(char datum[]) {
    //int day, month, year;
    std::sscanf(datum, "%d.%d.%d", &day, &month, &year);
    //std::cout << day << "  " << month << "  " <<year << "\n" ;
};
Date Date::getDate() {
    Date d(day, month, year);
    return d;
};

Date& Date::operator=(const Date &datum) {
    day = datum.day;
    month = datum.month;
    year = datum.year;
    return *this;
};

void Date::setDate(int d, int m)  {
    day=d;
    month=m;
};
std::string Date::showDate() {
    std::ostringstream str;
    str << day << "."<< month << "." << year;
    std::string output = str.str();
    return output;
};
void Date::setDate(int d, int m, int y)  {
    day = d;
    month = m;
    year = y;
};
bool Date::validDate() {
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
        if(day>31) {
            return false;
        }
        else { return true;}
    }
    else if(month==2 || month==4 || month==6 || month==9 || month==11) {
        if(day>30) { return false; }
        else { return true; }
    }
    else if (month<1 || month>12) {
        return false;
    }
};
bool Date::operator==(Date & d1) {
    if (d1.day == this->day && d1.month == this->month && d1.year == this->year) {
        std::cout << "true";
        return true;
    }
    else {
        std::cout << "false";
        return false;
    }
};
bool Date::operator>=(Date &d1) {
    if(this->year > d1.year) {
        return true;
    }
    else if(this->year < d1.year) { return false; }
    else if (this->month > d1.month && d1.year >= this->year) {
        //std::cout << "true";
        return true;
    }
    else if(d1.month == this->month && this->day >= d1.day && this->year >= d1.year) {
        //std::cout << "true";
        return true;
    }
    else {
        //std::cout << "false";
        return false;
    }
};
bool Date::operator<=(Date &d1) {
    if (d1.month == this->month && d1.year == this->year) {
        if (this->day <= d1.day) {
            //std::cout << "true";
            return true;
        }
        else {
            //std::cout << "false";
            return false;
        }
    }
    else if (d1.month > this->month && d1.year >= this->year) {
        //std::cout << "true";
        return true;
    }
    else if(this->year < d1.year) {
        //std::cout << "true";
        return true;
    }
    else {
        //std::cout << "false";
        return false;
    }
};
bool Date::operator<(Date &d1) {
    if (d1.month == this->month && d1.year == this->year) {
        if (this->day < d1.day) {
            //std::cout << "true";
            return true;
        }
        else {
            //std::cout << "false";
            return false;
        }
    }
    else if (d1.month > this->month && d1.year >= this->year) {
        //std::cout << "true";
        return true;
    }
    else if(this->year < d1.year) {
        //std::cout << "true";
        return true;
    }
    else {
        //std::cout << "false";
        return false;
    }
};