#pragma once
#ifndef source
#define source

class matrix {
private:
	int** data;
	unsigned int m, n; //m - rows, n - columns
public:
	matrix();
	matrix(unsigned int m, unsigned int n);
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
