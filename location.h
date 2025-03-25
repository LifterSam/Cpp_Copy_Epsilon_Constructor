#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>


class Location
{
private:
    std::string name_;
    std::map<std::string, double> angebot_;
    double einnahmen_ = 0;
    inline static int anzahlLocations_ = 0; // inline command allows declaration inside .h
    static std::vector<Location*> alleLocationsVector_;

public:

#pragma region KONSTRUKTOREN {

    Location(const std::string& name, const std::map<std::string, double>& angebot);

    // Rule of 5 =================================================================
    Location(const Location& other);
    Location& operator=(const Location& other);
    Location(Location&& other) noexcept;
    Location& operator=(Location&& other) noexcept = delete;

    ~Location();

#pragma endregion KONSTRUKTOREN }


#pragma region GETTER & SETTER {

    std::string getName() const;
    std::map<std::string, double> getAngebot() const;
    double getEinnahmen() const;
    static int getAnzahlLocations();
    static const std::vector<Location*>& getAlleLocations();

    void setName(const std::string &newName);
    void setAngebot(const std::map<std::string, double> &newAngebot);
    void setEinnahmen(const double& newEinnahmen);

#pragma endregion GETTER & SETTER }



#pragma region METHODEN {

    virtual void showAngebot() const;
    static void printAlleLocations();
    Location operator+(const Location& anderer) const;

#pragma endregion METHODEN }

};

#endif
