#include "Bike.h"
#include <SafeInput.h>

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

    bike.speed = SafeInput::inputDigit(is, "Введите скорость велосипеда:", 0, 30);
    bike.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    bike.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 2);
    maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 200);

    bike.setMaxPass(maxPass);
    bike.setMaxWeight(maxWeight);

    return is;
}