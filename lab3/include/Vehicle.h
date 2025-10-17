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
        Vehicle(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight) : speed(speed), costPerPass(costPerPass), costPerKg(costPerKg) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }

        virtual ~Vehicle() = default;

        double getSpeed() const;
        double getCostPerPass() const;
        double getCostPerKg() const;
        int getMaxPass() const;
        double getMaxWeight() const;
        void setSpeed(double speed);
        void setCostPerPass(double costPerPass);
        void setCostPerKg(double costPerKg);
        virtual void setMaxPass(int maxPass);
        virtual void setMaxWeight(double maxWeight);


        double calculateCostPassengers(double distance, int passengersCount) const;
        double calculateCostWeight(double distance, double weight) const;

        virtual void printHeader() const;
        virtual void printTable() const;
};