#include "Bike.h"
#include "Car.h"
#include "Cart.h"
#include "Deque.h"
#include "SafeInput.h"
#include "Exceptions.h"

void printVehicleHeader() {
    Vehicle v;
    v.printHeader();
}

void printAllVehicles(const Car& car, const Cart& cart, const Bike& bike) {
    car.printHeader();
    std::cout << car;
    cart.printHeader();
    std::cout << cart;
    bike.printHeader();
    std::cout << bike;
}

void demanstrateAllSortings(Deque<Vehicle>& vehicleDeque) {
    printVehicleHeader();
    vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getSpeed() > b.getSpeed(); });
    std::cout << "Отсортированая по скорости транспорта очередь:\n" << vehicleDeque << std::endl;
    printVehicleHeader();
    vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getCostPerPass() > b.getCostPerPass(); });
    std::cout << "Отсортированая по цене перевозки пассажира очередь:\n" << vehicleDeque << std::endl;
    printVehicleHeader();
    vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getCostPerKg() > b.getCostPerKg(); });
    std::cout << "Отсортированая по цене перевозки груза очередь:\n" << vehicleDeque << std::endl;
    printVehicleHeader();
    vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getMaxPass() > b.getMaxPass(); });
    std::cout << "Отсортированая по числу пассажиров очередь:\n" << vehicleDeque << std::endl;
    printVehicleHeader();
    vehicleDeque.sort([](const Vehicle& a, const Vehicle& b) { return a.getMaxWeight() > b.getMaxWeight(); });
    std::cout << "Отсортированая по перевозимому весу очередь:\n" << vehicleDeque << std::endl;
}

int main() {
    int choice = 1;
    
    while (choice != 2) {    
        Car car;
        Cart cart;
        Bike bike;
        bool allWereFilled = false;
        
        while(!allWereFIlled) {
            try {
                SafeInput::input(std::cin, car, "Введите информацию об автомобиле:");
                SafeInput::input(std::cin, cart, "Введите информацию о повозке:");
                SafeInput::input(std::cin, bike, "Введите информацию о велосипеде:");
                allWereFilled = true;
            } catch (const InputException& e) {
                std::cout << e.what();
            }
        }
        
        Deque<Vehicle> vehicleDeque;
        vehicleDeque.addLast(car);
        vehicleDeque.addLast(cart);
        vehicleDeque.addLast(bike);

        printVehicleHeader();
        std::cout << vehicleDeque << std::endl;
        std::cout << "Транспорт, скорость которого больше 2 км/ч:\n" << vehicleDeque.find([](const Vehicle& a) {return a.getSpeed() > 2; } );
        
        demanstrateAllSortings(vehicleDeque);

        int distance, pass;
        double weight;

        std::cout << "Введите число пассажиров, расстояние и массу груза:" << std::endl;

        allWereFilled = false;
        while (!allWereFilled) {    
            try {
                distance = SafeInput::inputDigit(std::cin);
                pass = SafeInput::inputDigit(std::cin);
                weight = SafeInput::inputDigit(std::cin);
                allWereFilled = true;
            } catch (const InputException& e) {
                std::cout << e.what() << std::endl;
            }
        }

        std::cout << "Цена перевозки пассажиров и грузов на машине: " 
            << car.calculateCostPassengers(distance, pass) << " " 
            << car.calculateCostWeight(distance, weight) << std::endl;

        printAllVehicles(car, cart, bike);

        std::cout << "Повторить?\n1 - Да\n2 - Нет." << std::endl;
        std::cin >> choice;
    }

}