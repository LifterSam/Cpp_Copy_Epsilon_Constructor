#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Location.h" // Basisklasse einbinden
#include <string>

class Restaurant : public Location
{
private:
    // Neue Attribute für Restaurant
    int sitzplaetze_;

public:
    // Konstruktor
    Restaurant(const std::string& name, const std::map<std::string, double>& angebot, int sitzplaetze);

    // Getter und Setter für Sitzplätze
    int getSitzplaetze() const;
    void setSitzplaetze(int sitzplaetze);

    // Methode zum Überschreiben (falls nötig)
    void showAngebot() const override;
};

#endif // RESTAURANT_H
