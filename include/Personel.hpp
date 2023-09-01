#ifndef PERSONEL_HPP
#define PERSONEL_HPP


class Personel {
public:
    virtual void displayInfo() const = 0;
};

class Pilot : public Personel {

public:
    enum Licence{
        ATPL = 1,
        CPL = 2,
        PPL = 3,
        JAR_FCL = 4,
        NR = 5
    };


    Pilot(const std::string& name, int experienceYears, Licence licence)
        : name(name), experienceYears(experienceYears),licence_(licence) {}

    void displayInfo() const override {
        std::cout << "Pilot information - Name: " << name << ", Experience: " << experienceYears << " years, Licence: " << licence_ << std::endl;
    }




private:
    std::string name;
    int experienceYears;
    Licence licence_;


};

class CabinCrew : public Personel {
public:

    enum Roles{
        CrewMember, Purser
    };



    CabinCrew(const std::string& name, Roles role)
        : name(name), role_(role) {}

    void displayInfo() const override {
        std::cout << "Cabin Crew information - Name: " << name << ", Role: " << role_ << std::endl;
    }

private:
    std::string name;
    Roles role_;
};

class GroundService : public Personel {
public:

    enum Job{
        Fuelling,
        Baggage,
        Cleaner,
        Cargo,
        Catering
    };


    GroundService(const std::string& name, Job jobType)
        : name(name), jobType_(jobType) {}

    void displayInfo() const override {
        std::cout << "Ground Service information - Name: " << name << ", Job Title: " << jobType_ << std::endl;
    }

private:
    std::string name;
    Job jobType_;
};

class Maintenance : public Personel {
public:

    enum MaintenanceTypeLicence{
        A,
        B1,
        B2,
        C
    };

    Maintenance(const std::string& name, MaintenanceTypeLicence licence)
        : name(name), licence_(licence) {}

    void displayInfo() const override {
        std::cout << "Maintenance information - Name: " << name << ", Specialization: " << licence_ << std::endl;
    }

private:
    std::string name;
    MaintenanceTypeLicence licence_;
};


#endif //PERSONEL_HPP
