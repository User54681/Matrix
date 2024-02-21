#include "source.h"
#include <ctime>
#include <iostream>

matrix::matrix() {
	m = 3;
	n = 3;
}

matrix::matrix(unsigned int m, unsigned int n) {
	this->m = m;
	this->n = n;
}

matrix::~matrix() {
	delete data;
}

void matrix::random() {
	srand(time(0));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			data[i][j] = rand() % 10;
		}
	}
}

//matrix & matrix::operator = (const matrix& object) {
//	this->m = object.m;
//	this->n = object.n;
//	if (this->data != nullptr) delete[] this->data;
//
//}

std::ostream& operator <<(std::ostream& os, const matrix& mat) {
    for (unsigned int i = 0; i < mat.m; ++i) {
        for (unsigned int j = 0; j < mat.n; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

matrix matrix::operator +(const matrix& other) {
    matrix result(m, n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

matrix& matrix::operator +=(const matrix& other) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

matrix matrix::operator -(const matrix& other) {
    matrix result(m, n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

matrix& matrix::operator -=(const matrix& other) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

matrix matrix::operator *(const matrix& other) {
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