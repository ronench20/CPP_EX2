//ronen.chereshn@msmail.ariel.ac.il
#ifndef CPP_EX2_MATRIX_HPP
#define CPP_EX2_MATRIX_HPP

struct matrix {
    int length;
    double **number;
};
class Matrix {
private:
    matrix *mat;

public:
    Matrix(int length);
    ~Matrix();
};


#endif //CPP_EX2_MATRIX_HPP
