#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
    int gears = 0;
    public:
        Bike() = default;
        Bike(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight, int gears) 
            : Vehicle(speed, costPerPass, costPerKg, maxPass, maxWeight), gears(gears) {}
        ~Bike() = default;

        int getGears() const;
        void setGears(int gears);
        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
        friend std::istream& operator>>(std::istream& is, Bike& bike);
};