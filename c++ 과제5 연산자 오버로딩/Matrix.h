#pragma once
#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix();
	static const int MATSIZE = 3;
	const int getElement(int, int) const;
	const int getSize() const;
	const int getMaxWidth() const;
	void setElement(int, int, int);
	void setMaxWidth();
	const Matrix operator +(const Matrix&) const;
	const Matrix operator *(const Matrix&) const;
private:
	int mat[MATSIZE][MATSIZE];
	void initialization();
	int maxWidth;
};
istream& operator >>(istream&, Matrix&);
ostream& operator <<(ostream&, const Matrix&);