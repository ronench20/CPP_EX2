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
    SquareMat operator^(const int &power); // not implemented in the main
    SquareMat operator++();
    SquareMat operator--();
    SquareMat operator~();
    SquareMat operator[](int index); // not sure if works
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator<(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    double operator!();
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(const double &scalar);
    SquareMat& operator/=(const double &scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(const double &scalar);
    friend std::ostream& operator<<(std::ostream&, const SquareMat &mat);

};

#endif //CPP_EX2_SQUAREMAT_HPP
