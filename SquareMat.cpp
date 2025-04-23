//ronen.chereshn@msmail.ariel.ac.il

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

bool SquareMat::operator==(const matrix &mat1) {
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

bool SquareMat::operator!=(const matrix &mat1) {
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
bool SquareMat::operator>(const matrix &mat1) {
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

bool SquareMat::operator<(const matrix &mat1) {
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

bool SquareMat::operator>=(const matrix &mat1) {
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

bool SquareMat::operator<=(const matrix &mat1) {
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

double SquareMat::operator!() {
    double det = 0;
    if (mat->length == 1) {
        return mat->number[0][0];
    }
    if (mat->length == 2) {
        return mat->number[0][0] * mat->number[1][1] - mat->number[0][1] * mat->number[1][0];
    }
    for (int i = 0; i < mat->length; i++) {
        int size = mat->length - 1;
        matrix* subMat = new matrix;
        subMat->length = size;
        subMat->number = new double*[size];
        for (int j = 0; j < size; j++) {
            subMat->number[j] = new double[size];
            int subCol = 0;
            for (int k = 0; k < mat->length; k++) {
                if (k != i) {
                    subMat->number[j][subCol] = mat->number[j + 1][k];
                }
            }
        }
        SquareMat subSquareMat;
        subSquareMat.mat = subMat;

        double sign = 1 - 2 * (i % 2); // possible 1 - 2 * (col & 1)
        det += sign * mat->number[0][i] * subSquareMat.operator!();

        for (int j = 0; j < size; j++) {
            delete[] subMat->number;
            delete subMat;
        }
    }
    return det;
}

SquareMat& SquareMat::operator+=(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] += mat1.number[i][j];
        }
    }
    return *this;
}

SquareMat& SquareMat::operator-=(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] -= mat1.number[i][j];
        }
    }
    return *this;
}

SquareMat& SquareMat::operator*=(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    double **temp = new double*[mat->length];
    for (int i = 0; i < mat->length; i++) {
        temp[i] = new double[mat->length];
        for (int j = 0; j < mat->length; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < mat->length; k++) {
                temp[i][j] += mat->number[i][k] * mat1.number[k][j];
            }
        }
    }
    for (int i = 0; i < mat->length; ++i) {
        delete[] mat->number[i];
    }
    delete[] mat->number;
    mat->number = temp;
    return *this;
}

SquareMat& SquareMat::operator*=(const double &scalar) {
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] *= scalar;
        }
    }
    return *this;
}

SquareMat& SquareMat::operator/=(const double &scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] /= scalar;
        }
    }
    return *this;
}

SquareMat& SquareMat::operator%=(const matrix &mat1) {
    if (mat->length != mat1.length) {
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] *= mat1.number[i][j];
        }
    }
    return *this;
}

SquareMat& SquareMat::operator%=(const double &scalar) {
    for (int i = 0; i < mat->length; i++) {
        for (int j = 0; j < mat->length; j++) {
            mat->number[i][j] = std::fmod(mat->number[i][j], scalar);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream&, const SquareMat &mat) {
    for (int i = 0; i < mat.mat->length; i++) {
        std:: cout << "[ ";
        for (int j = 0; j < mat.mat->length; j++) {
            std::cout << mat.mat->number[i][j] << " ";
        }
        std::cout << " ]\n";
    }
    return std::cout;
}
