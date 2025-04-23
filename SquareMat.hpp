//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX2_SQUAREMAT_HPP
#define CPP_EX2_SQUAREMAT_HPP
#include "Matrix.hpp"
#include <iostream>

class SquareMat{
private:
    matrix *mat;

public:
    Matrix operator+(const matrix &mat1);
    Matrix operator-(const matrix &mat1);
    Matrix operator-();
    Matrix operator*(const matrix &mat1);
    Matrix operator*(const double &scalar);
    Matrix operator%(const matrix &mat1);
    Matrix operator%(const double &scalar);
    Matrix operator/(const double &scalar);
    Matrix operator^(const int &power); // not working yet
    Matrix operator++();
    Matrix operator--();
    Matrix operator~();
    Matrix operator[](); // not implemented yet
    bool operator==(const matrix &mat1);
    bool operator!=(const matrix &mat1);
    bool operator>(const matrix &mat1);
    bool operator<(const matrix &mat1);
    bool operator>=(const matrix &mat1);
    bool operator<=(const matrix &mat1);
    double operator!(); // determinant
    SquareMat& operator+=(const matrix &mat1);
    SquareMat& operator-=(const matrix &mat1);
    SquareMat& operator*=(const matrix &mat1);
    SquareMat& operator*=(const double &scalar);
    SquareMat& operator/=(const double &scalar);
    SquareMat& operator%=(const matrix &mat1);
    SquareMat& operator%=(const double &scalar);
    friend std::ostream& operator<<(std::ostream&, const SquareMat &mat);


};

#endif //CPP_EX2_SQUAREMAT_HPP
