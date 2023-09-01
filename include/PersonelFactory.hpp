#ifndef PERSONEL_FACTORY_HPP
#define PERSONEL_FACTORY_HPP

#include "Personel.hpp"

class PersonelFactory {
public:
    std::unique_ptr<Personel> createPilot(const std::string& name, int experienceYears, Pilot::Licence licence) {
        return std::make_unique<Pilot>(name, experienceYears,licence);
    }

    std::unique_ptr<Personel> createCabinCrew(const std::string& name,  CabinCrew::Roles role) {
        return std::make_unique<CabinCrew>(name, role);
    }

    std::unique_ptr<Personel> createGroundService(const std::string& name, GroundService::Job jobTitle) {
        return std::make_unique<GroundService>(name, jobTitle);
    }

    std::unique_ptr<Personel> createMaintenance(const std::string& name, Maintenance::MaintenanceTypeLicence licence) {
        return std::make_unique<Maintenance>(name, licence);
    }
};


#endif //PERSONEL_FACTORY_HPP
