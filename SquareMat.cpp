#include "SquareMat.hpp"
#include <iostream>
#include <cmath>

Matrix SquareMat::operator+(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] + mat1.number[i][j];
        }
    }
    return result;
}

Matrix SquareMat::operator-(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] - mat1.number[i][j];
        }
    }
    return result;
}

Matrix SquareMat::operator-() {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = -1 * mat->number[i][j];
        }
    }
    return result;
}

Matrix SquareMat::operator*(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = 0;
            for (int k = 0; k < mat->length; k++) {
                result.getMatRef().number[i][j] += mat->number[i][k] * mat1.number[k][j];
            }
        }
    }
    return result;
}

Matrix SquareMat::operator*(const double &scalar) {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = scalar * mat->number[i][j];
        }
    }
    return result;
}
Matrix SquareMat::operator%(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] * mat1.number[i][j];
        }
    }
    return result;
}
Matrix SquareMat::operator%(const double &scalar) {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = std::fmod(mat->number[i][j], scalar);
        }
    }
    return result;
}

Matrix SquareMat::operator/(const double &scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] / scalar;
        }
    }
    return result;
}

