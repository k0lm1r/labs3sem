#pragma once

class Matrix {
    int rows;
    int columns;
    double **data;

    public:
        Matrix();
        Matrix(const int rows, const int columns);
        Matrix(const Matrix& mtx);
        void print();
        void fill();
        double replace(double digit, int row, int column);
        Matrix multiply(Matrix& mtx);
        bool isEmpty();
        ~Matrix();
};