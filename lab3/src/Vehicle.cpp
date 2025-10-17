#include "Vehicle.h"

double Vehicle::getSpeed() const {
    return speed;
}

double Vehicle::getCostPerPass() const {
    return costPerPass;
}

double Vehicle::getCostPerKg() const {
    return costPerKg;
}

int Vehicle::getMaxPass() const {
    return maxPass;
}

double Vehicle::getMaxWeight() const {
    return maxWeight;
}

void Vehicle::setSpeed(double speed) {
    this->speed = speed;
}

void Vehicle::setCostPerPass(double costPerPass) {
    this->costPerPass = costPerPass;
}

void Vehicle::setCostPerKg(double costPerKg) {
    this->costPerKg = costPerKg;
}

double Vehicle::calculateCostPassengers(double distance, int passengersCount) const {
    if (passengersCount > maxPass) return distance * maxPass * costPerPass;
    return distance * passengersCount * costPerPass;
}

double Vehicle::calculateCostWeight(double distance, double weight) const {
    if (weight > maxWeight) return distance * maxWeight * costPerKg;
    return distance * weight * costPerKg;
}

