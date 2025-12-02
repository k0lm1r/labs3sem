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
    out << " | " << std::setw(19) << cart.speed;
    out << "| " << std::setw(17) << cart.costPerPass;
    out << "| " << std::setw(17) << cart.costPerKg;
    out << "| " << std::setw(17) << cart.maxPass;
    out << "| " << std::setw(20) << cart.maxWeight;
    out << "| " << cart.hasCover << std::endl;

    return out;
}

std::istream& operator>>(std::istream& is, Cart& cart) {
    int maxPass;
    double maxWeight;

    cart.speed = SafeInput::inputDigit(is, "Введите скорость повозки:", 0, 30);
    cart.costPerPass = SafeInput::inputDigit(is, "Введите цену перевозки пассажиров:", 0);
    cart.costPerKg = SafeInput::inputDigit(is, "Введите цену перевозки грузов:", 0);
    cart.maxPass = SafeInput::inputDigit(is, "Введите максимальное число пассажиров:", 0, 8);
    cart.maxWeight = SafeInput::inputDigit(is, "Введите максимальный перевозимый вес:", 0, 2000);
    cart.hasCover = SafeInput::inputDigit(is, "Имеет ли повозка крышу?\n1 - Да\n2 - Нет", 0, 1);
    
    return is;
}