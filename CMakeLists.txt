cmake_minimum_required(VERSION 3.16)

project(OOP_Cpp_Location_Restaurant LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OOP_Cpp_Location_Restaurant main.cpp
    location.cpp location.h main.cpp person.cpp person.h restaurant.cpp restaurant.h
    Location_Aufgabe)

# add Cope Epsilon Deactivation here, after add_executable
target_compile_options(OOP_Cpp_Location_Restaurant PRIVATE -fno-elide-constructors)

include(GNUInstallDirs)
install(TARGETS OOP_Cpp_Location_Restaurant
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
