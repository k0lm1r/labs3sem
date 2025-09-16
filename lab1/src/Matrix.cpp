#include "Matrix.h"

void Matrix::freeData() {
    if (data != nullptr) {
        for (size_t i = 0; i < rows; ++i) 
            delete[] data[i];
        delete[] data;
    }
}

void Matrix::print() const {
    if (!isEmpty()) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) 
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
    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j) 
            std::cin >> data[i][j];
    std::cout << "Матрица успешно заполнена" << std::endl;
}

Matrix Matrix::multiply(const Matrix& mtx) {
    Matrix result;

    if (!mtx.isEmpty() && !isEmpty()) {
        if (columns == mtx.rows) {
            result = Matrix(rows, mtx.columns);
            for (size_t row = 0; row < rows; ++row) {
                for (size_t mtxColumn = 0; mtxColumn < mtx.columns; ++mtxColumn)
                    for (size_t current = 0; current < columns; ++current)
                        result.data[row][mtxColumn] += data[row][current] * mtx.data[current][mtxColumn];
            }
        }
    }

    return result;
}

Matrix Matrix::multiply(std::vector<Matrix> allMatrixes) {
    Matrix result;

    size_t columnsInResult = allMatrixes[0].columns;
    for (size_t i = 1; i < allMatrixes.size(); ++i) {
        if (allMatrixes[i].rows != columnsInResult) {
            std::cout << "Начиная с индекса " << i << " умножение невозможно." << std::endl;
            return result;
        }
        columnsInResult = allMatrixes[i].rows;
    }

    result = Matrix(multiply(allMatrixes[0]));
    for (size_t i = 1; i < allMatrixes.size(); ++i)
        result = result.multiply(allMatrixes[i]);

    return result;
}

Matrix& Matrix::operator=(const Matrix& mtx) {
    if (&mtx != this) {
        freeData();
        
        this->rows = mtx.rows;
        this->columns = mtx.columns;

        data = new double*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new double[columns];
            for (size_t j = 0; j < columns; ++j)
                data[i][j] = mtx.data[i][j];
        }
    }
    return *this;
}

bool Matrix::isEmpty() const {
    return data == nullptr;
}