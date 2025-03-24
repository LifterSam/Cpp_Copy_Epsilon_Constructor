#include <iostream>
#include <algorithm>
#include "location.h"

// Konstruktor ================================================================================
#pragma region KONSTRUKTOREN {
// Beginn eines Formatblocks zur Übersicht Konstruktoren

// Konstruktor nach Aufgabenvorgabe mit =======================================================
std::vector<Location*> Location::alleLocationsVector_; // erfasst alle instanzierten Locations

Location::Location(const std::string& name, const std::map<std::string, double>& angebot)
    : name_(name), angebot_(angebot){
    std::cout << "Die Location " << name_ << " wurde im Navi gefunden!" <<std::endl;
    anzahlLocations_++;
    alleLocationsVector_.push_back(this);
}

// Rule of 5 mit Definitionen =================================================================
// Kopierkonstruktor
Location::Location(const Location& other)
    : name_(other.name_), angebot_(other.angebot_) {
    anzahlLocations_++; // bei Kopie eine Location mehr, logisch
}

// Kopierzuweisungskonstruktor
Location& Location::operator=(const Location& other) {
    if (this == &other) return *this;
    name_ = other.name_;
    angebot_ = other.angebot_;
    return *this;
}

// Verschiebekonstruktor, sollte laut Aufgabe deaktiviert sein, aber dann geht
// die Operatorüberladung nicht mehr so einfach, daher wieder aktiviert;
// er wird auch verwendet, denn wenn mit = delete deaktiviert, kann nicht mehr
// kompiliert werden!!!
// im cmake-file Optimierung deaktivieren:
// "target_compile_options(OOP_Klassen_Person_Location PRIVATE -fno-elide-constructors)"
// , dann kann man auch den Output sehen an der Stelle
Location::Location(Location&& other) noexcept
    : name_(std::move(other.name_)), angebot_(std::move(other.angebot_)) {
    std::cout << "VERSCHIEBENKONSTRUKTOR AUFGERUFEN####################" << std::endl;
    // der cout wird wegen "Copy Epsilon Optimierung" normalerweise nicht ausgegeben
}

/* auch hier auskommentiert da mit "= delete" in location.h deaktiviert
// Verschiebezuweisungsoperator
Location& Location::operator=(Location&& other) noexcept {
    if (this == &other) return *this;  // Handle self-assignment
    name_ = std::move(other.name_);
    menue_ = std::move(other.menue_);
    return *this;
}*/

// Destruktor (bei Nichtgefallen und Mangelhygiene im Lokal)
Location::~Location(){
    std::cout << "Die Location " << name_ << " wurde wegen "
                                             "mangelnder Hygiene von Gordon Ramsay gesprengt. Na toll!\n" << std::endl;
    anzahlLocations_--;

    auto it = std::find(alleLocationsVector_.begin(), alleLocationsVector_.end(), this);
    if (it != alleLocationsVector_.end()) {
        alleLocationsVector_.erase(it);
    }
}

// Ende eines Formatblocks zur Übersicht Konstruktoren
#pragma endregion KONSTRUKTOREN }

// Getter und Setter ==========================================================================
#pragma region GETTER & SETTER {

// Getter Definitionen ------------------------------------------------------------------------
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

// Setter Definitionen -----------------------------------------------------------------------
void Location::setName(const std::string &newName)
{
    this->name_ = newName; // geht mit this-> oder ohne weil name_ eindeutig Klassenaatribut ist
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

// Klassenmethoden definieren =================================================================
#pragma region METHODEN {
// Ausgabemethode für das köstliche Menü unserer realen Locations!
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

// Operatorüberladungen =======================================================================
#pragma region OPERATORÜBERLADUNGEN {

// Operatorüberladung für +
Location Location::operator+(const Location& anderer) const {
    std::map<std::string, double> kombiniertesAngebot = angebot_;

    // Füge die Gerichte des anderen Menüs hinzu
    for (const auto& item : anderer.angebot_) {
        kombiniertesAngebot[item.first] = item.second;  // Überschreibt bei doppelten Einträgen
    }

    // Erstelle eine neue Location mit dem kombinierten Menü
    Location kombinierteLocation(name_ + " & " + anderer.name_, kombiniertesAngebot);
    return kombinierteLocation; // hier greift der Verschiebekonstruktor im Hintergrund!!!
}                               // wenn deaktiviert lässt sich hier sonst keine Location
// mit return zurückgeben und Locationzähler sowie Vector-
// Liste übernehmen die kombinierte Location nicht

#pragma endregion OPERATORÜBERLADUNGEN }
