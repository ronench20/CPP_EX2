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

//Matrix SquareMat::operator^(const int &power) {
//    Matrix result(mat->length);
//    if (power < 0) {
//        throw std::invalid_argument("Power must be non-negative.");
//    }
//    if (power == 0) {
//        for (int i = 0; i < mat->length; i++) {
//            for (int j = 0; j < mat->length; j++) {
//                if (i == j) {
//                    result.getMatRef().number[i][j] = 1;
//                } else {
//                    result.getMatRef().number[i][j] = 0;
//                }
//            }
//        }
//        return result;
//    }
//    if (power == 1) {
//        return *mat;
//    }
//    for (int i = 0; i < mat->length; i++) {
//        for (int j = 0; j < mat->length; j++) {
//            result.getMatRef().number[i][j] = mat->number[i][j];
//        }
//    }
//    for (int i = 0; i < power; i++) {
//        result = result * (*mat);
//    }
//    return result;
//}

Matrix SquareMat::operator++() {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] + 1;
        }
    }
    return result;
}

Matrix SquareMat::operator--() {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[i][j] = mat->number[i][j] - 1;
        }
    }
    return result;
}

Matrix SquareMat::operator~() {
    Matrix result(mat->length);
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            result.getMatRef().number[j][i] = mat->number[i][j];
        }
    }
    return result;
}

Matrix SquareMat::operator==(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];        }
    }
    if (sum1 == sum2){
        return true;
    }
    else{
        return false;
    }
}

Matrix SquareMat::operator!=(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];
        }
    }
    if (sum1 != sum2){
        return true;
    }
    else{
        return false;
    }
}
Matrix SquareMat::operator>(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];
        }
    }
    if (sum1 > sum2){
        return true;
    }
    else{
        return false;
    }
}

Matrix SquareMat::operator<(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];
        }
    }
    if (sum1 < sum2){
        return true;
    }
    else{
        return false;
    }
}

Matrix SquareMat::operator>=(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];
        }
    }
    if (sum1 >= sum2){
        return true;
    }
    else{
        return false;
    }
}

Matrix SquareMat::operator<=(const matrix &mat1) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            sum1 += mat->number[i][j];
        }
    }
    for (int i = 0; i < mat1.length; i++) {
        for (int j = 0; j < mat1.length; j++) {
            sum2 += mat1.number[i][j];
        }
    }
    if (sum1 <= sum2){
        return true;
    }
    else{
        return false;
    }
}

Matrix SquareMat::operator!() {
    double det = 0;
    if (mat->length == 1) {
        return mat->number[0][0];
    }
    if (mat->length == 2) {
        return mat->number[0][0] * mat->number[1][1] - mat->number[0][1] * mat->number[1][0];
    }
    for (int i = 0; i < mat->length; i++) {
        det +=((*this)* pow(-1, i)) * mat->number[0][i] ;//(mat->length - 1, mat->length - 1);
    }
    return det;
}
