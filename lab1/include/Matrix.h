#pragma once
#include <iostream>
#include <vector>

class Matrix {
    size_t rows;
    size_t columns;
    double **data;

    public:
        Matrix() : rows(0), columns(0), data(nullptr) {}
        Matrix(const size_t newRows, const size_t newColumns);
        Matrix(const Matrix &mtx);

        void print() const;
        void fill();
        Matrix multiply(const Matrix& mtx) const;
        Matrix& operator=(const Matrix& mtx);
        bool isEmpty() const;
        
        ~Matrix();
};