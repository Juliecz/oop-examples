//
// Created by yuliya on 25.5.16.
//

#ifndef HOTELRESERVATION_GUMOVEPOLE_H
#define HOTELRESERVATION_GUMOVEPOLE_H

#include <iostream>

template<typename Type>
class GumovePole {
public:
    GumovePole() {
        size = 10;
        pole = new Type[size];
    };
    GumovePole(int s = 10) {
        size = s;
        pole = new Type[size];
    };
    GumovePole(const GumovePole&guma) {
        size = guma.size;
        pole = new Type[size];
    };
    GumovePole& operator= (const GumovePole&guma) {
        size = guma.size;
        pole = new Type[size];
        return *this;
    };
    ~GumovePole() {
        delete pole;
    };
    Type& operator[] (int k) {
        if (k>=size) {
            Type* p = new Type[size+1];
            for( int i = 0; i < size; i++) {
                p[i] = pole[i];
            }
            delete pole;
            pole = p;
            size = k+1;
        }
        return  pole[k];
    };
    void vypis() {
        for ( int i = 0; i < size; i++ )
        {
            std::cout << pole[i] << " ";
        }
        std::cout << "\n";
    }

private:
    int size;
    Type* pole;
};


#endif //HOTELRESERVATION_GUMOVEPOLE_H
