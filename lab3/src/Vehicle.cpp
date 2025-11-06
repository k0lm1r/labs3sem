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

void Vehicle::setMaxPass(int maxPass) {
    this->maxPass = maxPass; 
}
void Vehicle::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight;
}

void Vehicle::printTable() const {
    std::cout << " | " << std::setw(18) << speed;
    std::cout << "| " << std::setw(17) << costPerPass;
    std::cout << "| " << std::setw(17) << costPerKg;
    std::cout << "| " << std::setw(17) << maxPass;
    std::cout << "| " << maxWeight << std::endl;
}

void Vehicle::printHeader() const {
    std::cout << " | " << std::left << std::setw(18) << "Макс. скорость т/с";
    std::cout << "| " << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| " << std::setw(17) << "Цена перев. груза";
    std::cout << "| " << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << "Макс. перевозимый вес" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Vehicle& vehicle) {
    out << " | " << std::setw(18) << vehicle.speed;
    out << "| " << std::setw(17) << vehicle.costPerPass;
    out << "| " << std::setw(17) << vehicle.costPerKg;
    out << "| " << std::setw(17) << vehicle.maxPass;
    out << "| " << vehicle.maxWeight << std::endl;
    return out;
}

double Vehicle::calculateCostPassengers(double distance, int passengersCount) const {
    if (passengersCount > maxPass) return distance * maxPass * costPerPass;
    return distance * passengersCount * costPerPass;
}

double Vehicle::calculateCostWeight(double distance, double weight) const {
    if (weight > maxWeight) return distance * maxWeight * costPerKg;
    return distance * weight * costPerKg;
}