#pragma once
#include <iostream>
#include <vector>

class Matrix {
    size_t rows;
    size_t columns;
    double **data;

    void freeData();

    public:
        Matrix() : rows(0), columns(0), data(nullptr) {}

        Matrix(const size_t newRows, const size_t newColumns) : rows(newRows), columns(newColumns) {
            data = new double*[rows];
            for (size_t i = 0; i < rows; ++i)
                data[i] = new double[columns]();
        }

        Matrix(const Matrix& mtx) : data(nullptr) {
            *this = mtx;
        }
        
        void print() const;
        void fill();
        Matrix multiply(const Matrix& mtx) const;
        Matrix multiply(std::vector<Matrix> arr) const;
        Matrix& operator=(const Matrix& mtx);
        bool isEmpty() const;
        
        ~Matrix() {
            freeData();
        }
};