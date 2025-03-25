Hello,

This is a short presentation on inheritance after `Location_Aufgabe`, which contains a detailed 
description of what had to be done.

The clou here is the Copy Epsilon Optimization. In the location.cpp starting at line 34 a move constructor
is defined. The compilers `Copy Epsilon` deactivates this constructor completely so even though a `std::cout` is 
called there the `std::cout` is never shown in the terminal. The compiler just optimizes the code and spares 
the move constructor completely. If you `=delete` the move constructor in the header file the code can not be 
compiled though, so there is proof that the move constructor is actually used even though no `std::cout` for 
control is shown.

If you want to see the `std::cout` you need to include the line:

`target_compile_options(OOP_Cpp_Location_Restaurant PRIVATE -fno-elide-constructors)`

into the cmake file. Thus the Copy Epsilon Optimization is deactivated for testing and you can see
the `std:cout` now. To show where it has to be put in i have included my cmake file. Note that you have
to generate your own build for all of this code on your prefered machine. You mostly will not be able to use
the cmake-file presented here.

The rest of the code is a basic inheritance with some counters, a vector to save generated objects in,
some calculations. All the output is shown in the terminal. It is funny with some seriously delicious but also
weird and real food found in Germany and Japan hence the topic was to create restaurants.

Best regards
Thomas
