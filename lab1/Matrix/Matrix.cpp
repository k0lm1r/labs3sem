#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix() : rows(0), columns(0), data(nullptr) {}

Matrix::Matrix(const int newRows, const int newColumns) : rows(newRows), columns(newColumns) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new double[columns]();
}

Matrix::Matrix(const Matrix& mtx) : rows(mtx.rows), columns(mtx.columns) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[columns];
        for (int j = 0; j < columns; ++j) 
            data[i][j] = mtx.data[i][j];    
    }
}

void Matrix::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) 
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}

void Matrix::fill() {
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j) 
            std::cin >> data[i][j];
    std::cout << "Массив успешно заполнен" << std::endl;
}

double Matrix::replace(double digit, int row, int column) {
    double oldValue = data[row][column];
    data[row][column] = digit;
    return oldValue;
}

Matrix Matrix::multiply(Matrix& mtx) {
    if (columns == mtx.rows) {
        Matrix result(rows, mtx.columns);

        for (int row = 0; row < rows; ++row) {
            for (int mtxColumn = 0; mtxColumn < mtx.columns; ++mtxColumn)
                for (int current = 0; current < columns; ++current)
                    result.data[row][mtxColumn] += data[row][current] * mtx.data[current][mtxColumn];
        }

        return result;
    } else 
        return Matrix();
}

bool Matrix::isEmpty() {
    return data == nullptr;
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) 
        delete[] data[i];
    delete[] data;
}