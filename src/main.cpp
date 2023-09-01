#include <iostream>
#include <memory>
#include "PersonelFactory.hpp"
#include <stdio.h>
#include<sqlite3.h>
#include <vector>
#include "City.hpp"
#include "FlightGraph.hpp"


struct Planes {
    int id;
    std::string constructor;
    std::string model;
    int capacity;
    int range;
};

std::vector<Planes> planes;

static int callback(void *data, int argc, char **argv, char **azColName) {
    std::vector<Planes> *planes = static_cast<std::vector<Planes> *>(data);
    
    Planes plane;
    plane.id = std::stoi(argv[0]);
    plane.constructor = argv[1];
    plane.model = argv[2];
    plane.capacity = std::stoi(argv[3]);
    plane.range = std::stoi(argv[4]);
    
    planes->push_back(plane);
    
    return 0;
}


int main() {
    PersonelFactory personelFactory;

    std::unique_ptr<Personel> pilot = personelFactory.createPilot("John Doe", 10,Pilot::Licence::PPL);
    std::unique_ptr<Personel> cabinCrew = personelFactory.createCabinCrew("Jane Smith", CabinCrew::Roles::CrewMember);
    std::unique_ptr<Personel> groundService = personelFactory.createGroundService("Mike Johnson", GroundService::Job::Cleaner);
    std::unique_ptr<Personel> maintenance = personelFactory.createMaintenance("Alex Brown", Maintenance::MaintenanceTypeLicence::C);

    pilot->displayInfo();
    cabinCrew->displayInfo();
    groundService->displayInfo();
    maintenance->displayInfo();


    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("../database/plane_db.db", &db);

    

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }


    const char *query = "SELECT * FROM Plane";
    char *errMsg;
    
    rc = sqlite3_exec(db, query, callback, &planes, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Planes in Database" << std::endl;
        
        for (const Planes &plane : planes) {
            std::cout << "ID: " << plane.id<< ", Constructor: " << plane.constructor << ", Model: " << plane.model
                      << ", Capacity: " << plane.capacity << ", Range: " << plane.range << std::endl;
        }
    }

    sqlite3_close(db);

    
    std::cout<<std::endl;
    Airdock airdock(Maintenance::MaintenanceTypeLicence::C,{});

    // Airport::Flight flight1;
    // flight1.id = planes[0].id;
    // flight1.constructor = planes[0].constructor;
    // flight1.model = planes[0].model;
    // flight1.capacity = planes[0].capacity;
    // flight1.range = planes[0].range;
    // flight1.cabin_crew = *static_cast<CabinCrew*>(cabinCrew.get());
    // flight1.pilot = *static_cast<Pilot*>(pilot.get());
    // flight1.departure.day = 3;
    // flight1.departure.month = 9;
    // flight1.departure.year = 2023;

    // std::vector<Airport::Flight> flights_airport1= {flight1};

    Airport airport1("Sabiha",{},{},airdock,true);
    Airport airport1_1("Istanbul",{},{},airdock,true);        
    Airport airport2("A-2",{},{},airdock,true);
    Airport airport3("A-3",{},{},airdock,true);
    Airport airport4("A-4",{},{},airdock,true);
    Airport airport5("A-5",{},{},airdock,true);        
    Airport airport6("A-6",{},{},airdock,true);
    Airport airport7("A-7",{},{},airdock,true);
    Airport airport8("A-8",{},{},airdock,true);
    Airport airport9("A-9",{},{},airdock,true);



    std::vector<Airport> airports1 = {airport1,airport1_1};
    std::vector<Airport> airports2 = {airport2};
    std::vector<Airport> airports3 = {airport3};
    std::vector<Airport> airports4 = {airport4};
    std::vector<Airport> airports5 = {airport5};
    std::vector<Airport> airports6 = {airport6};
    std::vector<Airport> airports7 = {airport7};
    std::vector<Airport> airports8 = {airport8};
    std::vector<Airport> airports9 = {airport8};




    
    
    City city1("Istanbul",airports1);




    FlightGraph flightGraph;

    // Havalimanlarını ekle
    flightGraph.addNode("Istanbul");
    flightGraph.addNode("Ankara");
    flightGraph.addNode("Izmir");
    flightGraph.addNode("Dubai");
    flightGraph.addNode("Sidney");
    flightGraph.addNode("Münich");
    flightGraph.addNode("New York");
    flightGraph.addNode("Rio de Janerio");


    // Uçuşları ekle
    flightGraph.addFlight("Istanbul", "Ankara", 350);
    flightGraph.addFlight("Istanbul", "Izmir", 330);
    flightGraph.addFlight("Istanbul", "Dubai", 3400);
    flightGraph.addFlight("Dubai", "Sidney", 11600);
    flightGraph.addFlight("Istanbul", "Münich", 1500);
    flightGraph.addFlight("Münich", "New York", 6700);
    flightGraph.addFlight("Istanbul", "Rio de Janerio", 9800);

    // Uçuşun varlığını kontrol et
    if (flightGraph.hasFlight("Istanbul", "Sidney") && city1.) {
        cout << "Flight is available." << endl;
        city1.displayInfo();
    } else {
        cout << "Flight is not available." << endl;
    }


    std::cout<<"Airdock Search"<<std::endl;

    city1.is_airdock_active(Maintenance::MaintenanceTypeLicence::C,10,10,2023);



    return 0;
}
