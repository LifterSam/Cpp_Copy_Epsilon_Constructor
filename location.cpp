#include <iostream>
#include <algorithm>
#include "location.h"

#pragma region KONSTRUKTOREN {

std::vector<Location*> Location::alleLocationsVector_;

Location::Location(const std::string& name, const std::map<std::string, double>& angebot)
    : name_(name), angebot_(angebot){
    std::cout << "Die Location " << name_ << " wurde im Navi gefunden!" <<std::endl;
    anzahlLocations_++;
    alleLocationsVector_.push_back(this);
}

// Rule of 5 =============================================================================
// copy constructor
Location::Location(const Location& other)
    : name_(other.name_), angebot_(other.angebot_) {
    anzahlLocations_++;
}

// copy assignment constructor
Location& Location::operator=(const Location& other) {
    if (this == &other) return *this;
    name_ = other.name_;
    angebot_ = other.angebot_;
    return *this;
}

// Move constructor: can not be be disabled because operator overloading,
// disabling it with `= delete` prevents compilation!  
// To disable optimization in the CMake file:  
// "target_compile_options(OOP_Cpp_Location_Restaurant PRIVATE -fno-elide-constructors)"  
// This allows the output to be visible at that point.
Location::Location(Location&& other) noexcept
    : name_(std::move(other.name_)), angebot_(std::move(other.angebot_)) {
    std::cout << "VERSCHIEBENKONSTRUKTOR AUFGERUFEN####################" << std::endl;
    // cout is usually not printed due to "Copy Elision Optimization
}

/* with "= delete" in location.h deactivated thus not used
// move assignment constructor
Location& Location::operator=(Location&& other) noexcept {
    if (this == &other) return *this;  // Handle self-assignment
    name_ = std::move(other.name_);
    menue_ = std::move(other.menue_);
    return *this;
}*/

// destructor
Location::~Location(){
    std::cout << "Die Location " << name_ 
              << " wurde wegen mangelnder Hygiene von Gordon Ramsay gesprengt. Na toll!\n" 
              << std::endl;
    anzahlLocations_--;

    // remove location from vector
    auto it = std::find(alleLocationsVector_.begin(), alleLocationsVector_.end(), this);
    if (it != alleLocationsVector_.end()) {
        alleLocationsVector_.erase(it);
    }
}

#pragma endregion KONSTRUKTOREN }


#pragma region GETTER & SETTER {

std::string Location::getName() const
{
    return name_;
}

std::map<std::string, double> Location::getAngebot() const
{
    return angebot_;
}

double Location::getEinnahmen() const
{
    return einnahmen_;
}

int Location::getAnzahlLocations(){
    return anzahlLocations_;
};

void Location::setName(const std::string &newName)
{
    this->name_ = newName;
}

void Location::setAngebot(const std::map<std::string, double> &newAngebot)
{
    angebot_ = newAngebot;
}

void Location::setEinnahmen(const double& newEinnahmen)
{
    einnahmen_ = newEinnahmen;
}

#pragma endregion Getter & Setter }


#pragma region METHODEN {

void Location::showAngebot() const{
    std::cout << "Die Location " << this->getName() << " hat folgendes Menue:\n " << std::endl;;

    for (const auto& item : angebot_) {
        std::cout << item.first << ": " << item.second << " Schmeckkels" << std::endl;
    }
}

void Location::printAlleLocations() {
    if (alleLocationsVector_.empty()) {
        std::cout << "Keine Locations registriert." << std::endl;
        return;
    }

    std::cout << "Alle registrierten Locations:" << std::endl;
    for (const Location* location : alleLocationsVector_) {
        std::cout << "Name: " << location->getName()
        << ", Einnahmen: " << location->getEinnahmen() << " Schmeckkels" << std::endl;
    }
}

#pragma endregion METHODEN }


#pragma region OPERATORÜBERLADUNGEN {

Location Location::operator+(const Location& anderer) const {
    std::map<std::string, double> kombiniertesAngebot = angebot_;

    for (const auto& item : anderer.angebot_) {
        kombiniertesAngebot[item.first] = item.second;
    }

    Location kombinierteLocation(name_ + " & " + anderer.name_, kombiniertesAngebot);
    return kombinierteLocation; // The move constructor is applied in the background here 
}                               // If disabled, a Location cannot be returned,  
// and the Location counter as well as the vector list  
// will not take over the combined Location.

#pragma endregion OPERATORÜBERLADUNGEN }
