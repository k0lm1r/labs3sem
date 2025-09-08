#include <iostream>
#include "Matrix/Matrix.hpp"

int main() {
    int n1, m1, n2, m2;

    std::cout << "Введите размеры 1 матрицы:" << std::endl;
    std::cin >> n1 >> m1;
    Matrix mtx1(n1, m1);
    mtx1.fill();
    mtx1.print();

    std::cout << "Введите размеры 2 матрицы:" << std::endl;
    std::cin >> n2 >> m2;
    Matrix mtx2(n2, m2);
    mtx2.fill();
    mtx2.print();

    Matrix result(mtx1.multiply(mtx2));

    if (!result.isEmpty()) result.print();
    else std::cout << "Матрицы невозможно перемножить.";
}