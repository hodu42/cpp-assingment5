#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;

Matrix::Matrix() {
	initialization();
};
int Matrix::getValue(int y, int x) const {
	return mat[y][x];
}
void Matrix::setValue(int y, int x, int value) {
	mat[y][x] = value;
}
void Matrix::initialization() {
	for (int y = 0; y < MATSIZE; y++) {
		for (int x = 0; x < MATSIZE; x++) {
			setValue(y, x, 0);
		}
	}
}
void Matrix::read() {
	cout << "Input: ";
	for (int y = 0; y < MATSIZE; y++) {
		for (int x = 0; x < MATSIZE; x++) {
			cin >> mat[y][x];
		}
	}
};
void Matrix::print() const {
	int maxDigit[MATSIZE] = { 0 };
	getMaximumDigitCol(maxDigit);
	for (int y = 0; y < MATSIZE; y++) {
		cout << "| ";
		for (int x = 0; x < MATSIZE; x++) {
			if (x < MATSIZE - 1) {
				printf("%-*d", maxDigit[x] + 2, getValue(y, x));
			}
			else {
				printf("%-*d", maxDigit[x], getValue(y, x));
			}
		}
		cout << " |" << endl;
	}
	cout << endl;
};
Matrix Matrix::add(Matrix mat2) const {
	Matrix addMat;
	for (int y = 0; y < MATSIZE; y++) {
		for (int x = 0; x < MATSIZE; x++) {
			addMat.setValue(y, x, getValue(y, x) + mat2.getValue(y, x));
		}
	}
	return addMat;
};
Matrix Matrix::multi(Matrix mat2) const {
	Matrix multiplyMat;
	for (int i = 0; i < MATSIZE; i++) {
		for (int j = 0; j < MATSIZE; j++) {
			int sum = 0;
			for (int k = 0; k < MATSIZE; k++) {
				sum += getValue(i, k) * mat2.getValue(k, j);
			}
			multiplyMat.setValue(i, j, sum);
		}
	}
	return multiplyMat;
};
void Matrix::getMaximumDigitCol(int max[MATSIZE]) const {
	for (int x = 0; x < MATSIZE; x++) {
		for (int y = 0; y < MATSIZE; y++) {
			string temp = to_string(getValue(y, x));
			int tempLength = temp.length();
			if (max[x] < tempLength) {
				max[x] = tempLength;
			}
		}
	}
}