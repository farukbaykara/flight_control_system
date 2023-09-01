#ifndef CITY_HPP
#define CITY_HPP

#include "AirPort.hpp"


class City{

private:

    std::string name_;
    std::vector<Airport> airports_;
    

public:
    // City(std::string name, std::vector<Airport> airports):
    //     name_(name), airports_(airports){};

    City(std::string name,std::vector<Airport> airport):
        name_(name), airports_(airport){};

    void displayInfo() const{

        std::cout << "City information - Name: " << name_ << std::endl;
        for (auto airport : airports_){
            airport.displayInfo();
        }

    }

    void is_airdock_active(Maintenance::MaintenanceTypeLicence maint_type,int day,int month, int year){

        if(airports_[0].air_dock_.getAppliableMaintenance()>=maint_type){
            
            if(airports_[0].air_dock_.maintenance_crew_.size()>0){
                std::cout<<"Airdock is available"<<std::endl;
                airports_[0].air_dock_.displayInfo();
            }
            else{
                std::cout<<"Airdock is available, but there are no maintenance crew"<<std::endl;

            }
        }
        else{
            std::cout<<"There is no air dock "<<std::endl;
        }


    }
    
    void isFlightAvailable();



};


#endif //CITY_HPP
