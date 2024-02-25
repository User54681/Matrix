#pragma once
#ifndef source
#define source
#include <iostream>

class matrix {
private:
	int** data;
	 int m, n; //m - rows, n - columns
public:
	matrix();
	matrix( int m,  int n);
	~matrix();
	void random();
	friend std::ostream& operator <<(std::ostream& os, const matrix& mat);
	matrix operator+(const matrix& other);
	matrix& operator+=(const matrix& other);
	matrix operator-(const matrix& other);
	matrix& operator-=(const matrix& other);
	matrix operator*(const matrix& other);
	bool operator ==(const matrix& other) const;
	bool operator !=(const matrix& other) const;
};

#endif // !source
#pragma once