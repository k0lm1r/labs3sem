#include "Cart.h"

void Cart::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 8 ? maxPass : 8; 
}
void Cart::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 2000 ? maxWeight : 2000;
}

void Cart::printHeader() const {
    std::cout << " | " << std::left << std::setw(30) << "Максимальная скорость повозки";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для повозки";
    std::cout << "| " << std::left << std::setw(30) << "Цена перевозки груза для повозки";
    std::cout << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    std::cout << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";
}

void Cart::printTable() const {
    std::cout << " | " << std::left << std::setw(30) << speed;
    std::cout << "| " << std::left << std::setw(30) << costPerPass;
    std::cout << "| " << std::left << std::setw(30) << costPerKg;
    std::cout << "| " << std::left << std::setw(30) << maxPass;
    std::cout << "| " << std::left << std::setw(30) << maxWeight;
}

std::ostream& operator<<(std::ostream& out, const Cart& cart) {
    out << " | " << std::left << std::setw(30) << "Максимальная скорость машины";
    out << "| " << std::left << std::setw(30) << "Цена перевозки пассажиров для машины";
    out << "| " << std::left << std::setw(30) << "Цена перевозки груза для машины";
    out << "| " << std::left << std::setw(30) << "Максимальное число пассажиров";
    out << "| " << std::left << std::setw(30) << "Максимальный перевозимый вес";

    out << " | " << std::left << std::setw(30) << cart.speed;
    out << "| " << std::left << std::setw(30) << cart.costPerPass;
    out << "| " << std::left << std::setw(30) << cart.costPerKg;
    out << "| " << std::left << std::setw(30) << cart.maxPass;
    out << "| " << std::left << std::setw(30) << cart.maxWeight;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    int maxPass;
    double maxWeight;

    is >> cart.speed >> cart.costPerPass >> cart.costPerKg >> maxPass >> maxWeight;
    cart.setMaxPass(maxPass);
    cart.setMaxWeight(maxWeight);

    return is;
}