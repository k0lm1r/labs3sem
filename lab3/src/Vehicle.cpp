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

void Vehicle::printHeader() const {
    std::cout << " | " << std::left << std::setw(5) << "Максимальная скорость транспорта";
    std::cout << "| " << std::left << std::setw(5) << "Цена перевозки пассажиров для транспорта";
    std::cout << "| " << std::left << std::setw(5) << "Цена перевозки груза для транспорта";
    std::cout << "| " << std::left << std::setw(5) << "Максимальное число пассажиров";
    std::cout << "| " << std::left << std::setw(5) << "Максимальный перевозимый вес";
}

void Vehicle::printTable() const {
    std::cout << " | " << std::left << std::setw(5) << speed;
    std::cout << "| " << std::left << std::setw(5) << costPerPass;
    std::cout << "| " << std::left << std::setw(5) << costPerKg;
    std::cout << "| " << std::left << std::setw(5) << maxPass;
    std::cout << "| " << std::left << std::setw(5) << maxWeight;
}

double Vehicle::calculateCostPassengers(double distance, int passengersCount) const {
    if (passengersCount > maxPass) return distance * maxPass * costPerPass;
    return distance * passengersCount * costPerPass;
}

double Vehicle::calculateCostWeight(double distance, double weight) const {
    if (weight > maxWeight) return distance * maxWeight * costPerKg;
    return distance * weight * costPerKg;
}

