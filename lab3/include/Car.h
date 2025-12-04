#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
    int year;

    public:
        Car() = default;
        Car(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight, int year) 
            : Vehicle(speed, costPerPass, costPerKg, maxPass, maxWeight), year(year) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }
        Car(const Car& other) : Vehicle(other), year(year) {}
        ~Car() = default;

        int getYear() const;
        void setYear(int year);
        void printHeader() const override;
        void printTable() const override;
        bool operator==(const Car& other) const;

        friend std::ostream& operator<<(std::ostream& os, const Car& car);
        friend std::istream& operator>>(std::istream& is, Car& car);
};