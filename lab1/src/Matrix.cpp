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

        if (mtx.data != nullptr) {
            data = new double*[rows];
            for (size_t i = 0; i < rows; ++i) {
                data[i] = new double[columns];
                for (size_t j = 0; j < columns; ++j)
                    data[i][j] = mtx.data[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix& mtx) const {
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

Matrix Matrix::operator*=(const Matrix& mtx) {
    // Matrix a = *this * mtx;
    *this = *this * mtx;
    return *this;
}

bool Matrix::isEmpty() const {
    return data == nullptr;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mtx) {
    if (!mtx.isEmpty()) {
        for (size_t i = 0; i < mtx.rows; ++i) {
            for (size_t j = 0; j < mtx.columns; ++j) 
                os << mtx.data[i][j] << " ";
            os << std::endl;
        }
    } else 
        os << "Матрица пуста." << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& mtx) {
    if (mtx.isEmpty()) {
        is >> mtx.rows >> mtx.columns;
        mtx.data = new double*[mtx.rows];
        for (size_t i = 0; i < mtx.rows; ++i)
            mtx.data[i] = new double[mtx.columns]();
    }

    for (size_t i = 0; i < mtx.rows; ++i)
        for (size_t j = 0; j < mtx.columns; ++j) 
            is >> mtx.data[i][j];

    return is;
}

Matrix::~Matrix() {
    if (data != nullptr) {
        for (size_t i = 0; i < rows; ++i) 
            delete[] data[i];
        delete[] data;
    }
}