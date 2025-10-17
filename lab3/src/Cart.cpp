#include "Cart.h"

void Cart::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 8 ? maxPass : 8; 
}
void Cart::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 2000 ? maxWeight : 2000;
}

void Cart::printHeader() const {
    std::cout << " | " << std::left << std::setw(5) << "Максимальная скорость повозки";
    std::cout << "| " << std::left << std::setw(5) << "Цена перевозки пассажиров для повозки";
    std::cout << "| " << std::left << std::setw(5) << "Цена перевозки груза для повозки";
    std::cout << "| " << std::left << std::setw(5) << "Максимальное число пассажиров";
    std::cout << "| " << std::left << std::setw(5) << "Максимальный перевозимый вес";
}

void Cart::printTable() const {
    std::cout << " | " << std::left << std::setw(5) << speed;
    std::cout << "| " << std::left << std::setw(5) << costPerPass;
    std::cout << "| " << std::left << std::setw(5) << costPerKg;
    std::cout << "| " << std::left << std::setw(5) << maxPass;
    std::cout << "| " << std::left << std::setw(5) << maxWeight;
}

std::ostream& operator<<(std::ostream& out, const Cart& cart) {
    out << " | " << std::left << std::setw(5) << "Максимальная скорость машины";
    out << "| " << std::left << std::setw(5) << "Цена перевозки пассажиров для машины";
    out << "| " << std::left << std::setw(5) << "Цена перевозки груза для машины";
    out << "| " << std::left << std::setw(5) << "Максимальное число пассажиров";
    out << "| " << std::left << std::setw(5) << "Максимальный перевозимый вес";

    out << " | " << std::left << std::setw(5) << cart.speed;
    out << "| " << std::left << std::setw(5) << cart.costPerPass;
    out << "| " << std::left << std::setw(5) << cart.costPerKg;
    out << "| " << std::left << std::setw(5) << cart.maxPass;
    out << "| " << std::left << std::setw(5) << cart.maxWeight;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    int maxPass;
    double maxWeight;

    is >> cart.speed >> cart.costPerPass >> cart.costPerKg >> maxPass >> maxWeight;
    cart.setMaxPass(maxPass);
    cart.setMaxWeight(maxWeight);
}