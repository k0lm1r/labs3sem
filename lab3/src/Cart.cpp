#include "Cart.h"

void Cart::setMaxPass(int maxPass) {
    this->maxPass = maxPass <= 8 ? maxPass : 8; 
}
void Cart::setMaxWeight(double maxWeight) {
    this->maxWeight = maxWeight <= 2000 ? maxWeight : 2000;
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

    is >> cart.speed >> cart.costPerPass >> cart.costPerKg >> maxPass >> maxWeight;
    cart.setMaxPass(maxPass);
    cart.setMaxWeight(maxWeight);

    return is;
}