#include <iostream>
#include <algorithm>
#include "person.h"



#pragma region KONSTRUKTOREN {

std::vector<Person*> Person::allePersonenVector_;

Person::Person(const std::string& name) : name_(name) {
    std::cout << "Person " << this->name_ << " mit Kontostand von "
              << kontostand_ << " Schmeckkels wurde angelegt." << std::endl;
    anzahlPersonen_++;
    allePersonenVector_.push_back(this);
}


Person::Person(const std::string& name, const double& kontostand)
    : name_(name), kontostand_(kontostand) {
    std::cout << "Wow, " << this->name_ << ", du wohlhabende Person wurdest mit "
              << kontostand_ << " Schmeckkels angelegt!" << std::endl;
    anzahlPersonen_++;
    allePersonenVector_.push_back(this);
}

// Rule of 5 definitions ===================================================================
// not used, but this is how declaration looks like

/*
// copy constructor
Person::Person(const Person& other)
    : name_(other.name_), kontostand_(other.kontostand_) {}

// copy assignment constructor
Person& Person::operator=(const Person& other) {
    if (this == &other) return *this;
    name_ = other.name_;
    kontostand_ = other.kontostand_;
    return *this;
}

// move constructor
Person::Person(Person&& other) noexcept
    : name_(std::move(other.name_)), kontostand_(other.kontostand_) {
    other.kontostand_ = 100.0;
}

// move assignment constructor
Person& Person::operator=(Person&& other) noexcept {
    if (this == &other) return *this;
    name_ = std::move(other.name_);
    kontostand_ = other.kontostand_;
    other.kontostand_ = 100.0;
    return *this;
}*/

// destructor
Person::~Person(){
    char firstChar = name_[0];
    if (firstChar >= 'A' && firstChar <= 'J') {
        std::cout << "Die Person " << name_
                  << " hat die Location wuetend wegen Salmonellenvergiftung "
                     "verlassen und ist unauffindbar! Prost!\n" << std::endl;
    }
    else {
        std::cout << "Die Person " << name_ << " ist versehentlich als Gericht "
                                               "auf der Speisekarte gelandet und verschwunden! Upsi, man "
                                               "sollte\naufpassen ob man auf die Toilette geht oder "
                                               "ausversehen in die Kueche!!!\n" << std::endl;
    }
    anzahlPersonen_--;

    auto it = std::find(allePersonenVector_.begin(), allePersonenVector_.end(), this);
    if (it != allePersonenVector_.end()) {
        allePersonenVector_.erase(it);
    }
}

#pragma endregion KONSTRUKTOREN }


#pragma region GETTER & SETTER {

std::string Person::getName() const
{
    return name_;
}

double Person::getKontostand() const
{
    return kontostand_;
}

int Person::getAnzahlPersonen(){
    return anzahlPersonen_;
};

const std::vector<Person*>& Person::getAllePersonen() {
    return allePersonenVector_;
}

void Person::setKontostand(const double& newKontostand)
{
    kontostand_ = newKontostand;
}

void Person::setName(const std::string &newName)
{
    name_ = newName;
}

#pragma endregion GETTER & SETTER }


#pragma region METHODEN {

void Person::dining(Location& location){
    std::cout << name_ << " geht in die Location " << location.getName() << "."<< std::endl;
    location.showAngebot();

    location.setEinnahmen(vomMenueAussuchen(location.getAngebot()));

    std::cout << "\n" << name_ << " isst alles auf! Omnomnom!!!" << std::endl;
}

double Person::vomMenueAussuchen(const std::map<std::string, double>& menue){
    std::string auswahl;
    std::cout << "\nWas waehlt " << this->name_ << " vom Menue: ";
    std::getline(std::cin, auswahl);
    std::cout << auswahl << " kostet: " << menue.at(auswahl) << std::endl;
    this->kontostandAktualisieren(menue.at(auswahl));

    return menue.at(auswahl); // return value for dining method
}

void Person::kontostandAktualisieren(const double& preis){
    double neuerKontostand = this->getKontostand();
    this->setKontostand(neuerKontostand-preis);
}

void Person::printAllePersonen() {
    if (allePersonenVector_.empty()) {
        std::cout << "Keine registrierten Personen vorhanden." << std::endl;
        return;
    }

    std::cout << "Alle registrierten Personen:" << std::endl;
    for (const Person* person : allePersonenVector_) {
        std::cout << "Name: " << person->getName()
                  << ", Kontostand: " << person->getKontostand() << " Schmeckkels" << std::endl;
    }
}

#pragma endregion METHODEN }
