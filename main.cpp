#include "person.h"     
#include "restaurant.h"
#include <iostream>

// menue e.g. https://www.youtube.com/watch?v=GNZC1gXFaiU&t=624s

using namespace std;

int main()
{   // creation of two customers
    { // creating a scope for the constructors to check if the static variable anzahlLocations resets 
      // to 0 after exiting the scope using a static method
        Person Adalbert ("Friedknecht");
        Person Kloberella ("Kriemhilde", 1337);
        std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

        Restaurant Fuzo ("Fusion Zone", {
                                            {"Bun Bo Nam Bo", 16.90},
                                            {"Chicken Bao", 13.90},
                                            {"Curyy Tofu", 14.90}
                                         },10); // 10 is for seats, new attribute after inheritance

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

    } // scope is left, objects destroyed with destructor

    // control if destructor and counters worked
    std::cout << "Anzahl der Locations: " << Location::getAnzahlLocations() << std::endl;
    std::cout << "Anzahl der Personen: " << Person::getAnzahlPersonen() << std::endl;
    Person::printAllePersonen();
    Location::printAlleLocations();
    std::cout << "\n-----------------------------------------------------------------\n" << std::endl;

    return 0;
}
