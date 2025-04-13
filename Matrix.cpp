//ronen.chereshn@msmail.ariel.ac.il

#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int length) {
    mat = new matrix;
    mat->length = length;
    mat->number = new double *[length];
    for (int i = 0; i < length; i++) {
        mat->number[i] = new double[length];
        for (int j = 0; j < length; j++) {
            std::cout << "Enter number for row " << i << "and column " << j << ": \n";
            double num;
            std::cin >> num;
            mat->number[i][j] = num;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mat->length; i++) {
        delete[] mat->number[i];
    }
    delete[] mat->number;
    delete mat;
}
