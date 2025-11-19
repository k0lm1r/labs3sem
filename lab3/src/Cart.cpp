#include "Cart.h"
#include <SafeInput.h>

void Cart::setMaxPass(int maxPass) {
    this->maxPass = maxPass; 
}
void Cart::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight;
}

void Cart::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| "  << std::setw(30) << costPerPass;
    std::cout << "| "  << std::setw(30) << costPerKg;
    std::cout << "| "  << std::setw(30) << maxPass;
    std::cout << "| "  << std::setw(30) << maxWeight;
}

void Cart::printHeader() const {
    std::cout << " | " << std::left << std::setw(19) << "Макс. скорость пов.";
    std::cout << "| "  << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| "  << std::setw(17) << "Цена перев. груза";
    std::cout << "| "  << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << "Макс. перевозимый вес" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cart& cart) {
    out << " | " << std::setw(19) << cart.speed;
    out << "| " << std::setw(17) << cart.costPerPass;
    out << "| " << std::setw(17) << cart.costPerKg;
    out << "| " << std::setw(17) << cart.maxPass;
    out << "| " << cart.maxWeight << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    int maxPass;
    double maxWeight;

    cart.speed = SafeInput::inputDigit(is, "Введите скорость повозки:", 0, 30);
    cart.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    cart.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 8);
    maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 2000);

    cart.setMaxPass(maxPass);
    cart.setMaxWeight(maxWeight);

    return is;
}