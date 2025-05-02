//ronen.chereshn@msmail.ariel.ac.il

#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace matrix;

int main() {
    SquareMat mat1(3);
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum++;
            mat1.setValue(i, j, sum);
        }
    }
    cout << "Matrix 1:" << endl;
    cout << mat1 << endl;

    SquareMat mat2(3);
    mat2.setValue(0, 0, 1);
    mat2.setValue(0, 1, 2);
    mat2.setValue(0, 2, 3);
    cout << "Matrix 2:" << endl;
    cout << mat2 << endl;

    cout << "Matrix 1 + Matrix 2:" << endl;
    SquareMat plus = mat1 + mat2;
    cout << plus << endl;

    cout << "Matrix 1 - Matrix 2:" << endl;
    SquareMat minus = mat1 - mat2;
    cout << minus << endl;

    cout << "-Matrix 1:" << endl;
    SquareMat minus1 = -mat1;
    cout << minus1 << endl;

    cout << "Matrix 1 * Matrix 2:" << endl;
    SquareMat mult = mat1 * mat2;
    cout << mult << endl;

    cout << "Matrix 1 % Matrix 2:" << endl;
    SquareMat mult1 = mat1 % mat2;
    cout << mult1 << endl;

    cout << "Matrix 1 % 4:" << endl;
    SquareMat mod = mat1 % 4;
    cout << mod << endl;

    cout << "Matrix 1 / 4:" << endl;
    SquareMat div = mat1 / 4;
    cout << div << endl;

    cout << "Matrix 1 ^ 3:" << endl;
    SquareMat pow = mat1 ^ 3;
    cout << pow << endl;

    cout << "Matrix 1++" << endl;
    SquareMat inc = ++mat1;
    cout << inc << endl;

    cout << "Matrix 1--" << endl;
    SquareMat dec = --mat1;
    cout << dec << endl;

    cout << "Matrix 1 transpose:" << endl;
    SquareMat trans = ~mat1;
    cout << trans << endl;

    cout << "Matrix 1 == Matrix 2:" << endl;
    cout << (mat1 == mat2) << endl;

    cout << "Matrix 1 != Matrix 2:" << endl;
    cout << (mat1 != mat2) << endl;

    cout << "Matrix 1 > Matrix 2:" << endl;
    cout << (mat1 > mat2) << endl;

    cout << "Matrix 1 < Matrix 2:" << endl;
    cout << (mat1 < mat2) << endl;

    cout << "Matrix 1 >= Matrix 2:" << endl;
    cout << (mat1 >= mat2) << endl;

    cout << "Matrix 1 <= Matrix 2:" << endl;
    cout << (mat1 <= mat2) << endl;

    mat1.setValue(0,2,6);
    cout << "Matrix 1 determinant:" << endl;
    cout << (!mat1) << endl;

    mat1.setValue(0,2,3);

    cout << "Matrix 1 += Matrix 2:" << endl;
    mat1 += mat2;
    cout << mat1 << endl;

    cout << "Matrix 1 -= Matrix 2:" << endl;
    mat1 -= mat2;
    cout << mat1 << endl;

    cout << "Matrix 1 *= Matrix 2:" << endl;
    mat1 *= mat2;
    cout << mat1 << endl;

    cout << "Matrix 1 *= 2:" << endl;
    mat1 *= 2;
    cout << mat1 << endl;

    cout << "Matrix 1 /= 2:" << endl;
    mat1 /= 2;
    cout << mat1 << endl;

    cout << "Matrix 1 %= Matrix 2:" << endl;
    mat1 %= mat2;
    cout << mat1 << endl;

    cout << "Matrix 1 %= 2:" << endl;
    mat1 %= 2;
    cout << mat1 << endl;

    cout << "New values of Matrix 1:" << endl;
    cout << mat1 << endl;

    return 0;
}
