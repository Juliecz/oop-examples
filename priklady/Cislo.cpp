
#include <iostream>
#include "Cislo.h"
Cele::Cele(const Cele &num) {
    cislo = num.cislo;
};
Cele::Cele(int num) {
    cislo = num;
};
void Cele::vypisCisla() {
    std::cout << "Cislo: " << cislo << "\n";
};
Cele::~Cele() {
    //todo add
};
Cele& Cele::operator=(const Cele &num) {
    cislo = num.cislo;
    return *this;
};
Cele Cele::operator+(const Cele &num) {
    return Cele(cislo+num.cislo);
};
Cele Cele::operator-(const Cele &num) {
    return Cele(cislo-num.cislo);
};
Cele Cele::operator*(const Cele &num) {
    return Cele(cislo*num.cislo);
};
Cele Cele::operator/(const Cele &num) {
    return Cele(cislo/num.cislo);
};
Cele& Cele::operator+=(const Cele &num) {
    cislo += num.cislo;
    return *this;
};
Cele& Cele::operator-=(const Cele &num) {
    cislo -=num.cislo;
    return *this;
};
Cele& Cele::operator*=(const Cele &num) {
    cislo *= num.cislo;
    return *this;
};
Cele& Cele::operator/=(const Cele &num) {
    cislo /= num.cislo;
    return *this;
};