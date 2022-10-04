#include <iostream>
#include "Matrix.h"
#include <string>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
	initialization();
};
const int Matrix::getElement(int y, int x) const {
	return mat[y][x];
}
const int Matrix::getSize() const {
	return MATSIZE;
}
const int Matrix::getMaxWidth() const {
	return maxWidth;
}
void Matrix::setElement(int y, int x, int value) {
	mat[y][x] = value;
	string temp = to_string(value);
	int crtLength = temp.length();
	if (maxWidth < crtLength) {
		maxWidth = crtLength;
	}
}
void Matrix::setMaxWidth() {
	for (int x = 0; x < MATSIZE; x++) {
		for (int y = 0; y < MATSIZE; y++) {
			string temp = to_string(getElement(y, x));
			int tempLength = temp.length();
			if (maxWidth < tempLength) {
				maxWidth = tempLength;
			}
		}
	}
}
void Matrix::initialization() {
	for (int y = 0; y < MATSIZE; y++) {
		maxWidth = 0;
		for (int x = 0; x < MATSIZE; x++) {
			setElement(y, x, 0);
		}
	}
}
const Matrix Matrix::operator +(const Matrix& mat2) const {
	Matrix result;
	for (int y = 0; y < MATSIZE; y++) {
		for (int x = 0; x < MATSIZE; x++) {
			result.setElement(y, x, mat[y][x] + mat2.getElement(y, x));
		}
	}
	return result;
}
const Matrix Matrix::operator *(const Matrix& mat2) const {
	Matrix multiplyMat;
	for (int i = 0; i < MATSIZE; i++) {
		for (int j = 0; j < MATSIZE; j++) {
			int sum = 0;
			for (int k = 0; k < MATSIZE; k++) {
				sum += mat[i][k] * mat2.getElement(k, j);
			}
			multiplyMat.setElement(i, j, sum);
		}
	}
	return multiplyMat;
}
istream& operator >>(istream& inputStream, Matrix& matrix) {
	int temp = 0;
	for (int y = 0; y < matrix.MATSIZE; y++) {
		for (int x = 0; x < matrix.MATSIZE; x++) {
			inputStream >> temp;
			matrix.setElement(y, x, temp);
		}
	}
	return inputStream;
}
ostream& operator <<(ostream& outputStream, const Matrix& matrix) {
	for (int y = 0; y < matrix.MATSIZE; y++) {
		outputStream << "|";
		for (int x = 0; x < matrix.MATSIZE; x++) {
			outputStream << setw(matrix.getMaxWidth() + 1) << matrix.getElement(y, x);
		}
		outputStream << " |" << endl;
	}
	outputStream << endl;
	return outputStream;
}