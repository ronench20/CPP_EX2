//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX2_SQUAREMAT_HPP
#define CPP_EX2_SQUAREMAT_HPP
#include "Matrix.hpp"
#include <iostream>

class SquareMat{
private:
    Matrix *mat;

public:
    SquareMat(int length);
    ~SquareMat();
    void setValue(int row, int col, double value);
    SquareMat operator+(const SquareMat& other) const;
    SquareMat operator-(const SquareMat& other) const;
    SquareMat operator-();
    SquareMat operator*(const SquareMat& other) const;
    SquareMat operator*(const double &scalar); // not implemented in the main
    SquareMat operator%(const SquareMat& other) const;
    SquareMat operator%(const double &scalar);
    SquareMat operator/(const double &scalar);
    SquareMat operator^(const int &power); // not working yet
    SquareMat operator++();
    SquareMat operator--();
    SquareMat operator~();
    Matrix operator[](int index); // not implemented yet
    bool operator==(const Matrix &mat1);
    bool operator!=(const Matrix &mat1);
    bool operator>(const Matrix &mat1);
    bool operator<(const Matrix &mat1);
    bool operator>=(const Matrix &mat1);
    bool operator<=(const Matrix &mat1);
    double operator!(); // determinant
    SquareMat& operator+=(const Matrix &mat1);
    SquareMat& operator-=(const Matrix &mat1);
    SquareMat& operator*=(const Matrix &mat1);
    SquareMat& operator*=(const double &scalar);
    SquareMat& operator/=(const double &scalar);
    SquareMat& operator%=(const Matrix &mat1);
    SquareMat& operator%=(const double &scalar);
    friend std::ostream& operator<<(std::ostream&, const SquareMat &mat);


};

#endif //CPP_EX2_SQUAREMAT_HPP
