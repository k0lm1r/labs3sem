#include <iostream>
#include <iomanip>
#include <limits>
#include "SafeInput.h"
#include "Bike.h"
#include "Car.h"
#include "Cart.h"
#include "Deque.h"


void showMainMenu() {
    std::cout << "1.  Добавить в начало\n";
    std::cout << "2.  Добавить в конец\n";
    std::cout << "3.  Удалить с начала\n";
    std::cout << "4.  Удалить с конца\n";
    std::cout << "5.  Просмотреть первое\n";
    std::cout << "6.  Просмотреть последнее\n";
    std::cout << "7.  Вывести всю очередь\n";
    std::cout << "8.  Сортировать\n";
    std::cout << "9.  Поиск по минимальной вместимости пассажиров\n";
    std::cout << "10. Очистить очередь\n";
    std::cout << "0.  Выход\n";
    std::cout << "Выберите пункт: ";
}

Vehicle* createVehicleInteractively() {
    std::cout << "\nВыберите тип транспортного средства:\n";
    std::cout << "1. Велосипед\n2. Автомобиль\n3. Повозка\n";
    std::cout << "Ваш выбор: ";
    int type = (int)SafeInput::inputDigit(std::cin, "", 1, 3);

    switch (type) {
        case 1: {
            Bike *bike = new Bike();
            SafeInput::input(std::cin, *bike);
            return bike;
        } case 2: {
            Car *car = new Car();
            SafeInput::input(std::cin, *car);
            return car;
        } case 3: {
            Cart *cart = new Cart();
            SafeInput::input(std::cin, *cart);
            return cart;
        }
        default: return nullptr;
    }
}

void addToFront(Deque<Vehicle*>& deque) {
    Vehicle* v = createVehicleInteractively();
    deque.addFirst(v);
    std::cout << "Транспорт добавлен в начало очереди.\n";
}

void addToBack(Deque<Vehicle*>& deque) {
    Vehicle* v = createVehicleInteractively();
    deque.addLast(v);
    std::cout << "Транспорт добавлен в конец очереди.\n";
}

void removeFromFront(Deque<Vehicle*>& deque) {
    Vehicle* v = deque.takeFirst();
    std::cout << "Удалено из начала:\n";
    v->printHeader();
    v->printTable();
    delete v;
}

void removeFromBack(Deque<Vehicle*>& deque) {
    Vehicle* v = deque.takeLast();
    std::cout << "Удалено с конца:\n";
    v->printHeader();
    v->printTable();
    delete v;
}

void showFirst(const Deque<Vehicle*>& deque) {
    deque.peekFirst()->printHeader();
    deque.peekFirst()->printTable();
}

void showLast(const Deque<Vehicle*>& deque) {
    deque.peekLast()->printHeader();
    deque.peekLast()->printTable();
}

void showAllAsTable(const Deque<Vehicle*>& deque) {
    if (deque.isEmpty()) {
        std::cout << "Очередь пуста.\n";
    } else {
        ((Vehicle)*deque.peekFirst()).printHeader();
        std::cout << deque;
    }
}

void sortDeque(Deque<Vehicle*>& deque) {
    if (!deque.isEmpty()) {
        std::cout << "\n=== СОРТИРОВКА ===" << std::endl;
        std::cout << "1. По скорости (возрастание)" << std::endl;
        std::cout << "2. По скорости (убывание)" << std::endl;
        std::cout << "3. По стоимости за пассажира (возрастание)" << std::endl;
        std::cout << "4. По стоимости за пассажира (убывание)" << std::endl;
        std::cout << "5. По грузоподъемности (возрастание)" << std::endl;
        std::cout << "Выберите критерий: ";
        
        int sortChoice = SafeInput::inputDigit(std::cin, "", 1, 5);
        
        switch (sortChoice) {
            case 1: deque.sort([](const auto& a, const auto& b) { return a->getSpeed() > b->getSpeed(); }); break;
            case 2: deque.sort([](const auto& a, const auto& b) { return a->getSpeed() < b->getSpeed(); }); break;
            case 3: deque.sort([](const auto& a, const auto& b) { return a->getCostPerPass() > b->getCostPerPass(); }); break;
            case 4: deque.sort([](const auto& a, const auto& b) { return a->getCostPerPass() < b->getCostPerPass(); }); break;
            case 5: deque.sort([](const auto& a, const auto& b) { return a->getMaxWeight() > b->getMaxWeight(); }); break;
        }
        std::cout << "Дек отсортирован!" << std::endl;
    } else {
        std::cout << "Дек пуст!" << std::endl;
    }
}

