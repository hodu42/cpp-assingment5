#pragma once

class Matrix {
public:
	Matrix();
	void read();
	void print() const;
	int getValue(int, int) const;
	void setValue(int, int, int);
	Matrix add(Matrix) const;
	Matrix multi(Matrix) const;
private:
	static const int MATSIZE = 3;
	int mat[MATSIZE][MATSIZE];
	void initialization();
	void getMaximumDigitCol(int[MATSIZE]) const;
};
