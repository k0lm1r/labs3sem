#include "Matrix.h"
#include <iostream>

void Matrix::print() const {
    if (!isEmpty()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) 
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    } else 
        std::cout << "Матрица пуста." << std::endl;
}

void Matrix::fill() {
    if (isEmpty()) {
        std::cout << "Введите размеры мaтрицы:" << std::endl;
        std::cin >> rows >> columns;
        *this = Matrix(rows, columns);
    }

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j) 
            std::cin >> data[i][j];
    std::cout << "Матрица успешно заполнена" << std::endl;
}

Matrix Matrix::multiply(const Matrix& mtx) {
    if (!mtx.isEmpty() && !isEmpty()) {
        if (columns == mtx.rows) {
            Matrix result(rows, mtx.columns);

            for (int row = 0; row < rows; ++row) {
                for (int mtxColumn = 0; mtxColumn < mtx.columns; ++mtxColumn)
                    for (int current = 0; current < columns; ++current)
                        result.data[row][mtxColumn] += data[row][current] * mtx.data[current][mtxColumn];
            }

            return result;
        }
    }
    return Matrix();
}

bool Matrix::isEmpty() const {
    return data == nullptr;
}
