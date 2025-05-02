//ronen.chereshn@msmail.ariel.ac.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include "Matrix.hpp"
#include <iostream>

using namespace matrix;

TEST_CASE("operators +, -"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }
    SquareMat mat2(3);
    x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat2.setValue(i, j, x);
            x++;

        }
    }
    SquareMat mat3(2);
    x = 0.5;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat3.setValue(i, j, x);
            x++;
        }
    }

    SUBCASE("operator +"){
        SquareMat result = mat1 + mat2;

        CHECK(result.getValue(0,0) == 2);
        CHECK(result.getValue(1,1) == 10);
        CHECK(result.getValue(2,2) == 18);
        CHECK_THROWS_AS(mat1 + mat3, std::invalid_argument);
    }

    SUBCASE("operator -"){
        SquareMat result = mat1 - mat2;

        CHECK(result.getValue(0,0) == 1);
        CHECK(result.getValue(1,1) == 1);
        CHECK(result.getValue(2,2) == 1);
        CHECK_THROWS_AS(mat1 - mat3, std::invalid_argument);

    }
}

TEST_CASE("operator -mat"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }

    SquareMat result = -mat1;

    CHECK(result.getValue(0,0) == -1.5);
    CHECK(result.getValue(1,1) == -5.5);
    CHECK(result.getValue(2,2) == -9.5);
}

TEST_CASE("operator *"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }
    SquareMat mat2(3);
    x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat2.setValue(i, j, x);
            x++;

        }
    }
    SquareMat mat3(2);
    x = 0.5;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat3.setValue(i, j, x);
            x++;
        }
    }
    SUBCASE("mat * mat"){
        SquareMat result = mat1 * mat2;
        CHECK(result.getValue(0,0) == 32.25);
        CHECK(result.getValue(1,1) == 80.25);
        CHECK(result.getValue(2,2) == 146.25);

        CHECK_THROWS_AS(mat1 * mat3, std::invalid_argument);
    }

    SUBCASE("mat * scalar"){
        SquareMat result = mat1 * 2;
        CHECK(result.getValue(0,0) == 3);
        CHECK(result.getValue(1,1) == 11);
        CHECK(result.getValue(2,2) == 19);
    }

}

TEST_CASE("operator %"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }
    SquareMat mat2(3);
    x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat2.setValue(i, j, x);
            x++;

        }
    }
    SquareMat mat3(2);
    x = 0.5;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat3.setValue(i, j, x);
            x++;
        }
    }

    SUBCASE("mat % mat"){
        SquareMat result = mat1 % mat2;
        CHECK(result.getValue(0,0) == 0.75);
        CHECK(result.getValue(1,1) == 24.75);
        CHECK(result.getValue(2,2) == 80.75);

        CHECK_THROWS_AS(mat1 % mat3, std::invalid_argument);
    }

    SUBCASE("mat % scalar"){
        SquareMat result = mat1 % 2;
        CHECK(result.getValue(0,0) == 1.5);
        CHECK(result.getValue(1,1) == 1.5);
        CHECK(result.getValue(2,2) == 1.5);
    }
}

TEST_CASE("operator /"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }
    double scalar = 3;

    SquareMat result = mat1 / scalar;
    CHECK(result.getValue(0,0) == 0.5);

}


TEST_CASE("operator ^"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }

    SUBCASE("power == 0") {
        SquareMat result = mat1 ^ 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j){
                    CHECK(result.getValue(i,j) == 1);
                } else{
                    CHECK(result.getValue(i,j) == 0);
                }
            }

        }
    }

    SUBCASE("power == 1"){
        SquareMat result = mat1 ^ 1;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                CHECK(result.getValue(i,j) == mat1.getValue(i,j));
            }
        }
    }

    SUBCASE("power == 2"){
        SquareMat result = mat1 ^ 2;
        CHECK(result.getValue(0,0) == 39.75);
        CHECK(result.getValue(1,1) == 96.75);
        CHECK(result.getValue(1, 2) == 113.25);
    }

    SUBCASE("power == -1"){
        CHECK_THROWS_AS(mat1 ^ -1, std::invalid_argument);
    }
}


TEST_CASE("operator ++, --"){
    SquareMat mat1(3);
    double x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }

    SUBCASE("operator ++"){
        SquareMat result = ++mat1;
        CHECK(result.getValue(0,0) == 1.5);
        CHECK(result.getValue(1,1) == 5.5);
        CHECK(result.getValue(2,2) == 9.5);
    }

    SUBCASE("operator --"){
        SquareMat result = --mat1;
        CHECK(result.getValue(0,0) == -0.5);
        CHECK(result.getValue(1,1) == 3.5);
        CHECK(result.getValue(2,2) == 7.5);
    }
}

TEST_CASE("operator ~"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }

    SquareMat result = ~mat1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            CHECK(result.getValue(i,j) == mat1.getValue(j,i));
        }

    }
}

TEST_CASE("operators equals"){
    SquareMat mat1(3);
    double x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;

        }
    }
    SquareMat mat2(2);
    x = 0.5;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            mat2.setValue(i, j, x);
            x++;
        }
    }
    SUBCASE("operator =="){
        CHECK_FALSE(mat1 == mat2);
    }
    SUBCASE("operator !="){
        CHECK(mat1 != mat2);
    }
    SUBCASE("operator >"){
        CHECK(mat1 > mat2);
    }
    SUBCASE("operator <"){
        CHECK_FALSE(mat1 < mat2);
    }
    SUBCASE("operator >="){
        CHECK(mat1 >= mat2);
    }
    SUBCASE("operator <="){
        CHECK_FALSE(mat1 <= mat2);
    }
}

TEST_CASE("operator !"){
    SquareMat mat1(3);
    double sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum++;
            mat1.setValue(i, j, sum);
        }
    }
    mat1.setValue(0,2,6);
    double result = !mat1;
    CHECK(result == -9);

}

TEST_CASE("Integrated placement operators"){
    SquareMat mat1(3);
    double x = 1.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat1.setValue(i, j, x);
            x++;
        }
    }
    SquareMat mat2(3);
    x = 0.5;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mat2.setValue(i, j, x);
            x++;

        }
    }

    SUBCASE("operator +="){
        mat1 += mat2;
        CHECK(mat1.getValue(0,0) == 2);
        CHECK(mat1.getValue(1,1) == 10);
        CHECK(mat1.getValue(2,2) == 18);
    }

    SUBCASE("operator -="){
        mat1 -= mat2;
        CHECK(mat1.getValue(0,0) == 1.5);
        CHECK(mat1.getValue(1,1) == 5.5);
        CHECK(mat1.getValue(2,2) == 9.5);
    }

    SUBCASE("operator *="){
        mat1 *= mat2;
        CHECK(mat1.getValue(0,0) == 32.25);
        CHECK(mat1.getValue(1,1) == 80.25);
        CHECK(mat1.getValue(2,2) == 146.25);
    }

    SUBCASE("operator *="){
        mat1 *= 2;
        CHECK(mat1.getValue(0,0) == 3);
        CHECK(mat1.getValue(1,1) == 11);
        CHECK(mat1.getValue(2,2) == 19);
    }

    SUBCASE("operator /="){
        mat1 /= 2;
        CHECK(mat1.getValue(0,0) == 1.5);
        CHECK(mat1.getValue(1,1) == 5.5);
        CHECK(mat1.getValue(2,2) == 9.5);
    }


}
