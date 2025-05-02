// ronen.chereshn@msmail.ariel.ac.il

#include "Matrix.hpp"
#include <iostream>

namespace matrix {


/**
 * Constructs a square matrix of the given length, initializing all elements to 0.
 * @param length The size of the matrix (number of rows and columns).
 */
    Matrix::Matrix(int length) : length(length) {
        number = new double*[length];
        for (int i = 0; i < length; i++) {
            number[i] = new double[length];
            for (int j = 0; j < length; j++) {
                number[i][j] = 0;
            }
        }
    }

/**
 * Destructor for the Matrix class. Frees all dynamically allocated memory.
 */
    Matrix::~Matrix() {
        for (int i = 0; i < length; i++) {
            delete[] number[i];
        }
        delete[] number;
    }

/**
 * Copy constructor. Creates a deep copy of another Matrix object.
 * @param other The Matrix object to copy from.
 */
    Matrix::Matrix(const Matrix& other) : length(other.length) {
        number = new double*[length];
        for (int i = 0; i < length; i++) {
            number[i] = new double[length];
            for (int j = 0; j < length; j++) {
                number[i][j] = other.number[i][j];
            }
        }
    }

/**
 * Copy assignment operator. Assigns the values of another Matrix object to this one.
 * @param other The Matrix object to assign from.
 * @return A reference to the current Matrix object.
 */
    Matrix& Matrix::operator=(const Matrix& other) {
        if (this == &other) return *this; // Self-assignment check

        // Free existing memory
        for (int i = 0; i < length; i++) {
            delete[] number[i];
        }
        delete[] number;

        // Allocate new memory and copy values
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

/**
 * Gets the 2D array representing the matrix.
 * @return A pointer to the 2D array of doubles.
 */
    double** Matrix::getNumber() const {
        return number;
    }

/**
 * Gets the size of the matrix (number of rows/columns).
 * @return The length of the matrix.
 */
    int Matrix::getLength() const {
        return length;
    }

/**
 * Sets the 2D array representing the matrix.
 * @param newNumber A pointer to the new 2D array of doubles.
 * @warning This method does not free the existing memory or validate the input.
 */
    void Matrix::setNumber(double** newNumber) {
        number = newNumber;
    }

}