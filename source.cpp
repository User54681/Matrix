#include "source.h"
#include <ctime>

matrix::matrix() {
	m = 3;
	n = 3;
}

matrix::matrix(unsigned int m, unsigned int n) {
	this->m = m;
	this->n = n;
    data = new int* [m];
    for (int i = 0; i < m; ++i) data[i] = new int [n];
}

matrix::~matrix() {
    for (int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void matrix::random() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			data[i][j] = rand() % 10;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const matrix& mat) {
    for (unsigned int i = 0; i < mat.m; ++i) {
        for (unsigned int j = 0; j < mat.n; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

matrix matrix::operator +(const matrix& other) {
    if (m == other.m and n == other.n) {
        matrix result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    else std::cout << "Нельзя посчитать сумму матриц" << "\n";
}

matrix& matrix::operator +=(const matrix& other) {
    if (m == other.m and n == other.n){
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        std::cout << *this << "\n";
        return *this;
    }
    else std::cout << "Нельзя прибавить одну матрицу к другой" << "\n";
}

matrix matrix::operator -(const matrix& other) {
    if (m == other.m and n == other.n){
        matrix result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j]; 
            }
        }
        return result;
    }
    else std::cout << "Нельзя посчитать разность матриц" << "\n";
}

matrix& matrix::operator -=(const matrix& other) {
    if (m == other.m and n == other.n){
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        std::cout << *this << "\n";
        return *this;
    }
    else std::cout << "Нельзя вычесть из одной матрицы другую" << "\n";
}

matrix matrix::operator *(const matrix& other) {
    if (m == other.n) {
        matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    else std::cout << "Невозможно посчитать произведение матриц" << "\n";
}

bool matrix::operator ==(const matrix& other) const {
    if (m != other.m || n != other.n) return false;

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other.data[i][j]) return false;
        }
    }

    return true;
}

bool matrix::operator !=(const matrix& other) const {
    return !(*this == other);
}