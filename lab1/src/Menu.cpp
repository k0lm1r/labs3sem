#include "Menu.h"

Menu::Menu() : defaultMatrix(nullptr), paramMatrix(nullptr), 
                          copyMatrix(nullptr), currentMatrix(nullptr) {}

Menu::~Menu() {
    if (defaultMatrix != nullptr) delete defaultMatrix;
    if (paramMatrix != nullptr) delete paramMatrix;
    if (copyMatrix != nullptr) delete copyMatrix;
}

void Menu::printMainMenu() {
    std::cout << "=== Демонстрация класса Matrix ===" << std::endl;;
    std::cout << "1. Демонстрация конструкторов" << std::endl;;
    std::cout << "2. Операции с текущей матрицей" << std::endl;;
    std::cout << "3. Умножение матриц" << std::endl;;
    std::cout << "4. Показать все созданные матрицы" << std::endl;;
    std::cout << "5. Выбрать текущую матрицу" << std::endl;;
    std::cout << "6. Выход" << std::endl;;
    std::cout << "Выберите опцию: ";
}

void Menu::printConstructorMenu() {
    std::cout << "\n=== Демонстрация конструкторов ===" << std::endl;;
    std::cout << "1. Конструктор по умолчанию" << std::endl;;
    std::cout << "2. Конструктор с параметрами" << std::endl;;
    std::cout << "3. Конструктор копирования" << std::endl;;
    std::cout << "4. Назад" << std::endl;;
    std::cout << "Выберите опцию: ";
}

void Menu::printOperationsMenu() {
    std::cout << "\n=== Операции с матрицей ===" << std::endl;;
    std::cout << "1. Заполнить матрицу" << std::endl;;
    std::cout << "2. Вывести матрицу" << std::endl;;
    std::cout << "3. Назад" << std::endl;;
    std::cout << "Выберите опцию: ";
}

void Menu::printSelectMatrixMenu() {
    std::cout << "\n=== Выбор текущей матрицы ===" << std::endl;;
    std::cout << "1. Матрица по умолчанию" << std::endl;;
    std::cout << "2. Матрица с параметрами" << std::endl;;
    std::cout << "3. Скопированная матрица" << std::endl;;
    std::cout << "4. Назад" << std::endl;;
    std::cout << "Выберите опцию: ";
}

void Menu::demonstrateDefaultConstructor() {
    if (defaultMatrix != nullptr) {
        delete defaultMatrix;
    }
    defaultMatrix = new Matrix();
    currentMatrix = defaultMatrix;
    std::cout << "Матрица создана с помощью конструктора по умолчанию." << std::endl;;
}

void Menu::demonstrateParameterConstructor() {
    int rows, cols;
    std::cout << "Введите количество строк и столбцов: ";
    std::cin >> rows >> cols;
    
    if (paramMatrix != nullptr) {
        delete paramMatrix;
    }
    paramMatrix = new Matrix(rows, cols);
    currentMatrix = paramMatrix;
    std::cout << "Матрица создана с помощью конструктора с параметрами." << std::endl;;
}

void Menu::demonstrateCopyConstructor() {
    if (currentMatrix == nullptr) {
        std::cout << "Сначала создайте матрицу для копирования!" << std::endl;;
        return;
    }
    
    if (copyMatrix != nullptr) {
        delete copyMatrix;
    }
    copyMatrix = new Matrix(*currentMatrix);
    std::cout << "Матрица скопирована с помощью конструктора копирования." << std::endl;;
    std::cout << "Оригинал:" << std::endl;;
    currentMatrix->print();
    std::cout << "Копия:" << std::endl;;
    copyMatrix->print();
    currentMatrix = copyMatrix;
}

void Menu::fillCurrentMatrix() {
    if (currentMatrix == nullptr) {
        std::cout << "Сначала создайте матрицу!" << std::endl;;
        return;
    }
    currentMatrix->fill();
    std::cout << "Матрица заполнена." << std::endl;;
}

void Menu::printCurrentMatrix() {
    if (currentMatrix == nullptr) {
        std::cout << "Матрица не создана!" << std::endl;;
        return;
    }
    currentMatrix->print();
}

void Menu::multiplyMatrices() {
    Matrix m1, m2;
    std::cout << "Заполните первую матрицу:";
    m1.fill();
    std::cout << "Заполните вторую матрицy:" << std::endl;
    m2.fill();
    
    Matrix result = m1.multiply(m2);
    std::cout << "Результат:" << std::endl;
    result.print();
}

void Menu::showAllMatrices() {
    std::cout << "\n--- Все созданные матрицы ---" << std::endl;;
    
    if (defaultMatrix != nullptr) {
        std::cout << "Матрица по умолчанию:" << std::endl;;
        defaultMatrix->print();
    } else
        std::cout << "Матрица по умолчанию: не создана" << std::endl;;
    
    if (paramMatrix != nullptr) {
        std::cout << "Матрица с параметрами:" << std::endl;;
        paramMatrix->print();
    } else
        std::cout << "Матрица с параметрами: не создана" << std::endl;;
    
    if (copyMatrix != nullptr) {
        std::cout << "Скопированная матрица:" << std::endl;;
        copyMatrix->print();
    } else
        std::cout << "Скопированная матрица: не создана" << std::endl;;
}

void Menu::selectCurrentMatrix() {
    int choice;
    printSelectMatrixMenu();
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            if (defaultMatrix != nullptr) {
                currentMatrix = defaultMatrix;
                std::cout << "Текущая матрица: матрица по умолчанию" << std::endl;;
            } else
                std::cout << "Матрица по умолчанию не создана!" << std::endl;;
            break;
        case 2:
            if (paramMatrix != nullptr) {
                currentMatrix = paramMatrix;
                std::cout << "Текущая матрица: матрица с параметрами" << std::endl;;
            } else
                std::cout << "Матрица с параметрами не создана!" << std::endl;;
            break;
        case 3:
            if (copyMatrix != nullptr) {
                currentMatrix = copyMatrix;
                std::cout << "Текущая матрица: скопированная матрица" << std::endl;
            } else
                std::cout << "Скопированная матрица не создана!" << std::endl;
            break;
        case 4: break;
        default: std::cout << "Неверный выбор!" << std::endl;
    }
}