#ifndef PLANE_HPP
#define PLANE_HPP

#include "PersonelFactory.hpp"



class Plane {

private:

    int id;
    std::string constructor;
    std::string model;
    int capacity;
    int range;


public:
    Plane(int id, std::string constructor, std::string model, int capacity, int range)
        : id(id), constructor(constructor), model(model), capacity(capacity), range(range) {};

    Plane() = default;

    void displayInfo() const {
        std::cout << "Plane information - ID: " << id << ", Constructor: " << constructor << ", Model: " << model << ", Capacity: " << capacity << ", Range: " << range << std::endl;
    }

    int getId() const {
        return id;
    }

    const std::string& getConstructor() const {
        return constructor;
    }

    const std::string& getModel() const {
        return model;
    }

    int getCapacity() const {
        return capacity;
    }

    int getRange() const {
        return range;
    }

    //Set functions
    void setId(int id){
        id = id;
    }

    void setConstructor(std::string constructor){
        constructor = constructor;
    }

    void setModel(std::string model){
        model = model;
    }

    void setCapacity(int capacity){
        capacity = capacity;
    }

    void setRange(int range){
        range = range;
    }



};


#endif //PLANE_HPP
