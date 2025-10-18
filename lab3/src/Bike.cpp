#include "Bike.h"

void Bike::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 2 ? maxPass : 2; 
}
void Bike::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 200 ? maxWeight : 200;
}

void Bike::printHeader() const {
    std::cout << " | " << std::left << std::setw(30) << "Максимальная скорость велосипеда";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для велосипеда";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки груза для велосипеда";
    std::cout << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    std::cout << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";
}

void Bike::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| " << std::left << std::setw(30) << costPerPass;
    std::cout << "| " << std::left << std::setw(30) << costPerKg;
    std::cout << "| " << std::left << std::setw(30) << maxPass;
    std::cout << "| " << std::left << std::setw(30) << maxWeight;
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    out << " | " << std::left << std::setw(30) << "Максимальная скорость велосипеда";
    out << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для велосипеда";
    out << "| " << std::left << std::setw(30) << "Цена перевозки груза для велосипеда";
    out << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    out << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";

    out << " | " << std::left << std::setw(30) << bike.speed;
    out << "| " << std::left << std::setw(30) << bike.costPerPass;
    out << "| " << std::left << std::setw(30) << bike.costPerKg;
    out << "| " << std::left << std::setw(30) << bike.maxPass;
    out << "| " << std::left << std::setw(30) << bike.maxWeight;

    return out;
}

std::istream& operator>>(std::istream& is, Bike& bike) {
    int maxPass;
    double maxWeight;

    is >> bike.speed >> bike.costPerPass >> bike.costPerKg >> maxPass >> maxWeight;
    bike.setMaxPass(maxPass);
    bike.setMaxWeight(maxWeight);

    return is;
}