void showSearch(Deque<Vehicle*>& deque) {
    std::cout << "\n=== ПОИСК ТРАНСПОРТА ===" << std::endl;
    std::cout << "1. По минимальной скорости" << std::endl;
    std::cout << "2. По максимальному количеству пассажиров" << std::endl;
    std::cout << "3. По максимальному весу" << std::endl;
    std::cout << "Выберите критерий: ";
    
    try {
        int choice = SafeInput::inputDigit(std::cin, "", 1, 3);
        Deque<Vehicle*> result;
        
        switch (choice) {
            case 1: {
                double minSpeed = SafeInput::inputDigit(std::cin, "Введите минимальную скорость: ", 0, 1000);
                result = deque.find([minSpeed](const auto& v) {
                    return v->getSpeed() >= minSpeed;
                });
                break;
            }
            case 2: {
                int minPassengers = SafeInput::inputDigit(std::cin, "Введите минимальное количество пассажиров: ", 1, 100);
                result = deque.find([minPassengers](const auto& v) {
                    return v->getMaxPass() >= minPassengers;
                });
                break;
            }
            case 3: {
                double minWeight = SafeInput::inputDigit(std::cin, "Введите минимальный вес: ", 0, 10000);
                result = deque.find([minWeight](const auto& v) {
                    return v->getMaxWeight() >= minWeight;
                });
                break;
            }
        }
        
        std::cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===" << std::endl;
        ((Vehicle)*deque.peekFirst()).printHeader();
        std::cout << deque;
    } catch (const Exception& e) {
        std::cout << "Ошибка при поиске: " << e.what() << std::endl;
    }
}

void pause() {
    std::cout << "\nНажмите Enter для продолжения...";
    std::cin.get();
    if (std::cin.get() != '\n') {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void clearDequeMemory(Deque<Vehicle*>& deque) {
    while (!deque.isEmpty()) {
        delete deque.takeFirst();
    }
}

void replaceLastVehicle(Deque<Vehicle*>& deque) {
    if (deque.isEmpty()) {
        std::cout << "Дек пуст!" << std::endl;
        return;
    }
    
    try {
        std::cout << "Замена последнего элемента:" << std::endl;
        Vehicle* newVehicle = createVehicleInteractively();
        deque.takeLast();
        deque.addLast(newVehicle);
        std::cout << "Последний элемент заменен!" << std::endl;
    } catch (const Exception& e) {
        std::cout << "Ошибка при замене последнего элемента: " << e.what() << std::endl;
    }
}

void replaceFirstVehicle(Deque<Vehicle*>& deque) {
    if (deque.isEmpty()) {
        std::cout << "Дек пуст!" << std::endl;
        return;
    }
    
    try {
        std::cout << "Замена первого элемента:" << std::endl;
        Vehicle* newVehicle = createVehicleInteractively();
        deque.takeFirst();
        deque.addFirst(newVehicle);
        std::cout << "Первый элемент заменен!" << std::endl;
    } catch (const Exception& e) {
        std::cout << "Ошибка при замене первого элемента: " << e.what() << std::endl;
    }
}

int main() {
    Deque<Vehicle*> transportDeque;
    int choice = 1;

    while (choice != 0) {
        showMainMenu();

        try {
            choice = (int)SafeInput::inputDigit(std::cin, "", 0, 12);
        }
        catch (...) {
            std::cout << "Ошибка ввода пункта меню!\n";
            pause();
            continue;
        }

        try {
            switch (choice) {
                case 0: break;
                case 1: addToFront(transportDeque); break;
                case 2: addToBack(transportDeque); break;
                case 3: removeFromFront(transportDeque); break;
                case 4: removeFromBack(transportDeque); break;
                case 5: showFirst(transportDeque); break;
                case 6: showLast(transportDeque); break;
                case 7: showAllAsTable(transportDeque); break;
                case 8: sortDeque(transportDeque); break;
                case 9: showSearch(transportDeque); break;
                case 10: clearDequeMemory(transportDeque); break;
                case 11: replaceFirstVehicle(transportDeque); break;
                case 12: replaceLastVehicle(transportDeque); break;
                default:
                    std::cout << "Неверный пункт меню!\n";
            }
        }
        catch (const ContainerException& e) {
            std::cout << "Ошибка контейнера: " << e.what() << std::endl;
        }
        catch (const InputException& e) {
            std::cout << "Ошибка ввода: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Неизвестная ошибка: " << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "Критическая ошибка!\n";
        }

        pause();
    }

    clearDequeMemory(transportDeque);
}