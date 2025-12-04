#pragma once
#include <iostream>
#include <iomanip>
#include "SafeInput.h"

class Vehicle {
    protected:
        double speed;
        double costPerPass;
        double costPerKg;
        int maxPass;
        double maxWeight;

    public:
        Vehicle() = default;
        Vehicle(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight)
            : speed(speed), costPerPass(costPerPass), costPerKg(costPerKg), maxPass(maxPass), maxWeight(maxWeight) {}
        Vehicle(const Vehicle& other) 
            : speed(other.speed), costPerPass(other.costPerPass), costPerKg(other.costPerKg), maxPass(other.maxPass), maxWeight(other.maxWeight) {}
        virtual ~Vehicle() = default;

        double getSpeed() const;
        double getCostPerPass() const;
        double getCostPerKg() const;
        int getMaxPass() const;
        double getMaxWeight() const;
        void setSpeed(double speed);
        void setCostPerPass(double costPerPass);
        void setCostPerKg(double costPerKg);
        void setMaxPass(int maxPass);
        void setMaxWeight(double maxWeight);

        double calculateCostPassengers(double distance, int passengersCount) const;
        double calculateCostWeight(double distance, double weight) const;

        virtual void printHeader() const;
        virtual void printTable() const;

        friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
        friend std::istream& operator>>(std::istream& is, Vehicle& vehicle);
};