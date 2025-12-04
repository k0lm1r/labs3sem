#pragma once
#include "Vehicle.h"

class Cart : public Vehicle {
    bool hasCover;
    public:
        Cart() = default;
        Cart(double speed, double costPerPass, double costPerKg, int maxPass, double maxWeight, bool hasCover) 
            : Vehicle(speed, costPerPass, costPerKg, maxPass, maxWeight), hasCover(hasCover) {
            setMaxPass(maxPass);
            setMaxWeight(maxWeight);
        }
        Cart(const Cart& other) : Vehicle(other), hasCover(other.hasCover) {}
        ~Cart() = default;

        bool isCovered() const;
        void setHasCover(bool hasCover);
        void printHeader() const override;
        void printTable() const override;

        friend std::ostream& operator<<(std::ostream& os, const Cart& cart);
        friend std::istream& operator>>(std::istream& is, Cart& cart);
};