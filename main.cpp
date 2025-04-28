//ronen.chereshn@msmail.ariel.ac.il

#include <iostream>
#include "SquareMat.hpp"

using namespace std;

int main() {
    //cout << "create first matrix" << endl;
    SquareMat mat1(3);
    double sum = 0;
//    mat1.setValue(0, 0, 33);
//    mat1.setValue(1, 1, 2);
//    mat1.setValue(2, 2, 3);
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

    cout << "Matrix 1++" << endl;
    SquareMat inc = ++mat1;
    cout << inc << endl;

    cout << "Matrix 1--" << endl;
    SquareMat dec = --mat1;
    cout << dec << endl;

    cout << "Matrix 1 transpose:" << endl;
    SquareMat trans = ~mat1;
    cout << trans << endl;

    return 0;
}
