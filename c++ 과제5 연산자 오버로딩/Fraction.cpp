#include "Fraction.h"
#include "Util.h"

Util util;

Fraction::Fraction() {
	numer = 1;
	denom = 1;
}
Fraction::Fraction(int inputNumer, int inputDenom) {
	numer = inputNumer;
	setDenom(inputDenom);
};
const int Fraction::getDenom() const {
	return denom;
}
const int Fraction::getNumer() const {
	return numer;
}
void Fraction::setDenom(int inputDenom) {
	if (inputDenom == 0) {
		cout << "error : input denom is 0, changed to 1";
		denom = 1;
	}
	else {
		denom = inputDenom;
	}
	int gcd = util.getGcd(numer, denom);
	numer /= gcd;
	denom /= gcd;
};
void Fraction::setNumer(int inputNumer) {
	numer = inputNumer;
	setDenom(denom);
};
const Fraction Fraction::operator +(const Fraction& a) const {
	int inputNumer = (numer * a.denom) + (a.numer * denom);
	int inputDenom = denom * a.denom;
	return Fraction(inputNumer, inputDenom);
};
ostream& operator <<(ostream& outputStream, const Fraction& fraction) {
	if (fraction.getNumer() * fraction.getDenom() < 0) {
		return outputStream << "-" << abs(fraction.getNumer()) << "/" << abs(fraction.getDenom());
	}
	else {
		return outputStream << abs(fraction.getNumer()) << "/" << abs(fraction.getDenom());
	}
}