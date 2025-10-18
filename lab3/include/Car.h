#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
    public:
        Car() = default;
        Car(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight) : Vehicle(speed, costPerPass, costPerKg) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }
        ~Car() = default;

        void setMaxPass(int maxPass) override;
        void setMaxWeight(double maxWeight) override;

        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& os, const Car& car);
        friend std::istream& operator>>(std::istream& is, Car& car);
};