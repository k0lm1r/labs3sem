#include "Bike.h"
#include <SafeInput.h>

int Bike::getGears() const {
    return this->gears;
}

void Bike::setGears(int gears) {
    this->gears = gears;
}

void Bike::printTable() const {
    Vehicle::printTable();
    std::cout << "| " << this->gears;
}

void Bike::printHeader() const {
    Vehicle::printHeader();
    std::cout << "| " << "Число передач";
}

std::ostream& operator<<(std::ostream& out, const Bike& bike) {
    out << static_cast<const Vehicle&>(bike);
    out << "| " << bike.gears;

    return out;
}

std::istream& operator>>(std::istream& is, Bike& bike) {
    is >> static_cast<Vehicle&>(bike);
    bike.gears = SafeInput::inputDigit(is, "Введите число передач:", 1, 6);
    return is;
}