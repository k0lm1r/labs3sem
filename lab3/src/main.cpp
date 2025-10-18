#include "Bike.h"
#include "Car.h"
#include "Cart.h"

int main() {
    int choice = 1;

    while (choice != 2) {    
        Car car;
        Cart cart;
        Bike bike;

        std::cin >> car;
        std::cin >> cart;
        std::cin >> bike;

        int distance, pass;
        double weight;
        std::cout << "Введите число пассажиров, расстояние и массу груза:" << std::endl;
        std::cin >> pass >> distance >> weight;
        std::cout << "Цена перевозки пассажиров и грузов на машине: " << car.calculateCostPassengers(distance, pass) << " " << car.calculateCostWeight(distance, weight) << std::endl;

        std::cout << car;
        std::cout << cart;
        std::cout << bike;

        std::cout << "Повторить?\n1 - Да\n2 - Нет." << std::endl;
        std::cin >> choice;
    }

}