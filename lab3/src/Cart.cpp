#include "Cart.h"
#include <SafeInput.h>

bool Cart::isCovered() const {
    return this->hasCover;
}

void Cart::setHasCover(bool hasCover) {
    this->hasCover = hasCover;
}

void Cart::printTable() const {
    Vehicle::printTable();
    std::cout << "| " << this->hasCover;
}

void Cart::printHeader() const {
    Vehicle::printHeader();
    std::cout << "| " << "Имеет крышу";
}

std::ostream& operator<<(std::ostream& out, const Cart& cart) {
    out << static_cast<const Vehicle&>(cart);
    out << "| " << cart.hasCover;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    is >> static_cast<Vehicle&>(cart);
    int coverChoice = SafeInput::inputDigit(is, "Имеет ли повозка крышу?\n1 - Да\n2 - Нет", 1, 2);
    cart.hasCover = coverChoice == 1 ? 1 : 0;
    return is;
}