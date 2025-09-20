#include "Matrix.h"

int main() {
    Matrix m1;
    m1.fill();

    std::cout << "Введите размеры второй матрицы:" << std::endl;
    int r2, c2;
    std::cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.fill();
    
    Matrix m3(m2);

    Matrix res = m1.multiply(m3);
    if (res.isEmpty())
        std::cout << "Матрицы невозможно перемножить." << std::endl;
    else 
        res.print();
}