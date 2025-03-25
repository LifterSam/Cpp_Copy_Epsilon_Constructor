#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <map>
#include "Location.h"

class Person
{
private:
    std::string name_;
    double kontostand_ = 100;
    inline static int anzahlPersonen_ = 0;
    static std::vector<Person*> allePersonenVector_;

public:

#pragma region KONSTRUKTOREN {
    Person(const std::string& name);
    Person(const std::string& name, const double& kontostand);

    // Rule of 5  ==============================================================
    // copy constructor
    Person(const Person& other) = delete;

    // copy assignment constructor
    Person& operator=(const Person& other) = delete;

    // move constructor
    Person(Person&& other) noexcept = delete;

    // move assignment constructor
    Person& operator=(Person&& other) noexcept = delete;

    // destructor ==============================================================
    ~Person();

#pragma endregion KONSTRUKTOREN }


#pragma region GETTER & SETTER {

    std::string getName() const;
    double getKontostand() const;
    static int getAnzahlPersonen();
    static const std::vector<Person*>& getAllePersonen();

    void setName(const std::string &newName);
    void setKontostand(const double& newKontostand);

#pragma endregion GETTER & SETTER }


    // class methods =========================================================
    void dining(Location& location);
    double vomMenueAussuchen(const std::map<std::string, double>& menue);
    void kontostandAktualisieren(const double& preis);
    static void printAllePersonen();

};

#endif
