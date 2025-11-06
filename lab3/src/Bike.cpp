#include "Bike.h"

void Bike::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 2 ? maxPass : 2; 
}
void Bike::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 200 ? maxWeight : 200;
}

void Bike::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| "  << std::setw(30) << costPerPass;
    std::cout << "| "  << std::setw(30) << costPerKg;
    std::cout << "| "  << std::setw(30) << maxPass;
    std::cout << "| "  << std::setw(30) << maxWeight;
}

void Bike::printHeader() const {
    std::cout << " | " << std::left << std::setw(19) << "Макс. скорость вел.";
    std::cout << "| " << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| " << std::setw(17) << "Цена перев. груза";
    std::cout << "| " << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << "Макс. перевозимый вес" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    out << " | " << std::setw(19) << bike.speed;
    out << "| " << std::setw(17) << bike.costPerPass;
    out << "| " << std::setw(17) << bike.costPerKg;
    out << "| " << std::setw(17) << bike.maxPass;
    out << "| " << bike.maxWeight << std::endl;

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