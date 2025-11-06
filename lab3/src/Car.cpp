#include "Car.h"

void Car::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 5 ? maxPass : 5; 
}
void Car::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 1500 ? maxWeight : 1500;
}

void Car::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| " << std::setw(30) << costPerPass;
    std::cout << "| " << std::setw(30) << costPerKg;
    std::cout << "| " << std::setw(30) << maxPass;
    std::cout << "| " << std::setw(30) << maxWeight;
}

void Car::printHeader() const {
    std::cout << " | " << std::left << std::setw(19) << "Макс. скорость авт.";
    std::cout << "| " << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| " << std::setw(17) << "Цена перев. груза";
    std::cout << "| " << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << "Макс. перевозимый вес" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << " | " << std::left << std::setw(19) << car.speed;
    out << "| " << std::setw(17) << car.costPerPass;
    out << "| " << std::setw(17) << car.costPerKg;
    out << "| " << std::setw(17) << car.maxPass;
    out << "| " << car.maxWeight << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Car& car) {
    int maxPass;
    double maxWeight;

    is >> car.speed >> car.costPerPass >> car.costPerKg >> maxPass >> maxWeight;
    car.setMaxPass(maxPass);
    car.setMaxWeight(maxWeight);

    return is;
}