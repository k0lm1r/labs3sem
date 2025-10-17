#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
    public:
        using Vehicle::Vehicle;

        void setMaxPass(int maxPass) override;
        void setMaxWeight(double maxWeight) override;

        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& os, const Car& car);
        friend std::istream& operator>>(std::istream& is, Car& car);
};