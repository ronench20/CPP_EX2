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
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    const matrix getMat();
    matrix& getMatRef();
    friend Matrix operator+(matrix &mat1, matrix &mat2);
    friend Matrix operator-(matrix &mat1, matrix &mat2);
    friend Matrix operator*(const Matrix& a, const matrix& b);

};


#endif //CPP_EX2_MATRIX_HPP
