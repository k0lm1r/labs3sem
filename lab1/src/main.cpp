#include "Matrix.h"

int main() {
    int choice = 1;

    do {
        std::cout << "Введите количество перемножаемых матриц:" << std::endl;
        int n;
        std::cin >> n;

        Matrix result;
        std::cout << "Матрица 1:" << std::endl;
        result.fill();
        for (int i = 1; i < n; ++i) {
            if (!result.isEmpty()) {
                std::cout << "Матрица " << i + 1 << ":" << std::endl;
                Matrix current;
                current.fill();
                result = result.multiply(current);
            } else 
                std::cout << "Умножение на данную матрицу невозможно!" << std::endl;
        }

        std::cout << "Вы хотите перезапустить?\n1 - Да.\n2 - Нет." << std::endl;
        std::cin >> choice;
    } while (choice != 2);
}