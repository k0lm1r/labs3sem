#pragma once
#include <iostream>
#include <iomanip>

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

        friend std::ostream& operator<<(std::ostream& os, const Vehicle& car);
};