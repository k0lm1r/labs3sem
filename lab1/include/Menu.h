#pragma once
#include <iostream>
#include "Matrix.h"

class Menu {
private:
    Matrix* defaultMatrix;
    Matrix* paramMatrix;
    Matrix* copyMatrix;
    Matrix* currentMatrix;
    
    void printMainMenu();
    void printConstructorMenu();
    void printOperationsMenu();
    void printSelectMatrixMenu();
    void demonstrateDefaultConstructor();
    void demonstrateParameterConstructor();
    void demonstrateCopyConstructor();
    void fillCurrentMatrix();
    void printCurrentMatrix();
    void multiplyMatrices();
    void showAllMatrices();
    void selectCurrentMatrix();

public:
    Menu() : defaultMatrix(nullptr), paramMatrix(nullptr), copyMatrix(nullptr), currentMatrix(nullptr) {}

    ~Menu() {
        if (defaultMatrix != nullptr) delete defaultMatrix;
        if (paramMatrix != nullptr) delete paramMatrix;
        if (copyMatrix != nullptr) delete copyMatrix;
    }
};