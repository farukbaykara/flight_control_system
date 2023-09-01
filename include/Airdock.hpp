//Create a hpp file for airdock of airport 

// Path: include/Airdock.hpp


#ifndef AIRDOCK_HPP
#define AIRDOCK_HPP

#include "PersonelFactory.hpp"

class Airdock{

    private:


    public:
            Maintenance::MaintenanceTypeLicence appliable_maintenances_;
        std::vector<Maintenance> maintenance_crew_;
        Airdock(Maintenance::MaintenanceTypeLicence maintenance_type, std::vector<Maintenance> crew):
            appliable_maintenances_(maintenance_type), maintenance_crew_(crew){};

        void setAppliableMaintenance(Maintenance::MaintenanceTypeLicence appliable_maintenances){
            appliable_maintenances_ = appliable_maintenances;
        }

        Maintenance::MaintenanceTypeLicence getAppliableMaintenance() const{
            return appliable_maintenances_;
        }

        void displayInfo() const{
            std::cout << "Airdock information - Appliable Maintenance: " << appliable_maintenances_ << std::endl;
        }

};


#endif //AIRDOCK_HPP

