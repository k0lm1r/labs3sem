#include "Matrix.h"

Matrix::Matrix(const size_t newRows, const size_t newColumns) : rows(newRows), columns(newColumns) {
    data = new double *[rows];
    for (size_t i = 0; i < rows; ++i)
        data[i] = new double[columns]();
}

Matrix::Matrix(const Matrix &mtx) : rows(mtx.rows), columns(mtx.columns) {
    data = new double *[rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[columns];
        for (size_t j = 0; j < columns; ++j)
            data[i][j] = mtx.data[i][j];
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
        std::cin >> rows >> columns;
        data = new double*[rows]();
        for (size_t i = 0; i < rows; ++i)
            data[i] = new double[columns]();
    }

    for (size_t i = 0; i < rows; ++i)
        for (size_t j = 0; j < columns; ++j) 
            std::cin >> data[i][j];
}

Matrix Matrix::multiply(const Matrix& mtx) const {
    Matrix result;

    if (!mtx.isEmpty() && !isEmpty() && columns == mtx.rows) {
        result = Matrix(rows, mtx.columns);
        for (size_t row = 0; row < rows; ++row) {
            for (size_t mtxColumn = 0; mtxColumn < mtx.columns; ++mtxColumn)
                for (size_t current = 0; current < columns; ++current)
                    result.data[row][mtxColumn] += data[row][current] * mtx.data[current][mtxColumn];
        }
    }

    return result;
}

Matrix& Matrix::operator=(const Matrix& mtx) {
    if (&mtx != this) {
        if (data != nullptr) {
            for (size_t i = 0; i < rows; ++i) 
                delete[] data[i];
            delete[] data;
        }

        rows = mtx.rows;
        columns = mtx.columns;
        data = nullptr;

        data = new double*[rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new double[columns];
            for (size_t j = 0; j < columns; ++j)
                std::copy(mtx.data[i], mtx.data[i] + j, data[i]);
        }
    }
    return *this;
}

bool Matrix::isEmpty() const {
    return data == nullptr;
}

Matrix::~Matrix() {
    if (data != nullptr) {
        for (size_t i = 0; i < rows; ++i) 
            delete[] data[i];
        delete[] data;
    }
}