#pragma once
#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix();
	void read();
	void print() const;
	int getValue(int, int) const;
	const int getSize() const;
	void setValue(int, int, int);
	const Matrix operator +(const Matrix&) const;
	const Matrix operator *(const Matrix&) const;
private:
	static const int MATSIZE = 3;
	int mat[MATSIZE][MATSIZE];
	void initialization();
	void getMaximumDigitCol(int[MATSIZE]) const;
};
istream& operator >>(istream&, Matrix&);
ostream& operator <<(ostream&, Matrix&);

