#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <map>
#include <vector>


class Location
{
private:
    // Klassenattribute nach Vorgabe festgelegt ==================================
    std::string name_;
    std::map<std::string, double> angebot_;
    double einnahmen_ = 0;
    inline static int anzahlLocations_ = 0; // mit inline kann man hier bereits deklarieren
    static std::vector<Location*> alleLocationsVector_;

public:
// Konstruktoren =============================================================
#pragma region KONSTRUKTOREN {

    // Konstruktor nach Vorgabe "Name & Menue über Konstruktor zuweisen" =========
    Location(const std::string& name, const std::map<std::string, double>& angebot);

    // Rule of 5 =================================================================
    // Kopierkonstruktor
    Location(const Location& other);

    // Kopierzuweisungsoperator
    Location& operator=(const Location& other);

    // Verschiebeonstruktor
    Location(Location&& other) noexcept;

    // Verschiebezuweisungsoperator
    Location& operator=(Location&& other) noexcept = delete;

    // Destruktor ================================================================
    ~Location();

#pragma endregion KONSTRUKTOREN }


    // Getter & Setter ===========================================================
#pragma region GETTER & SETTER {

    // Deklaration der Getter ====================================================
    std::string getName() const;
    std::map<std::string, double> getAngebot() const;
    double getEinnahmen() const;
    static int getAnzahlLocations();
    static const std::vector<Location*>& getAlleLocations();

    // Deklaration der Setter ---------------------------------------------------
    void setName(const std::string &newName);
    void setAngebot(const std::map<std::string, double> &newAngebot);
    void setEinnahmen(const double& newEinnahmen);

#pragma endregion GETTER & SETTER }


    // Klassen-Methoden ==========================================================
#pragma region METHODEN {

    virtual void showAngebot() const;
    // NUR HIER muss virtual hin wenn vererbt werden soll!!!

    static void printAlleLocations();

#pragma endregion METHODEN }


    // Operatorüberladungen ====================================================
    Location operator+(const Location& anderer) const;

};

#endif // LOCATION_H
