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
const int Matrix::getSize() const {
	return MATSIZE;
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
const Matrix operator +(const Matrix& mat1, const Matrix& mat2) {
	Matrix result;
	const int MATSIZE = mat1.getSize();
	for (int y = 0; y < MATSIZE; y++) {
		for (int x = 0; x < MATSIZE; x++) {
			result.setValue(y, x, mat1.getValue(y, x) + mat2.getValue(y, x));
		}
	}
	return result;
}
const Matrix operator *(const Matrix& mat1, const Matrix& mat2) {
	Matrix multiplyMat;
	int matSize = mat1.getSize();
	for (int i = 0; i < matSize; i++) {
		for (int j = 0; j < matSize; j++) {
			int sum = 0;
			for (int k = 0; k < matSize; k++) {
				sum += mat1.getValue(i, k) * mat2.getValue(k, j);
			}
			multiplyMat.setValue(i, j, sum);
		}
	}
	return multiplyMat;
}
istream& operator >>(istream& inputStream, Matrix& matrix) {
	int matSize = matrix.getSize();
	int temp = 0;
	for (int y = 0; y < matSize; y++) {
		for (int x = 0; x < matSize; x++) {
			cin >> temp;
			matrix.setValue(y, x, temp);
		}
	}
}
ostream& operator <<(ostream& outputStream, Matrix& matrix) {
	static const int matSize = matrix.getSize();
	int maxDigit[matSize] = {0};
	getMaximumDigitCol(maxDigit);
	for (int y = 0; y < matSize; y++) {
		cout << "| ";
		for (int x = 0; x < matSize; x++) {
			if (x < matSize - 1) {
				printf("%-*d", maxDigit[x] + 2, matrix.getValue(y, x));
			}
			else {
				printf("%-*d", maxDigit[x], matrix.getValue(y, x));
			}
		}
		cout << " |" << endl;
	}
	cout << endl;
}