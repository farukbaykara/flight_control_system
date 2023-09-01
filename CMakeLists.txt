cmake_minimum_required(VERSION 3.10)

project(FlightControl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(include)

find_package (SQLite3)


find_package (Eigen3 3.3 REQUIRED NO_MODULE)


include_directories(${SQLITE3_INCLUDE_DIRS})

set(TARGET_SRC
    src/main.cpp
    )

add_library(sqlite_src 
    src/shell.c
    src/sqlite3.c)



set(TARGET_HEADER
    include/Personel.hpp
    include/PersonelFactory.hpp
    include/Plane.hpp
    include/Airdock.hpp
    include/AirPort.hpp
    include/City.hpp
    include/sqlite3.h
    include/sqlite3ext.h
    include/FlightGraph.hpp
    )

add_executable(flight_control_exe 
    ${TARGET_SRC}
    ${TARGET_HEADER}
    )

target_link_libraries(flight_control_exe
    sqlite_src 
    ${SQLITE3_LIBRARIES})
