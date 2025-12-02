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
    out << " | " << std::setw(20) << bike.speed;
    out << "| " << std::setw(17) << bike.costPerPass;
    out << "| " << std::setw(17) << bike.costPerKg;
    out << "| " << std::setw(17) << bike.maxPass;
    out << "| " << std::setw(17) << bike.maxWeight;
    out << "| " << bike.gears << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Bike& bike) {
    bike.speed = SafeInput::inputDigit(is, "Введите скорость велосипеда:", 0, 30);
    bike.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    bike.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    bike.maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 2);
    bike.maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 200);
    bike.gears = SafeInput::inputDigit(is, "Введите число передач:", 0, 5);

    return is;
}