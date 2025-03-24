#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <map>
#include "Location.h"

class Person
{
private:
    // Klassenattribute nach Vorgabe festgelegt ================================
    std::string name_;
    double kontostand_ = 100;
    inline static int anzahlPersonen_ = 0; // mit inline kann man hier bereits deklarieren
    static std::vector<Person*> allePersonenVector_;

public:
// Konstruktoren ===========================================================
#pragma region KONSTRUKTOREN {
    // Konstruktor nach Vorgabe "Name über Konstruktor zuweisen" ===============
    Person(const std::string& name);

    // Eigener Konstruktor für Rich People =====================================
    Person(const std::string& name, const double& kontostand);

    // Rule of 5 Deklarationen =================================================
    // Kopierkonstruktor
    Person(const Person& other) = delete;

    // Kopierzuweisungsoperator
    Person& operator=(const Person& other) = delete;

    // Verschiebekonstruktor
    Person(Person&& other) noexcept = delete;

    // Verschiebezuweisungsoperator
    Person& operator=(Person&& other) noexcept = delete;

    // Destruktor ==============================================================
    ~Person();

#pragma endregion KONSTRUKTOREN }


    // Getter & Setter ===========================================================
#pragma region GETTER & SETTER {

    // Deklaration der Getter ==================================================
    std::string getName() const;
    double getKontostand() const;
    static int getAnzahlPersonen();
    static const std::vector<Person*>& getAllePersonen();

    // Deklaration der Setter ==================================================
    void setName(const std::string &newName);
    void setKontostand(const double& newKontostand);

#pragma endregion GETTER & SETTER }


    // Klassen-Methoden ========================================================
    void dining(Location& location);
    double vomMenueAussuchen(const std::map<std::string, double>& menue);
    void kontostandAktualisieren(const double& preis);
    static void printAllePersonen();

};

#endif // PERSON_H
