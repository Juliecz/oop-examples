#include "Student.h"
#include <fstream>
#include <vector>

Student::Student() {
    pocetPredmetu = 0;
    for (int i =0; i<20; i++) {
        seznamPredmetu[0][i] = 0;
        seznamPredmetu[1][i] = -1; //todo nema zapocet
        seznamPredmetu[2][i] = 0;
    }
    name = "nezname jmeno";
};
Student::Student(std::string jmeno) {
    name = jmeno;
    pocetPredmetu = 0;
    for (int i =0; i<20; i++) {
        seznamPredmetu[0][i] = 0;
        seznamPredmetu[1][i] = -1; //todo nema zapocet
        seznamPredmetu[2][i] = 0;
    }
};
Student::Student(const Student &student) {
    name = student.name;
    pocetPredmetu = student.pocetPredmetu;
    for (int i=0; i<20; i++) {
        seznamPredmetu[0][i] = student.seznamPredmetu[0][i];
        seznamPredmetu[1][i] = student.seznamPredmetu[1][i];
        seznamPredmetu[2][i] = student.seznamPredmetu[2][i];
    }
};
Student& Student::operator=(const Student &student) {
    name = student.name;
    pocetPredmetu = student.pocetPredmetu;
    for (int i=0; i<20; i++) {
        seznamPredmetu[0][i] = student.seznamPredmetu[0][i];
        seznamPredmetu[1][i] = student.seznamPredmetu[1][i];
        seznamPredmetu[2][i] = student.seznamPredmetu[2][i];
    }
    return *this;
}
int Student::zapisPredmetu(int predmet) {
    //todo remove bool zapsany = false;
    //todo kontrola jestli je predmet jiz zapsany zapsany = true;
    int cislo = najitPredmet(predmet);
    //std::cout << "\nCislo predmetu: "<< cislo<< "  Pocet predmetu: " << pocetPredmetu<< "\n";
    if (cislo == -1) { //predmet neni zapsany
        if (pocetPredmetu < 20) {
            for (int i = 0; i < 20; i++) {
                if (seznamPredmetu[0][i] == 0) {
                    seznamPredmetu[0][pocetPredmetu] = predmet;
                    pocetPredmetu++;
                    return 0;
                }
            }
        }
        else {
            std::cout << "Student ma maximalni pocet predmetu\n";
            return -1;
        }
    }
    else {
        std::cout << "Predmet je jiz zapsany";
        return -2;
    }
};
int Student::zapocet(int predmet) {
    int cislo = najitPredmet(predmet);
    //todo najit cislo predmetu, p - kod predmetu
    if (cislo > -1) {
        if (seznamPredmetu[1][cislo] == -1) {
            //student nema zapocet
            seznamPredmetu[1][cislo] = 0; //zapocet udelen
            return 0;
        }
        else if (seznamPredmetu[1][cislo] == 0){
            std::cout << "Student jiz ma zapocet\n";
            return -1;
        }
    }
    else {
        std::cout << "Tento predmet neni zapsany\n";
    }
};
int Student::zkouska(int predmet, int znamka) {
    int cislo = najitPredmet(predmet);
    //todo najit cislo predmetu
    if (cislo > -1) {
        if (seznamPredmetu[2][cislo] < 3) {  //pocet pokusu
            if (seznamPredmetu[1][cislo] == 0 || seznamPredmetu[1][cislo] == 5) { // student ma zapocet
                //student ma zapocet
                seznamPredmetu[1][cislo] = znamka;
                seznamPredmetu[2][cislo]++;
                return 0;
            }
            else if (seznamPredmetu[1][cislo] == -1) { //student nema zapocet
                std::cout << "Student nema zapocet\n";
                return -1;
            }
            else if (seznamPredmetu[1][cislo] > 0) { //jiz ma znamku
                std::cout << "Student jiz ma znamku\n";
                return -1;
            }
        }
    }
    else {
        std::cout << "Tento predmet neni zapsany\n";
    }
};
int Student::najitPredmet(int predmet) {
    for (int i=0; i<20; i++) {
        if (seznamPredmetu[0][i] == predmet) {
            return i;
        }
    }
    return -1;
};
void Student::splnenePredmety() {
    std::cout << "\nnPredmet: Znamka\n";
    for (int i=0; i<20; i++) {
        if (seznamPredmetu[1][i] > 0) {
            std::cout << seznamPredmetu[0][i] << ": " << seznamPredmetu[1][i] << "\n";
        }
    }
};
void Student::vypsatSeznamPredmetu() {
    std::cout << "\nPredmet Znamka Pocet pokusu\n";
    for (int i=0; i<20; i++) {
        std::cout << seznamPredmetu[0][i] << " \t\t " << seznamPredmetu[1][i] << " \t\t " << seznamPredmetu[2][i] << "\n";
    }
};
float Student::prumer() {
    float prumer=0, znamky=0;
    for (int i=0; i<20; i++) {
        if (seznamPredmetu[1][i] > 0) {
            znamky += seznamPredmetu[1][i];
            prumer++;
        }
    }
    prumer = znamky/prumer;
    return prumer;
};
std::string Student::getName() {
    return name;
};
void Student::setName(std::string jmeno) {
    name = jmeno;
};