#pragma once
#include "Matrix.h"
#include <vector>
#include <iostream>
#include <conio.h>

class Menu {
private:
    Matrix currentMatrix;
    std::vector<Matrix> matrixList;
    
    void showMenu() const;
    void handleChoice(int choice);
    void createAndFillMatrix();
    void multiplyTwoMatrices();
    void multiplyMatrixChain();
    void showCurrentMatrix() const;
    
public:
    void run();
};