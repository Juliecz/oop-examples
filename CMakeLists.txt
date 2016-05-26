cmake_minimum_required(VERSION 3.3)
project(hotelReservation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Room.cpp Room.h Person.cpp Person.h Reservation.cpp Reservation.h Date.cpp Date.h Hotel.cpp Hotel.h priklady/Student.cpp priklady/Student.h priklady/Cislo.cpp priklady/Cislo.h priklady/Realne.cpp priklady/Komplexni.cpp  priklady/GumovePole.h)
add_executable(hotelReservation ${SOURCE_FILES})