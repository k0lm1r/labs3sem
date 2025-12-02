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
    out << " | " << std::left << std::setw(19) << car.speed;
    out << "| " << std::setw(17) << car.costPerPass;
    out << "| " << std::setw(17) << car.costPerKg;
    out << "| " << std::setw(17) << car.maxPass;
    out << "| " << std::setw(20) << car.maxWeight;
    out << "| " << car.year << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Car& car) {
    int maxPass;
    double maxWeight;

    car.speed = SafeInput::inputDigit(is, "Введите скорость автомобиля:", 0, 400);
    car.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    car.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    car.maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 5);
    car.maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 1500);
    car.year = SafeInput::inputDigit(is, "Введите год выпуска:", 1950, 2025);

    return is;
}