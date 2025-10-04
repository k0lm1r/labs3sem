#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Matrix {
    size_t rows;
    size_t columns;
    double **data;

    public:
        Matrix() : rows(0), columns(0), data(nullptr) {}
        Matrix(const size_t newRows, const size_t newColumns);
        Matrix(const Matrix &mtx);

        Matrix& operator=(const Matrix& mtx);
        Matrix operator*(const Matrix& mtx) const;
        Matrix& operator*=(const Matrix& mtx);
        bool isEmpty() const;

        friend std::ostream& operator<<(std::ostream& os, const Matrix& mtx);
        friend std::istream& operator>>(std::istream& is, Matrix& mtx);

        ~Matrix();
};