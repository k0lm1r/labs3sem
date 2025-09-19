#pragma once
#include "Matrix.h"
#include <vector>
#include <iostream>

class Menu {
private:
    static Matrix currentMatrix;
    static std::vector<Matrix> matrixList;
    
    static void showMenu();
    static void handleChoice(int choice);
    static void createAndFillMatrix();
    static void multiplyTwoMatrices();
    static void multiplyMatrixChain();
    static void showCurrentMatrix();
    
public:
    static void run();
};