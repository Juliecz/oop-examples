#include <iostream>
#include "Cislo.h"

Komplexni::Komplexni(const Komplexni &num) {
    real = num.real;
    imag = num.imag;
};
Komplexni::Komplexni(double re, double im) {
    real = re;
    imag = im;
};
Komplexni& Komplexni::operator=(const Komplexni &num) {
    real = num.real;
    imag = num.imag;
    return *this;
};
void Komplexni::vypisCisla() {
    if(real == 0) {
        std::cout << "Komplexni cislo: " << imag << "i\n";
    }
    else if(imag == 0) {
        std::cout << "Komplexni cislo: " << real << "\n";
    }
    else if(imag>0) {
        std::cout << "Komplexni cislo: " << real << "+" << imag << "i\n";
    }
    else {
        std::cout << "Komplexni cislo: " << real << imag << "i\n";
    }
};
double Komplexni::getReal() {
    std::cout << "Realna cast: " << real << "\n";
    return real;
};
double Komplexni::getImag() {
    std::cout << "Imaginarni cast: " << imag << "i\n";
    return imag;
};
void Komplexni::setReal(double re) {
    real = re;
};
void Komplexni::setImag(double im) {
    imag = im;
};
Komplexni Komplexni::operator+(const Komplexni &num) {
    return Komplexni(real + num.real, imag + num.imag);
};
Komplexni Komplexni::operator-(const Komplexni &num) {
    return Komplexni(real - num.real, imag - num.imag);
};
Komplexni Komplexni::operator*(const Komplexni &num) {
    double re, im;
    re = real*num.real - imag*num.imag;
    im = imag * num.real + num.imag * real;
    return Komplexni(re, im);
};
Komplexni Komplexni::operator/(const Komplexni &num) {
    double re, im;
    re = (real*num.real + imag*num.imag)/(num.real*num.real + num.imag*num.imag);
    im = (num.real*imag - num.imag*real)/(num.real*num.real + num.imag*num.imag);
    return Komplexni(re, im);
};

Komplexni& Komplexni::operator+=(const Komplexni &num) {
    real += num.real;
    imag += num.imag;
    return *this;
};
Komplexni& Komplexni::operator-=(const Komplexni &num) {
    real -= num.real;
    imag -= num.imag;
    return *this;
};
Komplexni& Komplexni::operator*=(const Komplexni &num) {
    double re, im;
    re = real*num.real - imag*num.imag;
    im = imag * num.real + num.imag * real;
    real = re;
    imag = im;
    return *this;
};
Komplexni& Komplexni::operator/=(const Komplexni &num) {
    real = (real*num.real + imag*num.imag)/(num.real*num.real + num.imag*num.imag);
    imag = (num.real*imag - num.imag*real)/(num.real*num.real + num.imag*num.imag);
    return *this;
};
