#include "Menu.h"

void Menu::showMenu() {
    std::cout << "\n=== МЕНЮ РАБОТЫ С МАТРИЦАМИ ===" << std::endl;
    std::cout << "1. Создать и заполнить матрицу" << std::endl;
    std::cout << "2. Умножить две матрицы" << std::endl;
    std::cout << "3. Умножить цепочку матриц" << std::endl;
    std::cout << "4. Показать текущую матрицу" << std::endl;
    std::cout << "5. Выйти" << std::endl;
    std::cout << "Ваш выбор:" << std::endl;
}

void Menu::handleChoice(int choice) {
    switch(choice) {
        case 1: createAndFillMatrix(); break;
        case 2: multiplyTwoMatrices(); break;
        case 3: multiplyMatrixChain(); break;
        case 4: showCurrentMatrix(); break;
        case 5: break;
        default: std::cout << "Неверный выбор" << std::endl;
    }
}

void Menu::createAndFillMatrix() {
    Matrix m;
    m.fill();
    currentMatrix = m;
    matrixList.push_back(m);
}

void Menu::multiplyTwoMatrices() {
    if(matrixList.size() < 2) {
        std::cout << "Необходимо создать как минимум две матрицы!" << std::endl;
        return;
    }
    
    Matrix m1 = matrixList[matrixList.size() - 2];
    Matrix m2 = matrixList[matrixList.size() - 1];
    
    std::cout << "Умножаем матрицы:" << std::endl;
    std::cout << "Матрица 1:" << std::endl;
    m1.print();
    std::cout << "Матрица 2:" << std::endl;
    m2.print();
    
    Matrix result = m1.multiply(m2);
    
    if(result.isEmpty()) {
        std::cout << "Умножение невозможно: несовпадение размеров!" << std::endl;
    } else {
        std::cout << "Результат умножения:" << std::endl;
        result.print();
        currentMatrix = result;
    }
}

void Menu::multiplyMatrixChain() {
    if(matrixList.empty()) {
        std::cout << "Сначала создайте матрицы!" << std::endl;
        return;
    }
    
    std::cout << "Умножаем цепочку из " << matrixList.size() << " матриц:" << std::endl;
    for(size_t i = 0; i < matrixList.size(); ++i) {
        std::cout << "Матрица " << i + 1 << ":" << std::endl;
        matrixList[i].print();
    }
    
    Matrix result = currentMatrix.multiply(matrixList);
    
    if(!result.isEmpty()) {
        std::cout << "Результат умножения цепочки:" << std::endl;
        result.print();
        currentMatrix = result;
        
    }
}

void Menu::showCurrentMatrix() {
    std::cout << "Текущая матрица:" << std::endl;
    currentMatrix.print();
}

void Menu::run() {
    int choice;
    do {
        choice = 0;
        showMenu();
        std::cin >> choice;
        handleChoice(choice);
    } while(choice != 5);
}