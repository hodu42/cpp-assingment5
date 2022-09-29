#include "Fraction.h"
#include <iostream>
#include <math.h>

using namespace std;

Fraction::Fraction() {
	numer = 1;
	denom = 1;
}
Fraction::Fraction(int inputNumer, int inputDenom) {
	numer = inputNumer;
	denomCheck(inputDenom);
	gcd(numer, denom);
};
void Fraction::setDenom(int inputDenom) {
	denomCheck(inputDenom);
	gcd(numer, denom);
};
void Fraction::setNumer(int bunza) {
	gcd(bunza, denom);
};
Fraction Fraction::add(Fraction a) const {
	int inputNumer = (numer * a.denom) + (a.numer * denom);
	int inputDenom = denom * a.denom;
	return Fraction(inputNumer, inputDenom);
};
void Fraction::print() {
	if (numer * denom < 0) {
		cout << "- ";
	}
	else {
		cout << "+ ";
	}
	cout << abs(numer) << "/" << abs(denom) << endl;
};
void Fraction::gcd(int inputNumer, int inputDenom) {
	int small = 0, gcd = 1;
	if (abs(inputDenom) >= abs(inputNumer)) {
		small = abs(inputNumer);
	}
	else {
		small = abs(inputDenom);
	}
	for (int i = 2; i <= small; i++) {
		if (inputNumer % i == 0 && inputDenom % i == 0) {
			gcd = i;
		}
	}
	numer = inputNumer / gcd, denom = inputDenom / gcd;
}
void Fraction::denomCheck(int inputDenom) {
	if (inputDenom == 0) {
		cout << "error : input denom is 0, changed to 1";
		denom = 1;
	}
	else {
		denom = inputDenom;
	}
}