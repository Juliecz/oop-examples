//
// Created by yuliya on 24.5.16.
//

#ifndef HOTELRESERVATION_CISLO_H
#define HOTELRESERVATION_CISLO_H


class Cislo {
public:
    virtual ~Cislo() {};
    virtual void vypisCisla() = 0;
};

class Cele: Cislo {
public:
    Cele() { cislo = 0; };
    Cele(const Cele&);
    Cele(int);
    virtual ~Cele();
    virtual void vypisCisla();

    Cele& operator=(const Cele&);

    Cele operator+(const Cele&);
    Cele operator-(const Cele&);
    Cele operator*(const Cele&);
    Cele operator/(const Cele&);

    Cele& operator+=(const Cele&);
    Cele& operator-=(const Cele&);
    Cele& operator*=(const Cele&);
    Cele& operator/=(const Cele&);
private:
    int cislo;
};

class Realne: Cislo {
public:
    Realne() { realne = 0;};
    Realne(const Realne&);
    Realne(double);
    Realne& operator=(const Realne&);
    //todo destruktor
    virtual ~Realne() {};
    virtual void vypisCisla();
    Realne operator+(const Realne&);
    Realne operator-(const Realne&);
    Realne operator*(const Realne&);
    Realne operator/(const Realne&);

    Realne& operator+=(const Realne&);
    Realne& operator-=(const Realne&);
    Realne& operator*=(const Realne&);
    Realne& operator/=(const Realne&);
private:
    double realne;
};

class Komplexni: Cislo {
public:
    Komplexni() { real = 0; imag = 0;};
    Komplexni(const Komplexni &);
    Komplexni(double, double);
    Komplexni& operator=(const Komplexni&);
    virtual ~Komplexni() {};
    virtual void vypisCisla();
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);
    Komplexni operator+(const Komplexni&);
    Komplexni operator-(const Komplexni&);
    Komplexni operator*(const Komplexni&);
    Komplexni operator/(const Komplexni&);

    Komplexni& operator+=(const Komplexni&);
    Komplexni& operator-=(const Komplexni&);
    Komplexni& operator*=(const Komplexni&);
    Komplexni& operator/=(const Komplexni&);

private:
    double real;
    double imag;
};

#endif //HOTELRESERVATION_CISLO_H
