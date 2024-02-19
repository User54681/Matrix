#pragma once
#ifndef source
#define source

class matrix {
private:
	int** data;
	unsigned int m, n;
public:
	matrix();
	matrix(unsigned int m, unsigned int n);
	~matrix();
	void random();
};

#endif // !source
