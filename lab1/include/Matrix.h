#pragma once

class Matrix {
    int rows;
    int columns;
    double **data;

    public:
        Matrix() : rows(0), columns(0), data(nullptr) {}

        Matrix(const int newRows, const int newColumns) : rows(newRows), columns(newColumns) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i)
                data[i] = new double[columns]();
        }

        Matrix(const Matrix& mtx) : rows(mtx.rows), columns(mtx.columns) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new double[columns];
                for (int j = 0; j < columns; ++j) 
                    data[i][j] = mtx.data[i][j];
            }
        }
        
        void print() const;
        void fill();
        Matrix multiply(const Matrix& mtx);
        bool isEmpty() const;
        
        ~Matrix() {
            for (int i = 0; i < rows; ++i) 
                delete[] data[i];
            delete[] data;
        }
};