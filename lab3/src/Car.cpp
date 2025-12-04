#include "Car.h"
#include "SafeInput.h"

int Car::getYear() const {
    return this->year;
}

void Car::setYear(int year) {
    this->year = year;
}

void Car::printTable() const {
    std::cout << " | " << std::left << std::setw(19) << this->speed;
    std::cout << "| " << std::setw(17) << this->costPerPass;
    std::cout << "| " << std::setw(17) << this->costPerKg;
    std::cout << "| " << std::setw(17) << this->maxPass;
    std::cout << "| " << std::setw(20) << this->maxWeight;
    std::cout << "| " << this->year << std::endl;
}

void Car::printHeader() const {
    std::cout << " | " << std::left << std::setw(19) << "Макс. скорость авт.";
    std::cout << "| " << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| " << std::setw(17) << "Цена перев. груза";
    std::cout << "| " << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << std::setw(20) << "Макс. перевозимый вес";
    std::cout << "| " << "Год выпуска" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << static_cast<const Vehicle&>(car);
    out << "| " << car.year << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Car& car) {
    is >> static_cast<Vehicle&>(car);
    car.year = SafeInput::inputDigit(is, "Введите год выпуска:", 1950, 2025);
    return is;
}