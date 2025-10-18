#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
    public:
        Bike() = default;
        Bike(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight) : Vehicle(speed, costPerPass, costPerKg) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }
        ~Bike() = default;


        void setMaxPass(int maxPass) override;
        void setMaxWeight(double maxWeight) override;

        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& out, const Bike& bike);
        friend std::istream& operator>>(std::istream& is, Bike& bike);
};