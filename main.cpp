#include "person.h"     // person.h hat die location schon inkludiert, sonst kann
                        // diese nicht übergeben werden an interne Methode,
//#include "location.h" // deswegen muss location.h nicht in die main getan werden
#include "restaurant.h"
#include <iostream>

//Menue u.A. von https://www.youtube.com/watch?v=GNZC1gXFaiU&t=624s

using namespace std;

int main()
{   // Erstellen von zwei Kunden
    { // hier erstelle ich einen Geltungsbereich(?) für die Konstruktoren und weil ich mit der
        // statischen Methode prüfen will ob die statische Variable anzahlLocations wieder auf
        // 0 gesetzt wird nachdem Geltungsbereich verlassen wurde
        Person Adalbert ("Friedknecht");
        Person Kloberella ("Kriemhilde", 1337);
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        // Erstellen von Locations, ohne vorher eine Map einzeln zu erzeugen, sowie Operatorüberladung testen
        Restaurant Fuzo ("Fusion Zone", {
                                                                  {"Bun Bo Nam Bo", 16.90},
                                                                  {"Chicken Bao", 13.90},
                                                                  {"Curyy Tofu", 14.90}
                                                              },10);

        Location Gibier_Kishiiya ("Gibier Kishiiya", {
                                                        {"Geschmorte Schwarzbaerentatze", 1113.00},
                                                        {"Hirn vom Reh", 41.00}
                                                    });

        Location Zauou ("Fishing Restaurant Zauou", {
                                                       {"Lebender Hummer Sashimi", 105.00},
                                                       {"Tanzender Tintenfisch Sashimi", 78.00}
                                                   });

        Location kombinierteLocation = Fuzo + Gibier_Kishiiya;

        std::cout << std::endl;
        std::cout << "Anzahl der Locations: " << Location::getAnzahlLocations() << std::endl;
        std::cout << "Anzahl der Personen: " << Person::getAnzahlPersonen() << std::endl;
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;


        Fuzo.showAngebot();
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        kombinierteLocation.showAngebot();
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        Person::printAllePersonen();
        std::cout << std::endl;
        Location::printAlleLocations();
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        Adalbert.dining(Fuzo);
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        Person::printAllePersonen();
        std::cout << std::endl;
        Location::printAlleLocations();
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

    }// hier wird Scope verlassen und alle Elemente mit Destruktor automatisch zerstört

    // hier zur Kontrolle die Abfrage nach dem Status von Personen & Locations
    std::cout << "Anzahl der Locations: " << Location::getAnzahlLocations() << std::endl;
    std::cout << "Anzahl der Personen: " << Person::getAnzahlPersonen() << std::endl;
    Person::printAllePersonen();
    Location::printAlleLocations();
    std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

    return 0;
}
