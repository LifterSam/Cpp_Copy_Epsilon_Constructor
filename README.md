Hello,

this is a short presentation on inheritance and `Copy Epsilon Optimization`. In the location.cpp starting at 
line 34 a move constructor is defined. The compilers `Copy Epsilon` deactivates this constructor completely
so even though a `std::cout` is called there the `std::cout` is never shown in the terminal. The compiler 
just optimizes the code and spares the move constructor completely. If you `=delete` the move constructor
in the header file the code can not be compiled though, so there is proof that the move constructor is 
actually used even though no `std::cout` for control is shown.

If you want to see the `std::cout` you need to include the line:

`target_compile_options(OOP_Cpp_Location_Restaurant PRIVATE -fno-elide-constructors)`

into the cmake file. Thus the Copy Epsilon Optimization is deactivated for testing and you can see
the `std:cout` now. To show where it has to be put in i have included my cmake file. Note that you have
to generate your own build for all of this code on your prefered machine. You mostly will not be able to use
the cmake-file presented here.

The code itself evolves around creating three classes: Person, Location and Restaurant inheriting from Location.

- In Person, the following attributes are defined:
A name, which is assigned via the constructor.
An account balance, initialized to 100.

- Additionally, a Dining method is implemented:
It takes a Location as an argument.
The method displays the menu of the given Location.
When the person selects a menu item, the corresponding price is deducted from their account balance and added to the Location's revenue.

- In Location, the following attributes are defined:
A name, assigned via the constructor.
A menu, also assigned via the constructor.
The menu is stored in a suitable container that maps dish names to their prices.
Revenue, initialized to 0.

- A Show_Menu method is included:
It displays the menu to the guest.

- The Rule of Five is implemented:
In Person, all copy and move constructors are disabled.
In Location, only move constructors are disabled.
A static counter variable is used in each class within the constructors and destructors.
The + operator is overloaded in Location to merge two menus.
A function is included that returns a vector of n instances of either Person or Location.
Regarding inheritance, Location serves as the base class for Restaurant.

Best regards
Thomas
