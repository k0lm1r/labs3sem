#include "Cart.h"
#include <SafeInput.h>

bool Cart::isCovered() const {
    return this->hasCover;
}

void Cart::setHasCover(bool hasCover) {
    this->hasCover = hasCover;
}

void Cart::printTable() const {
    std::cout << " | " << std::setw(19) << this->speed;
    std::cout << "| " << std::setw(17) << this->costPerPass;
    std::cout << "| " << std::setw(17) << this->costPerKg;
    std::cout << "| " << std::setw(17) << this->maxPass;
    std::cout << "| " << std::setw(20) << this->maxWeight;
    std::cout << "| " << this->hasCover << std::endl;
}

void Cart::printHeader() const {
    std::cout << " | " << std::left << std::setw(19) << "Макс. скорость пов.";
    std::cout << "| "  << std::setw(17) << "Цена перев. пасс.";
    std::cout << "| "  << std::setw(17) << "Цена перев. груза";
    std::cout << "| "  << std::setw(17) << "Макс. число пасс.";
    std::cout << "| " << std::setw(20) << "Макс. перевозимый вес";
    std::cout << "| " << "Имеет крышу" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cart& cart) {
    out << static_cast<const Vehicle&>(cart);
    out << "| " << cart.hasCover << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    is >> static_cast<Vehicle&>(cart);
    int coverChoice = SafeInput::inputDigit(is, "Имеет ли повозка крышу?\n1 - Да\n2 - Нет", 1, 2);
    cart.hasCover = coverChoice == 1 ? 1 : 0;
    return is;
}