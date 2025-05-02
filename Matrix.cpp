//ronen.chereshn@msmail.ariel.ac.il

#include "Matrix.hpp"
#include <iostream>

namespace matrix{

Matrix::Matrix(int length) : length(length) {
    number = new double*[length];
    for (int i = 0; i < length; i++) {
        number[i] = new double[length];
        for (int j = 0; j < length; j++) {
            number[i][j] = 0;
        }
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < length; i++) {
        delete[] number[i];
    }
    delete[] number;
}

Matrix::Matrix(const Matrix& other) : length(other.length) {
    number = new double*[length];
    for (int i = 0; i < length; i++) {
        number[i] = new double[length];
        for (int j = 0; j < length; j++) {
            number[i][j] = other.number[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    for (int i = 0; i < length; i++) {
        delete[] number[i];
    }
    delete[] number;

    length = other.length;
    number = new double*[length];
    for (int i = 0; i < length; i++) {
        number[i] = new double[length];
        for (int j = 0; j < length; j++) {
            number[i][j] = other.number[i][j];
        }
    }
    return *this;
}

double** Matrix::getNumber() const {
    return number;
}

int Matrix::getLength() const {
    return length;
}

void Matrix::setNumber(double** newNumber) {
    number = newNumber;
}
}