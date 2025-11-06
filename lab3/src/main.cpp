#include "Bike.h"
#include "Car.h"
#include "Cart.h"
#include "Deque.h"

int main() {
    int choice = 1;

    while (choice != 2) {    
        Car car;
        Cart cart;
        Bike bike;

        std::cin >> car;
        std::cin >> cart;
        std::cin >> bike;

        Deque<Vehicle> vehicleDeque;
        vehicleDeque.addLast(car);
        vehicleDeque.addLast(cart);
        vehicleDeque.addLast(bike);

        Vehicle v;
        v.printHeader();
        std::cout << vehicleDeque << std::endl;
        std::cout << "Транспорт, скорость которого больше 2 км/ч:\n" << vehicleDeque.find([](const Vehicle& a) {return a.getSpeed() > 2; } );
        vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getSpeed() > b.getSpeed(); });
        std::cout << "Отсортированаая по скорости транспорта очередь:\n" << vehicleDeque << std::endl;

        int distance, pass;
        double weight;
        std::cout << "Введите число пассажиров, расстояние и массу груза:" << std::endl;
        std::cin >> pass >> distance >> weight;
        std::cout << "Цена перевозки пассажиров и грузов на машине: " << car.calculateCostPassengers(distance, pass) << " " << car.calculateCostWeight(distance, weight) << std::endl;

        car.printHeader();
        std::cout << car;
        cart.printHeader();
        std::cout << cart;
        bike.printHeader();
        std::cout << bike;

        std::cout << "Повторить?\n1 - Да\n2 - Нет." << std::endl;
        std::cin >> choice;
    }

}