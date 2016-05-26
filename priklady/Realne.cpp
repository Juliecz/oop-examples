#include <iostream>
#include "Cislo.h"

Realne::Realne(const Realne &num) {
    realne = num.realne;
};
Realne::Realne(double num) {
    realne = num;
};
Realne& Realne::operator=(const Realne&num) {
    realne = num.realne;
    return *this;
};
void Realne::vypisCisla() {
    std::cout << "Realne cislo: " << realne << "\n";
};
Realne Realne::operator+(const Realne&num) {
    return Realne(realne+num.realne);
};
Realne Realne::operator-(const Realne&num) {
    return Realne(realne-num.realne);
};
Realne Realne::operator*(const Realne&num) {
    return Realne(realne*num.realne);
};
Realne Realne::operator/(const Realne&num) {
    return Realne(realne/num.realne);
};

Realne& Realne::operator+=(const Realne &num) {
    return *this += num;
};
Realne& Realne::operator-=(const Realne &num) {
    return *this -= num;
};
Realne& Realne::operator*=(const Realne &num) {
    return *this *= num;
};
Realne& Realne::operator/=(const Realne &num) {
    return *this /= num;
};