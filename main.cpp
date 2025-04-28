//ronen.chereshn@msmail.ariel.ac.il

#include <iostream>
#include "SquareMat.hpp"

using namespace std;

int main() {
    //cout << "create first matrix" << endl;
    SquareMat mat1(3);
    mat1.setValue(0, 0, 33);
    mat1.setValue(1, 1, 2);
    mat1.setValue(2, 2, 3);
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


    return 0;
}
