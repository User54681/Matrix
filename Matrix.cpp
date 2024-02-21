#include <iostream>
#include "source.h"

int main()
{
    setlocale(LC_ALL, "rus");

    matrix mat1(2, 3);
    mat1.random();

    matrix mat2(2, 3);
    mat2.random();

    std::cout << "Матрица 1:" << "\n" << mat1;
    std::cout << "Матрица 2:" << "\n" << mat2;

    matrix sum = mat1 + mat2;
    std::cout << "Сумма матриц:" << "\n" << sum;

    mat1 += mat2;
    std::cout << "Матрица 1 после прибавления к ней матрицы 2:" << "\n" << mat1;

    matrix diff = mat1 - mat2;
    std::cout << "Разница матриц:" << "\n" << diff;

    mat1 -= mat2;
    std::cout << "Матрица 1 после вычитания из нее матрицы 2:" << "\n" << mat1;

    matrix prod = mat1 * mat2;
    std::cout << "Произведение матриц:" << "\n" << prod;

    if (mat1 == mat2) {
        std::cout << "Матрица 1 тождественна матрице 2." << "\n";
    }
    else {
        std::cout << "Матрица 1 не тождественна матрице 2." << "\n";
    }

    if (mat1 != mat2) {
        std::cout << "Матрица 1 не равняется матрице 2." << "\n";
    }
    else {
        std::cout << "Матрица 1 равняется матрице 2." << "\n";
    }
}