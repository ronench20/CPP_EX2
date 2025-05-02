//ronen.chereshn@msmail.ariel.ac.il
#ifndef CPP_EX2_MATRIX_HPP
#define CPP_EX2_MATRIX_HPP

namespace matrix {

    class Matrix {
    private:
        double **number;
        int length;

    public:
        Matrix(int length);

        ~Matrix();

        Matrix(const Matrix &other);

        Matrix &operator=(const Matrix &other);

        double **getNumber() const;

        int getLength() const;

        void setNumber(double **newNumber);
    };
}


#endif //CPP_EX2_MATRIX_HPP
