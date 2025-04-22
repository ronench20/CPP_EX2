//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX2_SQUAREMAT_HPP
#define CPP_EX2_SQUAREMAT_HPP
#include "Matrix.hpp"

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
    Matrix operator==(const matrix &mat1);
    Matrix operator!=(const matrix &mat1);
    Matrix operator>(const matrix &mat1);
    Matrix operator<(const matrix &mat1);
    Matrix operator>=(const matrix &mat1);
    Matrix operator<=(const matrix &mat1);
    Matrix operator!(); // determinant


};

#endif //CPP_EX2_SQUAREMAT_HPP
