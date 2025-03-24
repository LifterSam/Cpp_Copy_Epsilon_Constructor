#include "Restaurant.h"
#include <iostream>

// Konstruktor von Restaurant
Restaurant::Restaurant(const std::string& name, const std::map<std::string, double>& angebot, int sitzplaetze)
    : Location(name, angebot), sitzplaetze_(sitzplaetze) {
    std::cout << getName() << " ist ein Restaurant!" <<std::endl;
}

// Getter-Methode für Sitzplätze
int Restaurant::getSitzplaetze() const
{
    return sitzplaetze_;
}

// Setter-Methode für Sitzplätze
void Restaurant::setSitzplaetze(int sitzplaetze)
{
    sitzplaetze_ = sitzplaetze;
}

// Methode überschreiben (optional)
void Restaurant::showAngebot() const
{
    // Rufe die Basisklassen-Methode auf
    Location::showAngebot();
}
