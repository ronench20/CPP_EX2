//ronen.chereshn@msmail.ariel.ac.il

#include "SquareMat.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <cmath>

namespace matrix {

    SquareMat::SquareMat(int length) {
        mat = new Matrix(length);
    }

    SquareMat::~SquareMat() {
        delete mat;
    }

    void SquareMat::setValue(int row, int col, double value) {
        if (row < 0 || row >= mat->getLength() || col < 0 || col >= mat->getLength()) {
            throw std::out_of_range("Index out of range.");
        }
        mat->getNumber()[row][col] = value;
    }

    double SquareMat::getValue(int row, int col) const {
        if (row < 0 || row >= mat->getLength() || col < 0 || col >= mat->getLength()) {
            throw std::out_of_range("Index out of range.");
        }
        return mat->getNumber()[row][col];
    }

    SquareMat SquareMat::operator+(const SquareMat &other) const {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match");
        }

        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); ++i) {
            for (int j = 0; j < mat->getLength(); ++j) {
                double sum = mat->getNumber()[i][j] + other.mat->getNumber()[i][j];
                result.setValue(i, j, sum);
            }
        }
        return result;
    }


    SquareMat SquareMat::operator-(const SquareMat &other) const {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum = mat->getNumber()[i][j] - other.mat->getNumber()[i][j];
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum = -1 * mat->getNumber()[i][j];
                if (sum != 0) {
                    result.setValue(i, j, sum);
                }
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat &other) const {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum = 0;
                for (int k = 0; k < mat->getLength(); k++) {
                    sum += mat->getNumber()[i][k] * other.mat->getNumber()[k][j];
                }
                result.setValue(i, j, sum);
            }
        }
        return result;
    }


    SquareMat SquareMat::operator*(const double &scalar) {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum;
                sum = mat->getNumber()[i][j] * scalar;
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat operator*(const double &scalar, const SquareMat &other) {
        SquareMat result(other.mat->getLength());
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                double sum;
                sum = scalar * other.mat->getNumber()[i][j];
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum;
                sum = mat->getNumber()[i][j] * other.mat->getNumber()[i][j];
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(const double &scalar) {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum;
                sum = std::fmod(mat->getNumber()[i][j], scalar);
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator/(const double &scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                double sum;
                sum = mat->getNumber()[i][j] / scalar;
                result.setValue(i, j, sum);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator^(const int &power) {
        SquareMat result(mat->getLength());
        if (power < 0) {
            throw std::invalid_argument("Power must be non-negative.");
        }
        if (power == 0) {
            for (int i = 0; i < mat->getLength(); i++) {
                for (int j = 0; j < mat->getLength(); j++) {
                    if (i == j) {
                        result.setValue(i, j, 1);
                    } else {
                        result.setValue(i, j, 0);
                    }
                }
            }
            return result;
        }
        if (power == 1) {
            for (int i = 0; i < mat->getLength(); i++) {
                for (int j = 0; j < mat->getLength(); j++) {
                    result.setValue(i, j, mat->getNumber()[i][j]);
                }
            }
            return result;
        }

        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[i][j]);
            }
        }

        for (int i = 1; i < power; ++i) {
            SquareMat temp(mat->getLength());

            for (int j = 0; j < mat->getLength(); ++j) {
                for (int k = 0; k < mat->getLength(); ++k) {
                    double sum = 0;
                    for (int l = 0; l < mat->getLength(); ++l) {
                        sum += result.mat->getNumber()[j][l] * mat->getNumber()[l][k];
                    }
                    temp.setValue(j, k, sum);
                }
            }
            for (int j = 0; j < mat->getLength(); ++j) {
                for (int k = 0; k < mat->getLength(); ++k) {
                    result.setValue(j, k, temp.getValue(j, k));
                }
            }
        }
        return result;
    }

    SquareMat SquareMat::operator++() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[i][j] + 1);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator--() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[i][j] - 1);
            }
        }
        return result;
    }

    SquareMat SquareMat::operator~() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[j][i]);
            }
        }
        return result;
    }

    bool SquareMat::operator==(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 == sum2) {
            return true;
        } else {
            return false;
        }
    }

    bool SquareMat::operator!=(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 != sum2) {
            return true;
        } else {
            return false;
        }
    }

    bool SquareMat::operator>(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 > sum2) {
            return true;
        } else {
            return false;
        }
    }

    bool SquareMat::operator<(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 < sum2) {
            return true;
        } else {
            return false;
        }
    }

    bool SquareMat::operator>=(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 >= sum2) {
            return true;
        } else {
            return false;
        }
    }

    bool SquareMat::operator<=(const SquareMat &other) const {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                sum1 += mat->getNumber()[i][j];
            }
        }
        for (int i = 0; i < other.mat->getLength(); i++) {
            for (int j = 0; j < other.mat->getLength(); j++) {
                sum2 += other.mat->getNumber()[i][j];
            }
        }
        if (sum1 <= sum2) {
            return true;
        } else {
            return false;
        }
    }

    double SquareMat::operator!() {
        double det = 0;
        if (mat->getLength() == 1) {
            return mat->getNumber()[0][0];
        }
        if (mat->getLength() == 2) {
            return mat->getNumber()[0][0] * mat->getNumber()[1][1] - mat->getNumber()[0][1] * mat->getNumber()[1][0];
        }
        for (int i = 0; i < mat->getLength(); i++) {
            int size = mat->getLength() - 1;
            SquareMat subMat(size);
            for (int j = 0; j < size; j++) {
                int subCol = 0;
                for (int k = 0; k < mat->getLength(); k++) {
                    if (k != i) {
                        subMat.setValue(j, subCol, mat->getNumber()[j + 1][k]);
                        subCol++;
                    }
                }
            }
            double sign;
            if (i % 2 == 0) {
                sign = 1;
            } else {
                sign = -1;
            }
            det += sign * mat->getNumber()[0][i] * (!subMat);
        }
        return det;
    }

    SquareMat &SquareMat::operator+=(const SquareMat &other) {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] += other.mat->getNumber()[i][j];
            }
        }
        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &other) {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] -= other.mat->getNumber()[i][j];
            }
        }
        return *this;
    }

    SquareMat &SquareMat::operator*=(const SquareMat &other) {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        double **temp = new double *[mat->getLength()];
        for (int i = 0; i < mat->getLength(); i++) {
            temp[i] = new double[mat->getLength()];
            for (int j = 0; j < mat->getLength(); j++) {
                temp[i][j] = 0;
                for (int k = 0; k < mat->getLength(); k++) {
                    temp[i][j] += mat->getNumber()[i][k] * other.mat->getNumber()[k][j];
                }
            }
        }
        for (int i = 0; i < mat->getLength(); ++i) {
            delete[] mat->getNumber()[i];
        }
        delete[] mat->getNumber();
        mat->setNumber(temp);
        return *this;
    }

    SquareMat &SquareMat::operator*=(const double &scalar) {
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] *= scalar;
            }
        }
        return *this;
    }

    SquareMat &SquareMat::operator/=(const double &scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] /= scalar;
            }
        }
        return *this;
    }

    SquareMat &SquareMat::operator%=(const SquareMat &other) {
        if (mat->getLength() != other.mat->getLength()) {
            throw std::invalid_argument("Matrix sizes do not match.");
        }
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] *= other.mat->getNumber()[i][j];
            }
        }
        return *this;
    }

    SquareMat &SquareMat::operator%=(const double &scalar) {
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] = std::fmod(mat->getNumber()[i][j], scalar);
            }
        }
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const SquareMat &mat) {
        for (int i = 0; i < mat.mat->getLength(); i++) {
            os << "[ ";
            for (int j = 0; j < mat.mat->getLength(); j++) {
                os << mat.mat->getNumber()[i][j] << " ";
            }
            os << "]\n";
        }
        return os;
    }

    SquareMat SquareMat::operator[](int index) {
        if (index < 0 || index >= mat->getLength()) {
            throw std::out_of_range("Index out of range.");
        }
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            result.setValue(i, 0, mat->getNumber()[index][i]);
        }
        return result;
    }
}