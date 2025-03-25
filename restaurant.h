#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Location.h"
#include <string>

class Restaurant : public Location
{
private:
    // new special attribute for restaurant
    int sitzplaetze_;

public:

    Restaurant(const std::string& name, const std::map<std::string, double>& angebot, int sitzplaetze);

    int getSitzplaetze() const;
    void setSitzplaetze(int sitzplaetze);

    void showAngebot() const override;
};

#endif
