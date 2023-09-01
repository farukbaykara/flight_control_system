#ifndef AIRPORT_HPP
#define AIRPORT_HPP

#include "PersonelFactory.hpp"
#include "Plane.hpp"
#include "Airdock.hpp"

class Airport{

private:
    
    struct Time{
        int day;
        int month;
        int year;
    };


    struct Flight{
        int id;
        std::string constructor;
        std::string model;
        int capacity;
        int range;
        CabinCrew cabin_crew;
        Pilot pilot;
        Time departure;
    }



public:
    std::string name_;
    std::vector<Flight> flights_;
    std::vector<GroundService> ground_service_crew_;
    Airdock air_dock_;
    bool is_airdock_active_;
    Airport(std::string city,std::vector<Flight> flight,std::vector<GroundService> ground_service,Airdock air_dock,bool airdock_active):
        name_(city),flights_(flight),ground_service_crew_(ground_service),air_dock_(air_dock),is_airdock_active_(airdock_active){};

    void displayInfo() const{

        std::cout << "Airport information - Name: " << name_ << std::endl;
        for (auto flight : flights_){
            
            std::cout<<"ID:"<<flight.id<<std::endl;
            std::cout<<"Constructor:"<<flight.constructor<<std::endl;

            std::cout<<"Model:"<<flight.model<<std::endl;

            std::cout<<"Capacity:"<<flight.capacity<<std::endl;

            std::cout<<"Range:"<<flight.range<<std::endl;

            std::cout<<"Cabin Crew:"<<std::endl;

            flight.cabin_crew.displayInfo();

            std::cout<<"Pilot:"<<std::endl;

            flight.pilot.displayInfo();

            std::cout<<"Departure:"<<std::endl;

            std::cout<<"Day:"<<flight.departure.day<<std::endl;
            





        }
        for (auto ground_service : ground_service_crew_){
            ground_service.displayInfo();
        }
        air_dock_.displayInfo();
        std::cout << "Airdock active: " << is_airdock_active_ << std::endl;


    }


};


#endif //PLANE_HPP
