#include "Car.h"
#include "SafeInput.h"

void Car::setMaxPass(int maxPass) {
    this->maxPass = maxPass; 
}
void Car::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight;
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

    car.speed = SafeInput::inputDigit(is, "Введите скорость автомобиля:", 0, 400);
    car.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    car.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 5);
    maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 1500);

    car.setMaxPass(maxPass);
    car.setMaxWeight(maxWeight);

    return is;
}