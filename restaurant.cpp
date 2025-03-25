#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant(const std::string& name, const std::map<std::string, double>& angebot, int sitzplaetze)
    : Location(name, angebot), sitzplaetze_(sitzplaetze) {
    std::cout << getName() << " ist ein Restaurant!" <<std::endl;
}


int Restaurant::getSitzplaetze() const
{
    return sitzplaetze_;
}


void Restaurant::setSitzplaetze(int sitzplaetze)
{
    sitzplaetze_ = sitzplaetze;
}


void Restaurant::showAngebot() const
{   
    Location::showAngebot();
}
