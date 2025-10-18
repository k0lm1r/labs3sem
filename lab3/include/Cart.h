#pragma once
#include "Vehicle.h"

class Cart : public Vehicle {
    public:
        Cart() = default;
        Cart(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight) : Vehicle(speed, costPerPass, costPerKg) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }
        ~Cart() = default;

        void setMaxPass(int maxPass) override;
        void setMaxWeight(double maxWeight) override;

        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& os, const Cart& cart);
        friend std::istream& operator>>(std::istream& is, Cart& cart);
};