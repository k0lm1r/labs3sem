#include "Bike.h"
#include <SafeInput.h>

int Bike::getGears() const {
    return this->gears;
}

void Bike::setGears(int gears) {
    this->gears = gears;
}

void Bike::printTable() const {
    std::cout << " | " << std::setw(20) << this->speed;
    std::cout << "| " << std::setw(17) << this->costPerPass;
    std::cout << "| " << std::setw(17) << this->costPerKg;
    std::cout << "| " << std::setw(17) << this->maxPass;
    std::cout << "| " << std::setw(17) << this->maxWeight;
    std::cout << "| " << this->gears << std::endl;
}

void Bike::printHeader() const {
    std::cout << " | " << std::left << std::setw(20) << "Макс. скорость вел.";
    std::cout << "| " << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| " << std::setw(17) << "Цена перев. груза";
    std::cout << "| " << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << std::setw(20) << "Макс. перевозимый вес";
    std::cout << "| " << "Число передач" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    out << static_cast<const Vehicle&>(bike);
    out << "| " << bike.gears << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Bike& bike) {
    is >> static_cast<Vehicle&>(bike);
    bike.gears = SafeInput::inputDigit(is, "Введите число передач:", 1, 6);
    return is;
}