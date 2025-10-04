#include "Matrix.h"

int main() {
    int choice = 1;

    do {
        std::cout << "Введите количество перемножаемых матриц:" << std::endl;
        int n;
        std::cin >> n;

        Matrix result;
        std::cout << "Матрица 1(размер и элементы):" << std::endl;
       std::cin >> result;
        for (int i = 1; i < n; ++i) {
            if (!result.isEmpty()) {
                std::cout << "Матрица " << i + 1 << "(размер и элементы):" << std::endl;
                Matrix current;
                std::cin >> current;
                result *= current;
            } else 
                std::cout << "Умножение на данную матрицу невозможно!" << std::endl;
        }

        std::cout << result;

        std::cout << "Вы хотите перезапустить?\n1 - Да.\n2 - Нет." << std::endl;
        std::cin >> choice;
    } while (choice != 2);
}