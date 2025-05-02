//ronen.chereshn@msmail.ariel.ac.il

#include "SquareMat.hpp"
#include "Matrix.hpp"
#include <iostream>
#include <cmath>

namespace matrix {

    /**
    * Constructs a SquareMat object with the given size.
    * @param length The size of the square matrix (number of rows and columns).
    */
    SquareMat::SquareMat(int length) {
        mat = new Matrix(length);
    }


    /**
     * Destructor for the SquareMat class. Frees the dynamically allocated memory.
     */
    SquareMat::~SquareMat() {
        delete mat;
    }

    /**
    * Sets the value at the specified row and column in the matrix.
    * @param row The row index.
    * @param col The column index.
    * @param value The value to set.
    * @throws std::out_of_range If the row or column index is out of bounds.
    */
    void SquareMat::setValue(int row, int col, double value) {
        if (row < 0 || row >= mat->getLength() || col < 0 || col >= mat->getLength()) {
            throw std::out_of_range("Index out of range.");
        }
        mat->getNumber()[row][col] = value;
    }

    /**
    * Sets the value at the specified row and column in the matrix.
    * @param row The row index.
    * @param col The column index.
    * @param value The value to set.
    * @throws std::out_of_range If the row or column index is out of bounds.
    */
    double SquareMat::getValue(int row, int col) const {
        if (row < 0 || row >= mat->getLength() || col < 0 || col >= mat->getLength()) {
            throw std::out_of_range("Index out of range.");
        }
        return mat->getNumber()[row][col];
    }

    /**
     * Performs matrix addition operation.
     * @param other The other SquareMat to add.
     * @return A new SquareMat representing the sum.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
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

    /**
    * Performs matrix subtraction operation.
    * @param other The other SquareMat to subtract.
    * @return A new SquareMat representing the difference.
    * @throws std::invalid_argument If the matrices have different sizes.
    */
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

    /**
     * Negates all elements of the matrix.
     * @return A new SquareMat with all elements negated.
     */
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

    /**
     * Multiplies two SquareMat objects using matrix multiplication.
     * @param other The other SquareMat to multiply with.
     * @return A new SquareMat representing the product.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
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

    /**
     * Multiplies all elements of the matrix by a scalar.
     * @param scalar The scalar value to multiply with.
     * @return A new SquareMat with all elements scaled.
     */
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

    /**
    * Multiplies a scalar with a SquareMat object.
    * @param scalar The scalar value to multiply with.
    * @param other The SquareMat to scale.
    * @return A new SquareMat with all elements scaled.
    */
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

    /**
     * Computes the element-wise product of two SquareMat objects.
     * @param other The other SquareMat to multiply element-wise.
     * @return A new SquareMat representing the element-wise product.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
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

    /**
     * Computes the element-wise modulo of the matrix with a scalar.
     * @param scalar The scalar value for the modulo operation.
     * @return A new SquareMat with the modulo applied to each element.
     */
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

    /**
     * Divides the matrix by a scalar.
     * @param scalar The scalar value to divide by.
     * @return A new SquareMat with all elements divided by the scalar.
     * @throws std::invalid_argument If the scalar is zero.
     */
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

    /**
     * Raises the matrix to a given power using matrix multiplication.
     * @param power The exponent to raise the matrix to.
     * @return A new SquareMat representing the result of raising the matrix to the power.
     * @throws std::invalid_argument If the power is negative.
     */

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

    /**
     * Increments all elements of the matrix by 1.
     * @return A new SquareMat with all elements incremented.
     */
    SquareMat SquareMat::operator++() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[i][j] + 1);
            }
        }
        return result;
    }

    /**
     * Decrements all elements of the matrix by 1.
     * @return A new SquareMat with all elements decremented.
     */
    SquareMat SquareMat::operator--() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[i][j] - 1);
            }
        }
        return result;
    }

    /**
     * Transposes the matrix.
     * @return A new SquareMat representing the transposed matrix.
     */
    SquareMat SquareMat::operator~() {
        SquareMat result(mat->getLength());
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                result.setValue(i, j, mat->getNumber()[j][i]);
            }
        }
        return result;
    }

    /**
     * Compares two SquareMat objects for equality.
     * @param other The other SquareMat to compare with.
     * @return True if the matrices are equal, false otherwise.
     */
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

    /**
     * Compares two SquareMat objects for inequality.
     * @param other The other SquareMat to compare with.
     * @return True if the matrices are not equal, false otherwise.
     */
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

    /**
     * Compares two SquareMat objects for greater than.
     * @param other The other SquareMat to compare with.
     * @return True if this matrix is greater than the other, false otherwise.
     */
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

    /**
     * Compares two SquareMat objects for less than.
     * @param other The other SquareMat to compare with.
     * @return True if this matrix is less than the other, false otherwise.
     */
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

    /**
     * Compares two SquareMat objects for greater than or equal to.
     * @param other The other SquareMat to compare with.
     * @return True if this matrix is greater than or equal to the other, false otherwise.
     */
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

    /**
     * Compares two SquareMat objects for less than or equal to.
     * @param other The other SquareMat to compare with.
     * @return True if this matrix is less than or equal to the other, false otherwise.
     */
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

    /**
     * Computes the determinant of the matrix.
     * @return The determinant of the matrix.
     */
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

    /**
     * Performs matrix addition operation.
     * @return The original matrix.
     */
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

    /**
     * Performs matrix subtraction operation
     * @param other The other SquareMat to subtract.
     * @return The original matrix.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
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
    /**
     * Multiplies the matrix by another matrix.
     * @param other The other SquareMat to multiply with.
     * @return The original matrix.
     * @throws std::invalid_argument If the matrices have different sizes.
     */

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

    /**
     * Multiplies the matrix by a scalar.
     * @param scalar The scalar value to multiply with.
     * @return The original matrix.
     */
    SquareMat &SquareMat::operator*=(const double &scalar) {
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] *= scalar;
            }
        }
        return *this;
    }

    /**
     * Divides the matrix by a scalar.
     * @param scalar The scalar value to divide by.
     * @return The original matrix.
     * @throws std::invalid_argument If the scalar is zero.
     */
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

    /**
     * Computes the element-wise product of the matrix with another matrix.
     * @param other The other SquareMat to multiply element-wise.
     * @return The original matrix.
     * @throws std::invalid_argument If the matrices have different sizes.
     */
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

    /**
     * Computes the element-wise modulo of the matrix with a scalar.
     * @param scalar The scalar value for the modulo operation.
     * @return The original matrix.
     */
    SquareMat &SquareMat::operator%=(const double &scalar) {
        for (int i = 0; i < mat->getLength(); i++) {
            for (int j = 0; j < mat->getLength(); j++) {
                mat->getNumber()[i][j] = std::fmod(mat->getNumber()[i][j], scalar);
            }
        }
        return *this;
    }

    /**
     * Outputs the matrix to an output stream.
     * @param os The output stream.
     * @param mat The SquareMat object to output.
     * @return The output stream.
     */
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

    /**
     * Accesses a row of the matrix.
     * @param index The index of the row to access.
     * @return A new SquareMat representing the row.
     * @throws std::out_of_range If the index is out of bounds.
     */
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