#include "Car.h"
#include "SafeInput.h"

int Car::getYear() const {
    return this->year;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::printTable() const {
    Vehicle::printTable();
    std::cout << "| " << this->year;
}

void Car::printHeader() const {
    Vehicle::printHeader();
    std::cout << "| " << "Год выпуска";
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << static_cast<const Vehicle&>(car);
    out << "| " << car.year;

    return out;
}

std::istream& operator>>(std::istream& is, Car& car) {
    is >> static_cast<Vehicle&>(car);
    car.year = SafeInput::inputDigit(is, "Введите год выпуска:", 1950, 2025);
    return is;
}