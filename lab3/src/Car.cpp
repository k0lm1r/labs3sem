#include "Car.h"

void Car::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 5 ? maxPass : 5; 
}
void Car::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 1500 ? maxWeight : 1500;
}

void Car::printHeader() const {
    std::cout << " | " << std::left << std::setw(30) << "Максимальная скорость машины";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для машины";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки груза для машины";
    std::cout << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    std::cout << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";
}

void Car::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| " << std::left << std::setw(30) << costPerPass;
    std::cout << "| " << std::left << std::setw(30) << costPerKg;
    std::cout << "| " << std::left << std::setw(30) << maxPass;
    std::cout << "| " << std::left << std::setw(30) << maxWeight;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << " | " << std::left << std::setw(30) << "Максимальная скорость машины";
    out << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для машины";
    out << "| " << std::left << std::setw(30) << "Цена перевозки груза для машины";
    out << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    out << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";

    out << " | " << std::left << std::setw(30) << car.speed;
    out << "| " << std::left << std::setw(30) << car.costPerPass;
    out << "| " << std::left << std::setw(30) << car.costPerKg;
    out << "| " << std::left << std::setw(30) << car.maxPass;
    out << "| " << std::left << std::setw(30) << car.maxWeight;

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